
#include <stdio.h>
int main()
{
	int age = 25;
	char grade = 'A';
	float score = 98.5;
	
	printf("%lu\n",(unsigned long)sizeof(age));
	printf("%lu\n",(unsigned long)sizeof(grade));
	printf("%lu\n",(unsigned long)sizeof(score));
	
	printf("%p\n",&age);
	printf("%p\n",&grade);
	printf("%p\n",&score);
	
	return 0;
 } 
