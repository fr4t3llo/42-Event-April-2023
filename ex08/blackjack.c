#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
    int i = 0;
		int result = 0;
		char *line = "23456789TJDKA";

		while (av[1][i])
		{
			if (strchr(line, av[1][i]) == NULL){
				printf("Error arg\n");
        exit(1);
      }
			if (av[1][i] == 'A'){
				if ((result + 11) > 21)
					result += 1;
				else
					result += 11;
			}
			else if (strchr("TJDK", av[1][i]) != NULL)
				result += 10;
			else
				result += av[1][i] - '0';
			i++;
		}
		if (result == 21)
			printf("BlackJack!\n");
		else
			printf("%d\n", result);
	}
	return 0;
}
