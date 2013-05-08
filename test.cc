/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  test
 *
 *        Version:  1.0
 *        Created:  12/19/2012 07:37:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Dongsheng (mars), zhangdongsheng1224@gmail.com
 *   Organization:  HANGZHOU DIANZI UNIVERSITY
 *
 * =====================================================================================
 */


#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string strvec[1000];
    while(cin>>n && n != 0)
    {
        for(int i = 0;i < n;++i)
            cin>>strvec[i];
        int num,max;
        string temp;
        max = 0;
        for(int i = 0;i < n;++i)
        {
            num = 1;
            for(int j = i + 1;j < n;++j)
                if(strvec[i] == strvec[j])
                    ++num;
            if(num > max)
            {
                max = num;
                temp = strvec[i];
            }
        }
        cout<<temp<<endl;
    }
    return 0;
}
