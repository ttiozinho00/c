#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define RESPONSE_SIZE 40
#define FREQUENCY_SIZE 11

int main(int argc, char const *argv[])
{
	system("cls");
	setlocale(LC_ALL,"");

	argc=argc;
	argv=argv;

	int frequency[FREQUENCY_SIZE] = {0};
	int responses[RESPONSE_SIZE] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10,1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6,5, 6, 7, 5, 6, 4, 8, 6, 8, 10};
	int answer;
	int rating;

	for (answer = 0; answer <= RESPONSE_SIZE; answer++)
	{
		++frequency[responses[answer]];
	}

	printf("%s%17s\n","Avalia��o","Frequ�ncia");

	for (rating = 1; rating <= FREQUENCY_SIZE; rating++)
	{
		printf("%6d%17d\n", rating,frequency[rating]);
	}
	
	return 0;
}