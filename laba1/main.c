#include <stdio.h>
#include <>

int solve(int mas_b[100][2], int mas_w[100][2], int m, int n);

void create_win(int mas_b[100][2], int mas_w[100][2], int m, int n)
{

}

void input(int m, int n)
{
    int mas_black[100][2];
    int mas_white[100][2];
    int i;

    i = 0;
    if (m > 100 || n > 100)
        return;
    while (i < m)
    {
        printf("Input %d black point: ", i + 1);
        scanf("%d%d", &mas_black[i][0], &mas_black[i][1]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        printf("Input %d white point: ", i + 1);
        scanf("%d%d", &mas_white[i][0], &mas_white[i][1]);
        i++;
    }
    if (solve(mas_black, mas_white, m, n))
    	printf("line is here!");
    else
    {
    	printf("not found line:(");
        return ;
    }
    create_win(mas_black, mas_white, m, n);
}

int search_d(const int *par1, const int *par2, const int *par3)
{
	int a;
	int b;

	a = (par3[0] - par1[0]) * (par2[1] - par1[1]);
	b = (par3[1] - par1[1]) * (par2[0] - par1[0]);
	return (a - b);
}

int on_one_side(const int *mas, int m)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i < m)
	{
		if (mas[i] <= 0)
			c++;
		i++;
	}
	if (c == m)
		return (-1);
	i = 0;
	c = 0;
	while (i < m)
	{
		if (mas[i] >= 0)
			c++;
		i++;
	}
	if (c == m)
		return (1);
	return (0);
}

int one_color(const int *par1, const int *par2, int mas_w[100][2], int n, int side1)
{
	int i;
	int mas[n];
	int side2;

	i = 0;
	while (i < n)
	{
		mas[i] = search_d(par1, par2, mas_w[i]);
		i++;
	}
	side2 = on_one_side(mas, n);
	if (side2 != 0 && side2 != side1)
		return (1);
	return (0);
}

int solve(int mas_b[100][2], int mas_w[100][2], int m, int n)
{
	int mas[m];
	int i;
	int j;
	int z;
	int side;

	i = 0;
	while (i < m - 1)
	{
		j = i + 1;
		while (j < m)
		{
			z = 0;
			while (z < m)
			{
				mas[z] = search_d(mas_b[i], mas_b[j], mas_b[z]);
				z++;
			}
			side = on_one_side(mas, m);
			if (side == 1 || side == -1)
			{
				if (one_color(mas_b[i], mas_b[j], mas_w, n, side))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int main() {
    int m;
    int n;

    printf("Number of black point: \n");
    scanf("%d", &m);
    printf("Number of white point: \n");
    scanf("%d", &n);
    if (m < 2 || n < 2)
        return 0;
    input(m, n);
    return 0;
}