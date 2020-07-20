#include <stdio.h>
#include <stdlib.h>
void rotate(int matrix[10][10])
{
    int mat[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mat[i][j] = matrix[i][j];
        }
    }
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            matrix[a][b] = mat[9 - b][a];
        }
    }
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: rotateMatrix inputfilename.txt\n");
        return EXIT_FAILURE;
    }
    FILE *inf = fopen(argv[1], "r");
    FILE *outf = fopen("rotatedMatrix.out", "w");
    if (inf == NULL)
    {
        perror("Could not open input file\n");
        return EXIT_FAILURE;
    }
    if (outf == NULL)
    {
        perror("Could not open/create output file\n");
        return EXIT_FAILURE;
    }
    int numOfLines = 0;
    int numOfChars = 0;
    int c;
    int arr[10][10];
    while ((c = fgetc(inf)) != EOF && numOfLines <= 10 && numOfChars <= 10)
    {
        if (c == '\n' && numOfChars == 10)
        {
            numOfChars = 0;
            numOfLines++;
        }
        else if (c == '\n' && numOfChars != 10)
        {
            fprintf(stderr, "Incorrect matrix dimensions\n");
            return EXIT_FAILURE;
        }
        else if (c != '\n')
        {
            numOfChars++;
            arr[numOfLines][numOfChars - 1] = c;
        }
    }
    if (numOfLines != 10)
    {
        fprintf(stderr, "Incorrect matrix dimensions");
        return EXIT_FAILURE;
    }

    rotate(arr);
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    if (fclose(inf) != 0)
    {
        perror("Could not close input file\n");
        return EXIT_FAILURE;
    }
    if (fclose(outf) != 0)
    {
        perror("Could not close output file\n");
        return EXIT_FAILURE;
    }
}