/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:48:00 by krochefo          #+#    #+#             */
/*   Updated: 2022/07/27 06:09:49 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *array, char a)
{
	int	temp;

	if (!(array[0] == '\0' || array[1] == '\0'))
	{
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
	}
	if (a == 'a')
		write(1, "sa\n", 3);
	else if (a == 'c')
		write(1, "s", 1);
	else
		write(1, "sb\n", 3);
}

void	ft_push(int *array1, int *array2, char a)
{
	int	temp;
	int	i;
	int	j;

	temp = array1[0];
	i = 0;
	if (array1[0] != 0)
	{
		while (array1[i])
		{
			array1[i] = array1[i + 1];
			i++;
		}
		j = ft_array_len(array2);
		while (array2[j] != array2[j - 1])
		{
			array2[j] = array2[j - 1];
			j--;
		}
		array2[0] = temp;
		if (a == 'b')
			write(1, "pb\n", 3);
		else
			write(1, "pa\n", 3);
	}
}

void	ft_rotate(int *array, char a)
{
	int	temp;
	int	i;

	i = 0;
	temp = array[0];
	while (array[i + 1])
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = temp;
	if (a == 'a')
		write(1, "ra\n", 3);
	else if (a == 'c')
		write(1, "r\n", 2);
	else
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate(int *array, char a)
{
	int	temp;
	int	i;

	i = 0;
	while (array[i + 1])
		i++;
	temp = array[i];
	while (array[i])
	{
		array[i] = array[i - 1];
		i--;
	}
	array[0] = temp;
	if (a == 'a')
		write(1, "rra\n", 4);
	else if (a == 'c')
		write(1, "rr\n", 3);
	else
		write(1, "rrb\n", 4);
}
