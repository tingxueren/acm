/*
 * =====================================================================================
 *
 *       Filename:  1001.cc
 *
 *    Description:  acm 1001
 *
 *        Version:  1.0
 *        Created:  10/12/2012 10:31:35 AM
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
#include <vector>

using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
int main(int argc, char *argv[])
{
	int num, sum = 0;
	vector<int> limit;
	while (cin >> num)
		limit.push_back(num);
	for (vector<int>::iterator iter = limit.begin(); iter != limit.end(); ++iter) {
		for (int i = 1; i <= *iter; ++i){
			sum += i;
		}
		cout << sum << endl << endl;
		sum = 0;
	}

	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 
