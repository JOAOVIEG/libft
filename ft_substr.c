/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:24:28 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/19 11:13:03 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		subs = (char *)malloc(1);
	else
	{
		if (len > slen)
			len = slen - start;
		subs = (char *)malloc(sizeof(char) * len + 1);
		if (!subs)
			return (NULL);
		while (i < (int)(len))
		{
			*(subs + i) = *(char *)(s + start + i);
			i++;
		}
	}
	return (subs);
}

/*int main()
{
    char    *s = "Hello World. Good Morning";
    unsigned int    start = 13;
    printf("Should Be Good: %s\n", ft_substr(s, start, 4));
    return (0);
}*/