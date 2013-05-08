/*
ID:zhangdo3
PROG:milk2
LANG:C
*/

/*
 * =====================================================================================
 *
 *       Filename:  milk2.c
 *
 *    Description:  milk2
 *
 *        Version:  1.0
 *        Created:  05/08/2013 04:26:34 PM
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

#define MAXN 1000000

int milk[2][MAXN];

int max(int a, int b)
{
	if (a >= b)
		return a;
	else 
		return b;
}	

int main()
{
	int i, j, num, tmp0, tmp1, tmp2;
	int invertal1, invertal2;
	FILE *fin, *fout;
	fin = fopen("milk2.in", "r");
	fout = fopen("milk2.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d", &num);
	//printf("num = %d\n", num);

	for (i = 0; i < num; ++i)
		fscanf(fin, "%d %d", &(milk[0][i]), &(milk[1][i]));

	//for (i = 0; i < num; ++i)
		// 输出注意顺序
	//	printf("milk[0][%d] = %d, mikl[1][%d] = %d \n", i, milk[0][i], i, milk[1][i]);
	
	for (i = 1; i < num; ++i) {
		tmp0 = milk[0][i];
		tmp1 = milk[1][i];
		j = i - 1;

		while (j >= 0 && milk[0][j] > tmp0) {
			milk[0][j + 1] = milk[0][j];
			milk[1][j + 1] = milk[1][j];
			--j;
		}
		milk[0][j+1] = tmp0;
		milk[1][j+1] = tmp1;
	}

	//for (i = 0; i < num; ++i)
	//	printf("milk[0][%d] = %d, mikl[1][%d] = %d \n", i, milk[0][i], i, milk[1][i]);
	
	int start, end;
	start = milk[]
	for (i = 0; i < n; ++i) {
		
	}

	//printf("%d %d\n", invertal1, invertal2);
	fprintf(fout, "%d %d\n", invertal1, invertal2);
	return 0;
}	
