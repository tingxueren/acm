/*
 * =====================================================================================
 *
 *       Filename:  1005_v2.c
 *
 *    Description:  acm 1005 v2
 *
 *        Version:  1.0
 *        Created:  12/19/2012 08:42:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Dongsheng (mars), zhangdongsheng1224@gmail.com
 *   Organization:  HANGZHOU DIANZI UNIVERSITY
 *
 * =====================================================================================
 */


#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
int main(int argc, char *argv[])
{
	int f[56], a, b, i;
	int n;
	f[0] = 1;
	f[1] = 1;
	while(1) {
		scanf("%d%d%d",&a, &b, &n);
		if (!a && !b && !n)
			break;
		for (i = 2; i < 49; ++i) {
			f[i] = (a * f[i-1] + b * f[i-2]) % 7;
			printf("f[%d] = %d\n", i, f[i]);
		
		}	
		printf("%d\n", f[(n-1)%49]);
	
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
