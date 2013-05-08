/*
 * =====================================================================================
 *
 *       Filename:  1005.cc
 *
 *    Description:  acm 1005
 *
 *        Version:  1.0
 *        Created:  12/19/2012 07:47:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Dongsheng (mars), zhangdongsheng1224@gmail.com
 *   Organization:  HANGZHOU DIANZI UNIVERSITY
 *
 * =====================================================================================
 */


int get_num(int A, int B, int N)
{
	if (N == 1 || N == 2)
		return 1;
	else
		return ((A*get_num(A,B,N-1)) + (B*get_num(A,B,N-2))) % 7;

}

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
int main(int argc, char *argv[])
{
	int A, B, N;
	while (cin >> A >> B >> N){
		if (A == 0 && B == 0 && N == 0)
			return 0;
		else
			cout << get_num(A,B,N) << endl;
	
	}

	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 
