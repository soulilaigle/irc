/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <llaigle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:24:31 by llaigle           #+#    #+#             */
/*   Updated: 2024/05/16 17:10:47 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <poll.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

class Server
{
private:
    int server_fd;
    std::vector<int> client_fds;
    struct sockaddr_in cli_adr;
    struct sockaddr_in serv_adr;

public:

    Server();
    ~Server();
    void start(int port);
    void acceptNewConnection();
    void handleClientMessage(int client_socket);
    void run();
};