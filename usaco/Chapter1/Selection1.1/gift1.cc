/*
ID:zhangdo3
PROG:gift1
LANG:C++
*/

/*
 * =====================================================================================
 *
 *       Filename:  gift1.cc
 *
 *    Description:  gift1.cc
 *
 *        Version:  1.0
 *        Created:  11/02/2012 10:59:44 AM
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
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_order
 *  Description:  
 * =====================================================================================
 */
	int 
get_order(vector<string>::iterator iter01, vector<string>::iterator iter02, int num)
{
	int order = 0;
	for (int i = 0; i < num; ++i) {
		// break should in if 
		if (*iter01 == *(iter02 + i)){ 
			order = i;
			break;
		
		}
	}
	return order;
}		/* -----  end of function get_order  ----- */

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
int main(int argc, char *argv[])
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	vector<string> input;
	string elem;
	int user_num;
	fin >> user_num;
	//cout << user_num;
	//for (int i = 0; i < user_num; ++i) {
	//	getline(fin, elem);
	//	input.push_back(elem);
	//
	//}
	//cout << input << endl;
	while ( fin >> elem)
		input.push_back(elem);
	vector<string>::iterator iter1 = input.begin();
	vector<string>::iterator iter2 = input.begin() + user_num;
	vector<string>::iterator iter3;
//	cout << *iter1 << endl;
//	cout << *(iter1 + 6) << endl << *(iter1 + 7) << endl;
//	cout << "get_order = " << get_order(iter1 + 4, iter1, user_num) << endl;;
	int a[10][10] = {};
	int b[10] = {};
	for (iter3 = iter2; iter3 != input.end(); ) {
		//cout << "*iter3 = " << *iter3 << endl;
		int p = get_order(iter3, iter1, user_num);
		//cout << "p = " << p << endl;
		string str1, str2;
		str1 = *(iter3 + 1);
		const char *c1 = str1.c_str();
		str2 = *(iter3 + 2);
		const char *c2 = str2.c_str();
		int m = atoi(c1);
		int n = atoi(c2);
		//cout << "m = " << m << endl << "n = " << n << endl;
		//int m = atoi(*(iter3 + 1).c_str());
		//int n = atoi((iter3 + 2));
		int g;
		if (n != 0)
			 g = (m - m % n) / n;
		else 
			 g = 0;
		a[p][p] = m;
		//cout << "a[p][p] = " << a[p][p] << endl;
		for (int j = 1; j <= n; ++j) {
			a[p][get_order((iter3 + 2 + j), iter1, user_num)] = -g;
			
		}
		//cout << "g = " << g << endl;
		iter3 = iter3 + 3 + n;

	}

	for (int i = 0; i < user_num; ++i) {
		int account = 0;
		for (int j = 0; j < user_num; ++j)
			account += a[i][j];
		for (int k = 0; k < user_num; ++k)
			account -= a[k][i];
		b[i] = account;
	}	
	for (int i = 0; i < user_num; ++i) {
		fout << *(iter1 + i) << " " << b[i] << endl;
	}

	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 

