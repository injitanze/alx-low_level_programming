#include <stdio.h>
/**
* main - prints the lowercase alphabet in reverse.
*
*
* Return: Always 0.
*/
int main(void)
{
	char alphabet;

	for (alphabet = 'Z'; alphabet >= 'a'; alphabet--)
		putchar(alphabet);


	putchar('\n');

	return (0);
}
