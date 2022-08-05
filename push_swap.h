/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:34:39 by krochefo          #+#    #+#             */
/*   Updated: 2022/08/05 13:40:09 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_array_len(int *array);
int			ft_find_position(int *array, int nb);
int			ft_hold_number(int *array_a, int chunk, int nb_arg, int nb);
int			ft_hold_number_b(int *array_b, int nb_arg);
int			ft_b_to_a(int *array_a, int *array_b, int hold_first);
int			ft_checker(int *array_a, int nb_arg, int chunk);
int			ft_funnel_median(int *array_a, int nb_arg, int chunk);
int			ft_chunk_nb(int nb_arg);

long int	ft_atoli(const char *str);

void		ft_error(void);
void		ft_swap(int *array, char a);
void		ft_rotate(int *array, char a);
void		ft_reverse_rotate(int *array, char a);
void		ft_error_isdigit(char **argv);
void		ft_error_min_max(char **argv);
void		ft_error_doubles(char **argv);
void		ft_push(int *array1, int *array2, char a);
void		ft_sort_array(int *array_a, int *array_b, int nb);
void		ft_sort_3_array(int *array_a);
void		ft_sort_5_array(int *array_a, int *array_b);
void		ft_sort_100_array(int *array_a, int *array_b, int nb_arg);
void		ft_push_rotate(int *array_a, int *array_b);
void		ft_error_isordered(char **argv, int argc);
void		ft_a_to_b(int *array_a, int *array_b, int nb_arg, int hold_first);

#endif
