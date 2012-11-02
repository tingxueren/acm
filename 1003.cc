/*
 * =====================================================================================
 *
 *       Filename:  1003.cc
 *
 *    Description:  acm 1003
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
 *         Name:  max_sum_seq
 *  Description:  
 * =====================================================================================
 */
	void
max_sum_seq (vector<long int>::iterator start, vector<long int>::iterator end)
{
	vector<long int>::iterator iter1, iter2, iter3;
	vector<long int> result, tmp;
	long int pos, neg, sum, star_num, end_num;
	long int tmp[10000];
	for (iter1 = start; iter1 != end; ++iter1) {
		int i = 0;
		for (iter2 = iter1 + 1; iter2 != end; ++iter2) {
			tmp[0] = *iter1;
			tmp[i+1] = tmp[i] + *iter2;
			i++;
		}
		tmp[i] = '\n';
		for (iter3 = tmp.begin(); iter3 != tmp.end(); ++iter3) {
			end_num = 0;
			sum = *tmp.begin();
			if (*iter3 > sum) {
				sum = *iter3;
				end_num = iter3 - tmp.begin(); 

			}
		}
		star_num = iter1 - star;
		result.push_back(sum);
		result.push_back(star_num);
		result.push_back(end_num);




	}

	return <+return_value+>;
}		/* -----  end of function max_sum_seq  ----- */


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

	k

	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 

