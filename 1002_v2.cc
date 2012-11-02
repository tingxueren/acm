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
#include <algorithm>  
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  long_int_add
 *  Description:  
 * =====================================================================================
 */
	string
long_int_add (string a, string b)
{
	string str1 = a;
	string str2 = b;
	int nlen1, nlen2, nlen;
	nlen1 = str1.length();
	nlen2 = str2.length();
	nlen = nlen1 > nlen2 ? nlen1 : nlen2;

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	if (nlen > nlen1) str1.append(nlen - nlen1, '0');
	if (nlen > nlen2) str2.append(nlen - nlen2, '0');

	int tmp = 0;
	int i = 0;
	string result;

	while (i < nlen) {
		if (str1[i] - 0x30 + str2[i] + tmp > '9') {
			result.append(1, str1[i] + str2[i] - '9' - 1 + tmp);
			tmp = 1;
		}
		else {
			result.append(1, str1[i] + str2[i] - '0' + tmp);
			tmp = 0;

		}
		++i;

	}
	if (tmp == 1)
		result.append(1, '1');
	reverse(result.begin(), result.end());
	return result;
}		/* -----  end of function long_int_add  ----- */



// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
int main(int argc, char *argv[])
{
	int all_order_num;
	string  num;
	vector<string> nums;
	cin >> all_order_num;
	while (cin >> num)
		nums.push_back(num);
	vector<string>::iterator iter;
	//all_order_num = *nums.begin();
	//sscanf(*nums.begin(), "%d", &all_order_num);
	for (int i = 1; i <= all_order_num; ++i) {
		iter = nums.begin() + 2 * (i - 1);
		cout << "Case " << i << ":" << endl;
		cout << *iter << " + " << *(iter + 1) << " = " << long_int_add(*iter, *(iter + 1)) << endl;
		if (i < all_order_num)
			cout << endl;

	}

	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 

