/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <llaigle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:01:26 by llaigle           #+#    #+#             */
/*   Updated: 2024/05/16 17:02:58 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Clients.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    Server server;
    server.start(atoi(argv[1]));
    server.run();

    return 0;
}
