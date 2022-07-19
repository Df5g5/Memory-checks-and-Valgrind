#include <iostream>

int main()
{
	int i=13;
	int * p1= &i;
	(*p1)=2;
	int *p2 = p1;

	std::cout<<p1<<std::endl;
	std::cout<<*p1<<std::endl;
	delete p1;
	//std::cout<<"p1 after delete: "<<p1<<std::endl;
	//std::cout<<*p1<<std::endl;
	//std::cout<<"p2: "<<p2<<std::endl;
	//delete p2;
}
