#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	
 int dizi1[6]={1,2,3,4,5,6};
 int dizi2[5]={7,8,9,10,12};
 
 int eleman1 =(sizeof(dizi1)/sizeof(dizi1[0]));
 int eleman2 =(sizeof(dizi2)/sizeof(dizi2[0]));
 
 int tempdizi[eleman1+eleman2];
 
 
 for( int i=0;i<eleman1;i++)
 {
   tempdizi[i]=dizi1[i];
 }
 
 
 for(int i=0;i<eleman2;i++)
 {
	tempdizi[eleman1+i]=dizi2[i];
 }


for(int i=0;i<eleman1+eleman2;i++)
{
	cout<<tempdizi[i]<<endl;
}


return 0;


}
