/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    if (!n) return NULL; 
    
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) matrix[i] = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) memset(matrix[i], 0, sizeof(int) * n);
    
    int row = 0, col = -1, num = 1;
    while (num <= n * n)
    {
        while (col + 1 < n && !matrix[row][col+1]) matrix[row][++col] = num++;
        while (row + 1 < n && !matrix[row+1][col]) matrix[++row][col] = num++;
        while (col > 0 && !matrix[row][col-1]) matrix[row][--col] = num++;
        while (row > 0 && !matrix[row-1][col]) matrix[--row][col] = num++;
    }
    
    return matrix;
}