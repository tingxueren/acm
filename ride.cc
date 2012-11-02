/*
ID:zhangdo3
PROG:ride
LANG:C++
*/
  
/*
 * =====================================================================================
 *
 *       Filename:  ride.cc
 *
 *    Description:  acm ride
 *
 *        Version:  1.0
 *        Created:  10/31/2012 09:02:59 PM
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
#include <string>
#include <iostream>

using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
int main(int argc, char *argv[])
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string group;
	string comet;
	string::iterator iter1, iter2;

	while (getline(fin, group) && getline(fin, comet)) {
		int a = 1;
		int b =	1;
		//getline(fin, group);
		//cout << group << endl;
		//getline(fin, comet);
		//cout << comet << endl;
		for (iter1 = group.begin(); iter1 != group.end(); ++iter1) {
			a *= (*iter1 - 'A' + 1);
		}

		for (iter2 = comet.begin(); iter2 != comet.end(); ++iter2) {
			b *= (*iter2 - 'A' + 1);
		}
		//cout << a << endl << b << endl;
		if ((a % 47) == (b % 47)) {
			fout << "GO" << endl;
		}
		else {
			fout << "STAY" << endl;
		}
	}
	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 
