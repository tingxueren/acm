/*
 * =====================================================================================
 *
 *       Filename:  1004.cc
 *
 *    Description:  acm 1004
 *
 *        Version:  1.0
 *        Created:  12/19/2012 05:30:45 PM
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
#include <string>
#include <map>

using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
int main(int argc, char *argv[])
{
	int num;
	string balloon;

	while (cin >> num && num != 0) {
		map<string, int> balloon_count;
		for (int i = 0; i != num; ++i) {
			cin >> balloon;
			++balloon_count[balloon];
		
		}
		
		map<string, int>::iterator map_it = balloon_count.begin();
		map<string, int>::iterator max = balloon_count.begin();
		for (; map_it != balloon_count.end(); ++map_it) {
			if (map_it->second > max->second)
				max = map_it;
		
		}

		cout << max->first << endl;

		
	}



	return EXIT_SUCCESS;
}				// ----------  end of function main  ---------- 
