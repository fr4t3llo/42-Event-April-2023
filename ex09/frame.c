#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1000

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
    int k = 0;
    if (ac == 2){
        splt = ft_split(av[1]," ");
        if (!splt[k])
            return (1);
        int len = 0;
        len = strlen(splt[k]);
        while (splt[k]){
            if (len < strlen(splt[k]))
                len = strlen(splt[k]);
            k++;
        }
        for (int i = 0; i < len + 4; i++)
            printf("*");
        printf("\n");
        int i = 0;
        int j = 0;
        while (splt[i])
        {
            int k = len;
            int nb = k - strlen(splt[i]);
            j = 0;
            printf("* ");
            while (splt[i][j])
            {
                printf("%c", splt[i][j]);
                j++;
            }
            while (nb >= 0)
            {
                printf(" ");
                nb--;
            }
            printf("*\n");
            i++;
        }
        for (int i = 0; i < len + 4; i++)
            printf("*");
        printf("\n");
    }
    return 0;
}

