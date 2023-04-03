#include "libc.h"


// int		printf(char c)
// {
//     write (1, &c, 1);
//     return (0);
// }

int		base(int size)
{
	int floor, width, floor_step;

	floor = 1;
	width = 1;
	floor_step = 4;
	while (floor <= size){
		width += 2 * (2 + floor);
		floor++;
		width += floor_step;
		if (floor % 2 && floor < size)
			floor_step += 2;
	}
	width -= floor_step;
	return width;
}

void	put_line(int space)
{
	int pos;
	pos = 0;
	while (pos < space){
		printf(" ");
		pos++;
	}
}

void	put_blocks(int size, int floor, int width, int step)
{
	int door;
    int pos = 0;

	door = 1 + 2 * ((floor - 1) / 2);
	while (pos < width){
		if (pos == 0)
			printf("/");
		else if (pos == width - 1)
			printf("\\");
		else{
			if (floor == size && pos >= (width - door) / 2
					&& pos < (width + door) / 2 && 2 + floor - step <= door)
				if (door >= 5 && step == 2 + floor - door / 2 - 1
						&& pos == (width + door) / 2 - 2)
					printf("$");
				else
					printf("|");
			else
				printf("*");
		}
		pos++;
	}
}

void	sastantua(int size)
{
	int	floor = 1;
	int	height;
	int	step;
	int	width = 1;

	if (size < 1)
		return ;
	while (floor <= size){
		height = 2 + floor;
		step = 0;
		while (step < height){
			width += 2;
			put_line((base(size) - width) / 2);
			put_blocks(size, floor, width, step);
			printf("\n");
			step++;
		}
		floor++;
		width += 4 + 2 * ((floor - 2) / 2);
	}
}

int	main(int ac, char **av){
	if (ac < 2)
		return 0;
	sastantua(atoi(av[1]));
    return 0;
}