#include <iostream>
#include<string>


using namespace std;

class insan
{
	
	public:
		
	string name;
	
	void printname()
	{
		cout<<name;
	}
};

int main() 
{
	insan ben;
	ben.name="Yaren";
	ben.printname();
	
	return 0;
}
