#include <stdio.h>
#include <stdlib.h>

/**
 * Builds a Magic Square using the Siamese method.
 *
 *  n The order of the magic square (must be odd and positive).
 *  mSquare A 2D array of dimensions n x n to be filled.
 */
void magic_square(int n, int mSquare[][n])
{
    /// to rule out zero, negative and even inputs
    if ((n < 1) || (n % 2 == 0))
        return;

    /** Insert your code here */
    int t = 1; // the value that is placed at the places in the sqaure matrix
    int i = 0; // for first row here and for row indexing
    int j = ((n + 1) / 2) - 1; // the middle column and column index
    int prev_value1, prev_value2; // for the move when there exist a value in the place

    for (;;) // we do not need proper condition as it is covered below
    {
        if (i == n - 1 && j == ((n + 1) / 2) - 1) // if i and j reaches the last row and middle column
        {
            mSquare[i][j] = t; // last value is written in the place
            break;             // and so the loop is ended
        }
        else if ((mSquare[i][j]) != 0) // if there exist a value at the place
        {
            i = prev_value1 + 1; // the previous value are assigned back and also we move one down in that previous place
            j = prev_value2;     // the previous value are assigned back
            mSquare[i][j] = t;   // at the one down place the value is placed
            t++;                 // value
            i -= 1;              // same one move up
            j += 1;              // one move right
        }
        else // if there is zero at place means value is to be places there
        {
            mSquare[i][j] = t;   // value is placed at the place
            t++;                 // incrementing the value after it is placed.
            prev_value1 = i;     // i and j are assigned to previous values if there occurs the condition of value present beforehand.
            prev_value2 = j;     // then these values helps get back to this position to make the move of one down
            i -= 1;              // one move up
            j += 1;              // one move right
        }
        if (i < 0) // if i gets out of the possible appropriate index of matrix then it setback accordingly
        {
            i = n - 1; // if by move one up we moves out of array, then it is resetted back to last row
        }
        else if (i >= n)
        {
            i = 0; // if by move one down we moves out of array, then it is resetted back to first row
        }
        if (j < 0) // if j gets out of the possible appropriate index of matrix then it setback accordingly
        {
            j = n - 1;
        }
        else if (j >= n)
        {
            j = 0;
        }
    }

    return;
}

/**
 * Helper function to print a magic square.
 */
void print_magic_square(int n, int mSquare[][n])
{
    printf("\nMagic Square of order %d:\n", n);
    printf("-------------------------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", mSquare[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------\n");
}


int main(int argc, char *argv[])
{
    int n;

    printf("=== Magic Square Generator (Siamese Method) ===\n");
    printf("Enter the order of the magic square (odd positive integer): ");
    fflush(stdout);  // Ensure prompt is displayed before reading input
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input! Please enter an integer.\n");
        return 1;
    }

    if (n < 1)
    {
        printf("Error: Order must be a positive integer.\n");
        return 1;
    }

    if (n % 2 == 0)
    {
        printf("Error: Order must be an odd integer (Siamese method works only for odd orders).\n");
        return 1;
    }

    // Declare a 2D array of size n x n
    int mSquare[n][n];

    // Initialize all elements to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mSquare[i][j] = 0;
        }
    }

    // Generate the magic square
    magic_square(n, mSquare);

    // Print the result
    print_magic_square(n, mSquare);

    // Verify the magic constant
    int magic_constant = n * (n * n + 1) / 2;
    printf("\nExpected Magic Constant: %d\n", magic_constant);

    // Verify rows
    printf("\nRow sums: ");
    for (int i = 0; i < n; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < n; j++)
        {
            row_sum += mSquare[i][j];
        }
        printf("%d ", row_sum);
    }

    // Verify columns
    printf("\nColumn sums: ");
    for (int j = 0; j < n; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < n; i++)
        {
            col_sum += mSquare[i][j];
        }
        printf("%d ", col_sum);
    }

    // Verify main diagonal
    printf("\nMain diagonal sum: ");
    int diag_sum = 0;
    for (int i = 0; i < n; i++)
    {
        diag_sum += mSquare[i][i];
    }
    printf("%d ", diag_sum);

    // Verify anti-diagonal
    printf("\nAnti-diagonal sum: ");
    int anti_diag_sum = 0;
    for (int i = 0; i < n; i++)
    {
        anti_diag_sum += mSquare[i][n - 1 - i];
    }
    printf("%d ", anti_diag_sum);

    printf("\n\nMagic square generated successfully!\n");

    return 0;
}