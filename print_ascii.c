#include "main.h"

/**
 * print_ascii_art - prints ascii art from a file
 * @filename: the file to read from
 */

void print_ascii_art(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return;
	}

	char line[1024];
	while (fgets(line, sizeof(line), file))
	{
		printf("%s", line);
	}

	fclose(file);
}
