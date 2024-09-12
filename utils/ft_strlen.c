/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:43:41 by aeid              #+#    #+#             */
/*   Updated: 2024/02/05 17:45:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solong.h"

//#include <stdio.h>//
//#include <string.h>//

int	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

/*int main()
{
    //int i = ft_strlen ("hello");//
    int i = strlen("Hello");
    printf("the length of the array is %i", i);
    return (0);
}*/
