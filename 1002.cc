/*
 * =====================================================================================
 *
 *       Filename:  1002.cc
 *
 *    Description:  acm 1002
 *
 *        Version:  1.0
 *        Created:  10/12/2012 10:52:53 AM
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
	int all_order_num;
	long int num;
	vector<long int> nums;
	while (cin >> num)
		nums.push_back(num);
	vector<long int>::iterator iter;
	all_order_num = *nums.begin();
	for (int i = 1; i <= all_order_num; ++i) {
		iter = nums.begin() + 1 + 2 * (i - 1);
		cout << "Case " << i << ":" << endl;
		cout << *iter << " + " << *(iter + 1) << " = " << *iter + *(iter + 1) << endl;
		if (i < all_order_num)
			cout << endl;

	}

	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 

