/* 
ID:zhangdo3
PROG:transform
LANG:C
*/

/*
 * =====================================================================================
 *
 *       Filename:  transform.c
 *
 *    Description:  transform
 *
 *        Version:  1.0
 *        Created:  05/09/2013 06:34:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Dongsheng (mars), zhangdongsheng1224@gmail.com
 *   Organization:  HANGZHOU DIANZI UNIVERSITY
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 10

typedef struct Board Board;
struct Board {
	int n;
	char b[MAXN][MAXN];
};

int num;

int is_equal(Board a, Board b)
{	
	if (a.n != b.n)
		return 0;
	int flag = 1;
	int i, j;
	for (i = 0; i < a.n; ++i) {
		for (j = 0; j < a.n; ++j) {
			if (a.b[i][j] != b.b[i][j])
				flag = 0;
		}
	}
	return flag;	
}

void print_matrix(Board a)
{
	int i, j;
	for (i = 0; i < a.n; ++i) {
		for (j = 0; j < a.n; ++j)
			printf("%c ", a.b[i][j]);
		printf("\n");	
	}
}	

// 右旋90度
Board rotate(Board b)
{
	int i, j;
	Board nb;
	nb.n = b.n;
	for (i = 0; i < b.n; ++i)
		for (j = 0; j < b.n; ++j)
			nb.b[j][b.n - 1 - i] = b.b[i][j];
	return nb;
}	

// 对称
Board reflect(Board b)
{
	int i, j;
	Board nb;
	nb.n = b.n;
	for (i = 0; i < b.n; ++i)
		for (j = 0; j < b.n; ++j)
			nb.b[i][b.n - 1 - j] = b.b[i][j];
	return nb;
}	

int main()
{
	FILE *fin, *fout;
	int i, j, change;
	Board in, out;

	fin = fopen("transform.in", "r");
	fout = fopen("transform.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d", &num);
	//printf("num = %d\n", num);

	in.n = num;
	out.n = num;

	//fscanf(fin, "%d", &i);
	getc(fin);

	for (i = 0; i < num; ++i) {
		for (j = 0; j < num; ++j) {
			in.b[i][j] = getc(fin);
			//fscanf(fin, "%c", &(Matrix_in[i][j]));
		}
		getc(fin);
	}	


	for (i = 0; i < num; ++i) {
		for (j = 0; j < num; ++j) {
			out.b[i][j] = getc(fin);
			//fscanf(fin, "%c", &(Matrix_in[i][j]));
		}
		getc(fin);
	}

	//print_matrix(in);
	//printf("\n");
	//print_matrix(rotate(in));
	//printf("\n");
	//print_matrix(rotate(rotate(in)));
	//printf("\n");
	//print_matrix(rotate(rotate(rotate(in))));
	//printf("\n");
	//print_matrix(reflect(in));
	//printf("\n");
	//print_matrix(combin(in));
	
	if (is_equal(out, rotate(in)))
		change = 1;
	else if(is_equal(out, rotate(rotate(in))))
		change = 2;
	else if(is_equal(out, rotate(rotate(rotate(in)))))
		change = 3;
	else if(is_equal(out, reflect(in)))
		change = 4;
	else if(is_equal(out, rotate(reflect(in))) || is_equal(out, rotate(rotate(reflect(in)))) || is_equal(out, rotate(rotate(rotate(reflect(in))))))
		change = 5;
	else if(is_equal(out, in))
		change = 6;
	else
		change = 7;
	
	//printf("change = %d\n", change);	
	fprintf(fout, "%d\n", change);
	
	return 0;
}	
