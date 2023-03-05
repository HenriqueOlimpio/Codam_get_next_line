/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: henolimp <henolimp@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 15:18:47 by henolimp      #+#    #+#                 */
/*   Updated: 2023/01/30 15:20:28 by henolimp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*aux_of_strjoin(char *new_string, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_string[i + j] = s2[j];
		j++;
	}
	new_string[i + j] = '\0';
	return (new_string);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static	void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*val;
	int				i;

	i = 0;
	val = (unsigned char *)b;
	while (len > 0)
	{
		val[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, '\0', (count * size));
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL)
		return (s2);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	str = aux_of_strjoin (str, s1, s2);
	free(s1);
	free(s2);
	return (str);
}
