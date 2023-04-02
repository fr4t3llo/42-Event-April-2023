#include <stdio.h>

int main(int ac, char **av)
{
    int i = 1;
    int j = 0;
    int result = 0;
    if (ac == 2){

        while(av[i][j]){
            if (av[i][j] >= '2' && av[i][j] <= '9')
            {

                result += 4;
            }
            else if (av[i][j] == 'J' || av[i][j] == 'K' || av[i][j] == 'Q')
            {
                result += 10;
            }
            else if (av[i][j] == 'A'){
                if (result >= 21)
                    result += 11;
                else 
                    result += 1;
            }
            j++;
        }
        printf("%d\n", result);
    }
    else
        return 1;
    return (0);
}