#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args              ok [x]
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into               ok[x]
    char buffer[7];

    // Create array to store plate numbers      Ok [x]
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");         // Ensure file was successfully opened
    if (infile == NULL)                         // Print error if invalid and return error to main
    {
        printf("File not found\n");
        return 1;
    }

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        plates[idx] = malloc(7 * sizeof(char)); // To resolve the buffer problem, allocated heap memory for each plate
        strcpy(plates[idx], buffer);            // Copy plate contents to allocated memory
        idx++;
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);              // Printing plates
        free(plates[i]);                        // Using the loop to free memory for each plate
    }
    fclose(infile);                             // Close input file
}
