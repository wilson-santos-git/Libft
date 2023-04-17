/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:36:59 by wteles-d          #+#    #+#             */
/*   Updated: 2023/04/17 18:36:43 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	h;
	int	count;

	h = 0;
	count = 0;
	while (s && s[h] != '\0')
	{
		if (s[h] != c && (s[h - 1] == c || h == 0))
			count++;
		h++;
	}
	return (count);
}

static int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

static void	ft_free_all(char **p)
{
	while (p && *p)
		free(*p++);
	free (p);
}

static int	ft_alloc_word(char **p, char const *s, int i, char c)
{
	*p = (char *)ft_calloc(size_word(s, c, i) + 1, sizeof(char));
	if (p == NULL)
		return (0);
	ft_strlcpy(*p, s + i, (size_t)size_word(s, c, i));
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**p;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	p = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (p == NULL)
		return (p);
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			if (!(ft_alloc_word(&p[j], s, i, c)))
			{
				ft_free_all(p);
				return (NULL);
			}
			i += size_word(s, c, i);
			j++;
		}
	}
	return (p);
}

// int	main(void)
// {
// 	char	**str = ft_split("aisdhynaid sadsd asd   as das das a ", ' ');
// 	int		x = 0;
// 	while	(str[x])
// 	{		
// 		printf("%s\n", str[x]);
// 		x++;
// 	}
// }
