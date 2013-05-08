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
	int i, j, num, tmp1, tmp2, tmp3;
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
		tmp1 = milk[0][i];
		tmp2 = milk[1][i];
		j = i - 1;

		while (j >= 0 && milk[0][j] > tmp1) {
			milk[0][j + 1] = milk[0][j];
			milk[1][j + 1] = milk[1][j];
			--j;
		}
		milk[0][j+1] = tmp1;
		milk[1][j+1] = tmp2;
	}

	//for (i = 0; i < num; ++i)
	//	printf("milk[0][%d] = %d, mikl[1][%d] = %d \n", i, milk[0][i], i, milk[1][i]);
	
	invertal1 = milk[0][1] - milk[0][0];
	invertal2 = 0;
	tmp1 = invertal1;
	tmp2 = invertal2;

	for (i = 1; i < num; ++i) {
		// 与上一事件连续
		// 连续的时候更新不对，考虑事件
		// 1-20, 3-5, 7-9, 8-25
		if (milk[0][i] <= milk[1][i-1])
			tmp1 += (milk[1][i] - milk[1][i-1]);
		// 与上一事件不连续
		else {
			tmp1 = milk[1][i] - milk[0][i];
			tmp3 = milk[1][i-1];
			for (j = 0; j < i; ++j) {
				if (milk[1][j] > tmp3)
					tmp3 = milk[1][j];
			
			}
			if (tmp3 < milk[0][i])
				tmp2 = milk[0][i] - tmp3;
		
		}
		invertal1 = max(invertal1, tmp1);
		invertal2 = max(invertal2, tmp2);
	}

	
		

	//printf("%d %d\n", invertal1, invertal2);
	fprintf(fout, "%d %d\n", invertal1, invertal2);
	return 0;
}	
