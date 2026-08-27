/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:54:33 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 12:48:02 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

/* push_swap */

/* gnl.c */
char	*get_next_line(int fd);

/* gnl_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* checker_utils.c */
int		parse_arguments(int argc, char **argv, t_ctx *ctx);

/* checker.c */
int		main(int argc, char **argv);

/* operations */
void	push_stack(t_stack *src, t_stack *dst);
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

#endif
