#include <math.h>// when using the math header make sure to include flag -lm!!!!!!!!!
#include <stdio.h>

typedef struct cords
{
	double	x;
	double	y;
}	t_cords;


int main()
{
	t_cords	vector;// from enmy to plyr
	t_cords	ply_pos;
	t_cords	enmy_pos;
	double	length;

	ply_pos.x = 0;
	ply_pos.y = -1;
	enmy_pos.x = 1;
	enmy_pos.y = 1;
	vector.x = ply_pos.x - enmy_pos.x;
	vector.y = ply_pos.y - enmy_pos.y;
	printf("v.x => %f, v.y => %f\n", vector.x, vector.y);
	length = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	printf("length(distance between enmy and plyr) => %f\n", length);
}