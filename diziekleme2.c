#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	
    int dizi1[3][3];
    int dizi2[3][3];   

    for(int i=0;i<3;i++)
	{
	   	
	for(int j=0;j<3;j++)
	   	
	    {
		   	dizi1[i][j]=1;
		   	//printf("%d",dizi1[i][j]);
	    }
		   
		   
	    //printf("\n");
	}         

   // printf("***\n");
    
    for(int i=0;i<3;i++)
	{
	   	
	for(int j=0;j<3;j++)
	   	
		{
		   	dizi2[i][j]=1;
		   	//printf("%d",dizi1[i][j]);
		}
		   
		   
	   
	    //printf("\n");
	} 
	
	
	int eleman1 =(sizeof(dizi1)/sizeof(dizi1[0]));
    int eleman2 =(sizeof(dizi2)/sizeof(dizi2[0]));
 
    //cout<<eleman1<<endl;
    
    int tempdizi[3][6];
 
 
    for( int i=0;i<eleman1;i++)
    {
    	for(int j=0;j<eleman1;j++)
    	{
    		 tempdizi[i][j]=dizi1[i][j];
		}
       
    }
 
 
    for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
        {
	    tempdizi[i][j+3]=dizi2[i][j];
        }
        
	    
    }


    for(int i=0;i<3;i++)
    {   for(int j=0;j<6;j++)
        {
    	  cout<<tempdizi[i][j]<<endl;
	    }
	    printf("\n");
      	
    }        



return 0;
}
