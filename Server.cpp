/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <llaigle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:23:59 by llaigle           #+#    #+#             */
/*   Updated: 2024/05/16 17:10:54 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server() : server_fd(-1) {}

Server::~Server()
{
    if (server_fd != -1)
        close(server_fd);
    for (size_t i = 0; i < client_fds.size(); ++i)
        close(client_fds[i]);
}

void Server::start(int port)
{
    std::cout << "Starting the server on port " << port << "..." << std::endl;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        std::cerr << "Socket failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = INADDR_ANY;
    serv_adr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) < 0)
    {
        std::cerr << "Bind failed" << std::endl;
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        std::cerr << "Listen failed" << std::endl;
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    std::cout << "The server started with success !" << std::endl;
}

void Server::acceptNewConnection()
{
    socklen_t addrlen = sizeof(cli_adr);
    int new_socket = accept(server_fd, (struct sockaddr *)&cli_adr, &addrlen);
    if (new_socket < 0)
    {
        std::cerr << "Accept failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    client_fds.push_back(new_socket);
    std::cout << "New connection accepted" << std::endl;
}


void Server::handleClientMessage(int client_socket)
{
    char buffer[BUFFER_SIZE];
    ssize_t valread = read(client_socket, buffer, BUFFER_SIZE);
    if (valread == 0)
    {
        close(client_socket);
        std::cout << "Client disconnected" << std::endl;
        return;
    }
    buffer[valread] = '\0';
    std::cout << "Received message: " << buffer << std::endl;

    // Echo message back to client
    send(client_socket, buffer, valread, 0);
}

void Server::run()
{
    if (server_fd == -1)
    {
        std::cerr << "Server not initialized" << std::endl;
        return;
    }

    std::vector<struct pollfd> pollfds;
    struct pollfd server_pollfd;

    server_pollfd.fd = server_fd;
    server_pollfd.events = POLLIN;
    pollfds.push_back(server_pollfd);

    while (true)
    {
        int poll_count = poll(pollfds.data(), pollfds.size(), -1);
        if (poll_count < 0)
        {
            std::cerr << "Poll error" << std::endl;
            exit(EXIT_FAILURE);
        }
        for (size_t i = 0; i < pollfds.size(); ++i)
        {
            if (pollfds[i].revents & POLLIN)
            {
                if (pollfds[i].fd == server_fd)
                {
                    acceptNewConnection();
                    struct pollfd client_pollfd;
                    client_pollfd.fd = client_fds.back();
                    client_pollfd.events = POLLIN;
                    pollfds.push_back(client_pollfd);
                }
                else
                    handleClientMessage(pollfds[i].fd);
            }
        }
    }
}