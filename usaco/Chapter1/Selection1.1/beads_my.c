/*
ID:zhangdo3
PROG:beads
LANG:C
*/

/*
 * =====================================================================================
 *
 *       Filename:  beads_my.c
 *
 *    Description:  beads_my
 *
 *        Version:  1.0
 *        Created:  05/08/2013 12:49:49 PM
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
#include <string.h>
#include <assert.h>

#define MAXN 400

char necklace[MAXN];
int len;

int mod(int m, int n)
{
	while(m < 0)
		m += n;
	return m % n;
}	

int nbreak(int p, int dir)
{
	int i, n;
	char color = 'w';

	if (dir > 0)
		i = p;
	else
		i = mod(p - 1, len);

	for (n = 0; n < len; ++n, i = mod(i + dir, len)) {
		if (necklace[i] != 'w' && color == 'w')
			color = necklace[i];

		if (color != 'w' && necklace[i] != color && necklace[i] != 'w')
			break;	
	}

	return n;
}	

int main()
{
	FILE *fin, *fout;
	int max, i, j;

	fin = fopen("beads.in", "r");
	fout = fopen("beads.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d%s", &len, necklace);
	assert(strlen(necklace) == len);

	max = 0;
	for (i = 0; i < len; ++i) {
		j = nbreak(i, 1) + nbreak(i, -1);
		if (j > max)
			max = j;		
	}
	
	if (max > len)
		max = len;

	fprintf(fout, "%d\n", max);
	//printf("%d\n", max);
	return 0;

}	
