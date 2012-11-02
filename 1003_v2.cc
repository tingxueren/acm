/*
 * =====================================================================================
 *
 *       Filename:  1003_v2.cc
 *
 *    Description:  acm 1003
 *
 *        Version:  1.0
 *        Created:  10/13/2012 05:01:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Dongsheng (mars), zhangdongsheng1224@gmail.com
 *   Organization:  HANGZHOU DIANZI UNIVERSITY
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	int j, i, n, t;
	int a[100002];
	scanf("%d", &t);
	for (j = 1; j <= t; j++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int sum = 0, maxsum = -1001, first = 0, last = 0, temp = 1;
		for (i = 0; i < n; i++) {
			sum += a[i];
			if (sum > maxsum) {
				maxsum = sum;
				first = temp;
				last = i + 1;
			}
			if (sum < 0) {
				sum = 0;
				temp = i + 2;
			}
		}

		printf("Case %d:\n%d %d %d\n", j, maxsum, first, last);
		if (j != t) {
			printf("\n");
		}
	}

	return 0;
}
