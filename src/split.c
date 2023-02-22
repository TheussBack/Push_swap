/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:18:06 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/22 12:22:48 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	is_charset(char c, char *charset);
int	wordcount(char *str, char *charset);
char	*get_word(char *str, char *charset, int index);

int	is_charset(char c, char *charset)
{
	int	n;

	n = 0;
	while (charset[n])
	{
		if (c == charset[n])
			return (1);
		n++;
	}
	return (0);
}

int	wordcount(char *str, char *charset)
{
	int	trigger;
	int	count;
	int	n;

	trigger = 1;
	n = 0;
	count = 0;
	while (str[n])
	{
		if (!is_charset(str[n], charset))
		{
			if (trigger)
				count++;
			trigger = 0;
		}
		else
			trigger = 1;
		n++;
	}
	return (count + 1);
}

char	*get_word(char *str, char *charset, int index)
{
	char	*result;
	int		i;

	i = index;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	i -= index;
	result = (char *) malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[index] && !is_charset(str[index], charset))
	{
		result[i] = str[index];
		i++;
		index++;
	}
	result[i] = '\0';
	return (result);
}

char	**split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;

	result = (char **) malloc(sizeof(char *) * (wordcount(str, charset) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			result[j] = get_word(str, charset, i);
			j++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (result);
}
