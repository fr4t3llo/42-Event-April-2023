#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 9

#define MAX_TOKENS 100

// int	ft_is_separator(char c, char cr)
// {
// 	if (c == cr)
// 		return (1);
// 	if (c == '\0')
// 		return (1);
// 	return (0);
// }

// int	ft_words(char *str, char c)
// {
// 	int	i;
// 	int	w;

// 	i = 0;
// 	w = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (ft_is_separator(str[i], c) == 0
// 			&& ft_is_separator(str[i + 1], c) == 1)
// 			w++;
// 		i++;
// 	}
// 	return (w);
// }

// void	ft_write_word(char *dest, char *src, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (ft_is_separator(src[i], c) == 0)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// }

// int	ft_write_split(char **split, char *str, char c)
// {
// 	int	i;
// 	int	j;
// 	int	w;

// 	i = 0;
// 	w = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (ft_is_separator(str[i], c) == 1)
// 			i++;
// 		else
// 		{
// 			j = 0;
// 			while (ft_is_separator(str[i + j], c) == 0)
// 				j++;
// 			split[w] = (char *)malloc(sizeof(char) * (j + 1));
// 			if (!(split + w))
// 				return (0);
// 			ft_write_word(split[w], str + i, c);
// 			i += j;
// 			w++;
// 		}
// 	}
// 	return (1);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		w;
// 	char	**rtn;

// 	if (!s)
// 		return (NULL);
// 	w = ft_words((char *)s, c);
// 	rtn = (char **)malloc(sizeof(char *) * (w + 1));
// 	if (!rtn)
// 		return (NULL);
// 	if (!(ft_write_split(rtn, (char *) s, c)))
// 	{
// 		w = -1;
// 		while (rtn + ++w)
// 			free(rtn + w);
// 		free(rtn);
// 	}
// 	rtn[w] = 0;
// 	return (rtn);
// }


char** ft_split(char* str, char* delim) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    int num_tokens = 0;
    char* token = strtok(str, delim);
    while (token != NULL) {
        tokens[num_tokens++] = token;
        if (num_tokens == MAX_TOKENS) {
            break;
        }
        token = strtok(NULL, delim);
    }
    tokens[num_tokens] = NULL;
    return tokens;
}


int main(int ac, char **av)
{
    int i = 1;
    char **splt;
    if (ac == 2){
        splt = ft_split(av[1]," ");
        for (int i = 0; i < LEN; i++)
            printf("*");
        printf("\n");
        while (splt[i]){
            printf("* %s *\n", splt[i]);
            i++;
        }
        for (int i = 0; i < LEN; i++)
            printf("*");
        printf("\n");
    }
    return 0;
}

