#include<stdio.h>
#include <iostream>
using namespace std; 
int main();
void getAverageDistance()
{
	printf("call get\n");
	main();
}
int main(){
	printf("call main\n");
    getAverageDistance();
    return 1;
}