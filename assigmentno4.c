#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

    int row = 4;
    int col = 4; 
    
bool check_symatric(int a[row][col]){
    int count;
    int mul=row*col;
    int tranpose[row][col];
    bool check;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            tranpose[j][i] = a[i][j];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (tranpose[i][j] == a[i][j]){
                count++;  
                }
        }
    }
    if (count == mul){
        check=true;
        return check; 
        }
    else{
        check=false;
        return check;
        }
}

int main()
{

    int diagonal_1_save[row];
    int third_matrix[row][col];
    int matrix_1[row][col];
    int matrix_2[row][col];
    int sub=row-1;
    srand(time(NULL));

    // random value generate in matrix 1 and matrix 2;
    // value generate between 0 to 50
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix_1[i][j] = rand() % 50;
            matrix_2[i][j] = rand() % 50;
        }
    }

    // store diagonals of 1 matrix in another arry;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                diagonal_1_save[i] = matrix_1[i][j];
            }
        }
    }

    printf("\n\n");

    // replacing the diagonal of 2 matrix with the diagonal  of 1 matrix that store in (diagonal_1_save arry);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j) // when row and coloum is same diagonal condiition is satisfaied then replacing process occur;
            {
                matrix_2[i][j] = diagonal_1_save[i];
            }
        }
    }

    // print the matrixs after diagonal replacing;

    printf("print matrix 1 after replace\n\n ");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", matrix_1[i][j]);
        printf("\n");
    }

    printf("print matrix 2 after replace\n\n ");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", matrix_2[i][j]);
        printf("\n");
    }

    printf("****_________________________________________________________________________________________***\n");

    // nebouring value calculation;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            // (i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 & j == 2)

            if (i>0 && j>0 && i<sub&& j<sub)
            // this condition for only those values which have 8 nebour value exist;
            {

                third_matrix[i][j] = (matrix_2[i - 1][j] + matrix_2[i + 1][j] + matrix_2[i][j - 1] + matrix_2[i][j + 1] + matrix_2[i - 1][j - 1] + matrix_2[i + 1][j - 1] + matrix_2[i - 1][j + 1] + matrix_2[i + 1][j + 1]) / matrix_2[i][j];
            }
                //    (i == 0 && j == 1) || (i == 0 && j == 2)
            else if (i==0 && j>0 && j<sub)
            // this condition for uper two value which have 8 nebour values but we need overlaping;
            {
                third_matrix[i][j] = (matrix_2[i + 1][j - 1] + matrix_2[i + 1][j] + matrix_2[i][j - 1] + matrix_2[i][j + 1] + matrix_2[i + 1][j + 1] + matrix_2[-i + sub][j] + matrix_2[-i + sub][j + 1] + matrix_2[-i + sub][j - 1]) / matrix_2[i][j];
            }
            // (i == 3 && j == 1) || (i == 3 && j == 2)
            else if (i==sub && j>0 && j<sub)
            // this condition for lower two value which have 8 nebour values but we need overlaping;
            {
                third_matrix[i][j] = (matrix_2[i - 1][j] + matrix_2[i - 1][j + 1] + matrix_2[i][j - 1] + matrix_2[i][j + 1] + matrix_2[i - 1][j - 1] + matrix_2[-i + sub][j] + matrix_2[-i + sub][j + 1] + matrix_2[-i + sub][j - 1]) / matrix_2[i][j];
            }
            //   (i == 1 && j == 0) || (i == 2 && j == 0)
            else if (j==0 && i>0 && i<sub)
            // this condition for left side  two value which have 8 nebour values but we need overlaping;
            {
                third_matrix[i][j] = (matrix_2[i][j + 1] + matrix_2[i + 1][j] + matrix_2[i + 1][j + 1] + matrix_2[i - 1][j] + matrix_2[i - 1][j + 1] + matrix_2[i][-j + sub] + matrix_2[i + 1][-j + sub] + matrix_2[i - 1][-j + sub]) / matrix_2[i][j];
            }
            // (i == 1 && j == 3) || (i == 2 && j == 3)
            else if (j==sub && i>0 && i<sub)
            // this condition for right side two value which have 8 nebour values but we need overlaping;
            {
                third_matrix[i][j] = (matrix_2[i][j - 1] + matrix_2[i + 1][j] + matrix_2[i + 1][j - 1] + matrix_2[i - 1][j] + matrix_2[i - 1][j - 1] + matrix_2[i][-j + sub] + matrix_2[i + 1][-j + sub] + matrix_2[i - 1][-j + sub]) / matrix_2[i][j];
            }
            else if ((i == 0 && j == 0))
            // this condition for  uper left value which have 7 nebour values but we need overlaping;

            {
                third_matrix[i][j] = (matrix_2[i][j + 1] + matrix_2[i + 1][j] + matrix_2[i + 1][j + 1] + matrix_2[i + sub][j] + matrix_2[i + sub][j + 1] + matrix_2[i][j + sub] + matrix_2[i + 1][j + sub]) / matrix_2[i][j];
            }
            else if ((i == 0 && j == sub))
            // this condition for  uper right value which have 7 nebour values but we need overlaping;

            {
                third_matrix[i][j] = (matrix_2[i][j - 1] + matrix_2[i + 1][j] + matrix_2[i + 1][j - 1] + matrix_2[i][j - sub] + matrix_2[i + 1][j - sub] + matrix_2[i + sub][j] + matrix_2[i + sub][j - 1]) / matrix_2[i][j];
            }
            else if (i == sub && j == 0)
            // this condition for  lower left value which have 7 nebour values but we need overlaping;

            {
                third_matrix[i][j] = (matrix_2[i][j + 1] + matrix_2[i - 1][j] + matrix_2[i - 1][j + 1] + matrix_2[i - sub][j] + matrix_2[i - sub][j + 1] + matrix_2[i][j + sub] + matrix_2[i - 1][j + sub]) / matrix_2[i][j];
            }
            else if (i == sub && j == sub)
            // this condition for  lower right value which have 7 nebour values but we need overlaping;

            {
                third_matrix[i][j] = (matrix_2[i][j - 1] + matrix_2[i - 1][j] + matrix_2[i - 1][j - 1] + matrix_2[i - sub][j] + matrix_2[i - sub][j - 1] + matrix_2[i][j - sub] + matrix_2[i - 1][j - sub]) / matrix_2[i][j];
            }
        }
    }

    // print output means third matric containing submision of all nebouring values

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", third_matrix[i][j]);
        printf("\n");
    }
    // function call in which aryy row and col pass and return type is bool which store in result;
    int result = check_symatric(third_matrix);
    //  just print result;
    printf(" [%d]",result);
    if (result == 0)
        printf(" matrix is not symatric");
    else if (result == 1)
        printf(" matrix is symatric");
    // THE END    /\/\ @@ --/__
}
