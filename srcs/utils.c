/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:10:13 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/08 22:52:47 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len--)
		*ptr++ = uc;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	i;

	if (count == 0 || size == 0 || size > ((size_t)(-1)) / count)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	i = 0;
	ft_memset(ret, 0, count * size);
	return (ret);
}

bool	ft_atoi(char *s, int *dest)
{
	int	number;

	if (*s == '\0')
		return (false);
	number = 0;
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (false);
		number = 10 * number + *s++ - '0';
	}
	*dest = number;
	return (true);
}
