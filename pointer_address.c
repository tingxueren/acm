/*
 * =====================================================================================
 *
 *       Filename:  pointer_address.c
 *
 *    Description:  指针的疑惑
 *
 *        Version:  1.0
 *        Created:  11/04/2012 03:02:07 PM
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
	char buf[10] = {"abcdefg"};
	int *p, *q;
	p = (int *)buf;
	printf("buf = %p; &buf[0] = %p; buf[0] = %c; &p = %p; p = %p; *(char *)p = %c\n", buf, &buf[0], buf[0], &p, p, *(char *)p); 
	q = p;
	p++;
	printf("&q = %p; &p = %p; q = %p; p = %p;\n", &q, &p, q, p);
	printf("(char *)p - &buf[0] = %ld\n", (char *)p - &buf[0]);
	printf("\nProgram %s\n\n", argv[0]);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
