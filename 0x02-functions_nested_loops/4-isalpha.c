#include "main.h"

/**
* _isalpha - tests whether a character is from the English alphabet.
* @c: character to be checked.
* Return: 1 if the character is an English character.
* 0 if the character is not an English character.
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'z'))
		return (1);
	else
		return (0);
}
