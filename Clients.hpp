/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clients.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <llaigle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:50:02 by llaigle           #+#    #+#             */
/*   Updated: 2024/05/16 15:50:58 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <cstring>
# include <poll.h>

class Clients
{
private:
	int	_Socket;
	std::string _Nickname;
	std::string _Username;
public:
	Clients(void);
	~Clients(void);
	int	get_Socket(void);
	void	set_Socket(int new_Socket);
	std::string get_Nickname(void);
	void	set_Nickname(int new_Nickname);
	std::string get_Username(void);
	void	set_Username(std::string new_Username);
};