/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clients.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <llaigle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:49:54 by llaigle           #+#    #+#             */
/*   Updated: 2024/05/16 15:50:55 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Clients.hpp"

Clients::Clients(void)
{

}

Clients::~Clients(void)
{

}

int	Clients::get_Socket(void)
{
	return(this->_Socket);
}

void	Clients::set_Socket(int new_Socket)
{
	this->_Socket = new_Socket;
	return ;
}

std::string Clients::get_Nickname(void)
{
	return(this->_Nickname);
}

void	Clients::set_Nickname(int new_Nickname)
{
	this->_Nickname = new_Nickname;
	return ;
}

std::string	Clients::get_Username(void)
{
	return (this->_Username);
}

void	Clients::set_Username(std::string new_Username)
{
	this->_Username = new_Username;
	return ;
}