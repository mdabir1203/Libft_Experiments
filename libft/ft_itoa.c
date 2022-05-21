/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.wolfsburg42.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:04:00 by mabbas            #+#    #+#             */
/*   Updated: 2022/05/21 23:13:21 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 * @brief : Changing your integer to a char string
 * @return : Return the string containing the integer
 * 			 else NULL Check
 * @approach: Check for integer higher than 9 . Computer can't print it.
 * 			  smart way to handle int min and int max:
 * 			  Take absolute value of them.
 * 			  I used --size which is prefix decrement. the value size is decrem
 * 			  first and then starts decrememting again.
 *
 */
#include "libft.h"

static int	ft_absval(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_count_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		++size;
	while (n != 0)
	{
		++size;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*outstring;
	int		size;

	size = ft_count_size (n);
	outstring = malloc(sizeof(char) * (size + 1));
	if (n < 0)
		outstring[0] = '-';
	outstring[size] = '\0';
	if (n == 0)
	{
		*outstring = '0';
		*(outstring + 1) = '\0';
	}
	while (n != 0)
	{
		--size;
		outstring[size] = ft_absval(n % 10) + '0';
		n /= 10;
	}
	return (outstring);
}

/* #include<stdio.h>

int	main(void)
{
	printf("%s\n",ft_itoa(1234567890));
	return(0);
} */