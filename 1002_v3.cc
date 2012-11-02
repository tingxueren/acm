/*
 * =====================================================================================
 *
 *       Filename:  1002_v3.cc
 *
 *    Description:  acm 1002
 *
 *        Version:  1.0
 *        Created:  10/12/2012 01:30:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Dongsheng (mars), zhangdongsheng1224@gmail.com
 *   Organization:  HANGZHOU DIANZI UNIVERSITY
 *
 * =====================================================================================
 */

#include <iostream>  
#include <algorithm>  
#include <string>  
using namespace std;  
  
int main()  
{  
   string str1;  
   string str2;  
   while(cin>>str1>>str2)  
   {  
       int nLen1, nLen2, nLen;  
       nLen1 = str1.length();  
       nLen2 = str2.length();  
       nLen = nLen1 > nLen2 ? nLen1 : nLen2;  
         
       reverse(str1.begin(), str1.end());  
       reverse(str2.begin(), str2.end());  
         
       //高位补零  
       if (nLen > nLen1) str1.append(nLen - nLen1, '0');   
       if (nLen > nLen2) str2.append(nLen - nLen2, '0');  
         
       int temp = 0;   //进位数目  
       int i = 0;  
       string strResult;    //存储结果  
         
       while (i < nLen)  
       {  
           if(str1[i] -0x30 + str2[i] + temp > '9')  
           {  
               strResult.append(1, str1[i] + str2[i] - '9' - 1 + temp);  
               temp = 1;  
           }  
           else  
           {  
               strResult.append(1, str1[i] + str2[i] - '0' + temp);  
               temp = 0;  
           }  
           i++;  
       }  
         
       if(temp == 1)  
          strResult.append(1, '1');  
       reverse(strResult.begin(), strResult.end());  
       cout<<strResult<<endl;  
   }  
   return 0;  
}  
