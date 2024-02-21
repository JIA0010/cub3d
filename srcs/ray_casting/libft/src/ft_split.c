/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:47:05 by yoshimurahi       #+#    #+#             */
/*   Updated: 2023/09/20 15:59:07 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	get_word_count(char const *s, char c)
{
	int	count;
	int	in_substr;

	count = 0;
	in_substr = 0;
	while (*s)
	{
		if (*s == c)
			in_substr = 0;
		else if (in_substr == 0)
		{
			in_substr = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*make_word(char const *s, size_t len)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static int	split_words(char **words, int wc, const char *s, char c)
{
	int	i;
	int	len;
	int	j;

	j = 0;
	i = 0;
	while (i < wc)
	{
		while (s[j] == c)
			j++;
		len = 0;
		while (s[j + len] && s[j + len] != c)
			len++;
		words[i] = make_word(s + j, len);
		if (!words[i])
		{
			while (i >= 0)
				free(words[i--]);
			return (-1);
		}
		j += len;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**words;
	int		k;

	if (s == NULL)
		return (NULL);
	wc = get_word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!words)
		return (NULL);
	k = split_words(words, wc, s, c);
	if (k == -1)
	{
		free(words);
		return (NULL);
	}
	words[k] = NULL;
	return (words);
}

// int	main(void)
// {
// 	char	*str;
// 	char	c;
// 	char	**ans;

// 	c = '\0';
// 	str = "\0";
// 	ans = ft_split(str, c);
// 	printf("0: %s\n", *ans);
// 	// printf("1: %s\n", ans[1]);
// 	// printf("2: %s\n", ans[2]);
// 	// printf("3: %s\n", ans[3]);
// 	// printf("4: %s\n", ans[4]);
// 	for (int i = 0; ans[i]; i++)
// 		free(ans[i]);
// 	free(ans);
// }