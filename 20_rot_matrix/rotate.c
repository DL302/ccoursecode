void rotate(char matrix[10][10])
{
    char mat[10][10];
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