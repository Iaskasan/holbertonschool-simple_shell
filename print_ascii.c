#include "main.h"

void print_ascii_art(const char *filename)
{
	FILE *file = fopen(filename, "r"); // Ouvre le fichier en mode lecture
	if (file == NULL) {
		perror("Erreur lors de l'ouverture du fichier");
		return;
	}

	char line[1024]; // Buffer pour stocker chaque ligne du fichier
	while (fgets(line, sizeof(line), file)) {
		printf("%s", line); // Affiche chaque ligne
	}

	fclose(file); // Ferme le fichier après avoir fini de lire
}
