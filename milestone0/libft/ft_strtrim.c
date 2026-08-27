/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:37:31 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/03 20:11:00 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	if (!s1 || !set)
		return (NULL);
	left = 0;
	while (s1[left] && ft_strchr(set, s1[left]))
	{
		left++;
	}
	right = ft_strlen(s1);
	while (right > left && ft_strchr(set, s1[right - 1]))
	{
		right--;
	}
	return (ft_substr(s1, left, right - left));
}
/*						ft_strchr(s1, set);
	s1[] = ".hola." set[] = "."
		new_s = ".."

		".hola."
		new_s = ""

		strchr?
		s1 = NULL; return ""
		s1 = ""; return ""
		
		s1 = "Hola" set = "" return "Hola"
		s1 = "   Hola   mundo   " set = "Hola   mundo"


*/
