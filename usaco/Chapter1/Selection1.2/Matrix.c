/* 
ID:zhangdo3
PROG:transform
LANG:C
 */

/*
 * =====================================================================================
 *
 *       Filename:  Matrix.c
 *
 *    Description:  matrix.c
 *
 *        Version:  1.0
 *        Created:  05/09/2013 03:41:59 PM
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

//void print_matrix(char Matrix[m][n], int m, int n)
//{
//		int i, j;
//		for (i = 0; i < m; ++i) {
//			for (j = 0; j < n; ++j)
//				printf("%c\t", Matrix[i][j]);
//			printf("\n");
//		}
//}	


int main()
{
	FILE *fin, *fout;
	int i, j, num;
	char Matrix_in[MAXN][MAXN];

	fin = fopen("Matrix.in", "r");
	fout = fopen("Matrix.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d", &num);
	printf("num = %d\n", num);

	//fscanf(fin, "%d", &i);
	getc(fin);

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			Matrix_in[i][j] = getc(fin);
			//fscanf(fin, "%c", &(Matrix_in[i][j]));
			printf("%c ", Matrix_in[i][j]);	
		}
		getc(fin);
		printf("\n");
	}	
//	for (i = 0; i < 3; ++i) {
//		for (j = 0; j < 3; ++j) 
//			Matrix_in[i][j] = getc(fin);
//		//assert(getc(fin) == '\n');
//	}
//
//	//print_matrix(Matrix_in, num, num);
////	printf("%c", Matrix_in[0][0]);
//	for (i = 0; i < num; ++i) {
//		for (j = 0; j < num; ++j)
//			printf("%c ", Matrix_in[i][j]);
//		printf("\n");
//	}
//	//for (i = 0; i < num; ++i)
//	//	printf("%c ", Matrix_in[0][i]);
//
	return 0;
}	
