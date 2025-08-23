/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:04:58 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/23 13:56:28 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char *to_upper(char *arg)
{
	char	*result;

	result = arg;
	for (int i = 0; result[i] != '\0'; i++)
	{
		if (result[i] >= 'a' && result[i] <= 'z')
			result[i] = std::toupper(result[i]);
	}
	return (result);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << to_upper(argv[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}
