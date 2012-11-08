/*
ID:zhangdo3
PROG:friday
LANG:C++
*/

/*
 * =====================================================================================
 *
 *       Filename:  friday.cc
 *
 *    Description:  friday
 *
 *        Version:  1.0
 *        Created:  11/08/2012 10:54:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Dongsheng (mars), zhangdongsheng1224@gmail.com
 *   Organization:  HANGZHOU DIANZI UNIVERSITY
 *
 * =====================================================================================
 */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  is_leap
 *  Description:  
 * =====================================================================================
 */
bool is_leap (int year)
{
	bool index = 0;
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		index = 1;

	return index;
}		/* -----  end of function is_leap  ----- */


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
	int mon_num[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	int mon_leap[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
	int result[7] = {0};
	long int sum = 0;
	int years, year_day;
	int start = 1900;
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	fin >> years;

	for (int i = start; i < start + years; ++i) {
		if (!is_leap(i)) {
			year_day = 365;
			for (int j = 0; j < 12; ++j) {
				result[(sum + mon_num[j] + 13) % 7]++; 
			}
		} else {
			year_day = 366;
			for (int j = 0; j < 12; ++j) {
				result[(sum + mon_leap[j] + 13) % 7]++; 
			}
			
		
		}
		sum += year_day;
	
	}
	// 输出时必须严格按照要求输出，
	// 结尾必须是 endl;
	for (int i = 0; i < 6; ++i)
		fout << result[(i + 6) % 7] << " ";
	fout << result[5] << endl;
		//fout << result[i] << " ";
	//fout << endl;


//	if (is_leap(400))
//		cout << "400 is leap year." << endl;
//	if (!is_leap(399))
//		cout << "399 is normal year." << endl;
//	cout << "\nProgram " << argv[0] << endl << endl;
//

	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 
