#include <stdio.h>
#include <stdbool.h>
/*FN****************************************************************************
*
* int extract_value(int columns, double mat[][columns],int row, int column)
*
* Return: Returns a value ([i][j]) from a matrix
*
* Purpose: It extracts a value from a matrix
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int extract_value(int columns, double mat[][columns],int row, int column)
{
  return mat[row][column];
}
/*FN****************************************************************************
*
* long double transpose_mtx(int rows, int columns, double mtx[][columns])
*
* Return: Returns 1 to success
*
* Purpose: It transposes a matrix
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
long double transpose_mtx(int rows, int columns, double mtx[][columns])
{
  long double temp=0;
  for(int i=0;i<rows;i++)
  {
    for(int j=i;j<columns;j++)
      {
        temp=mtx[i][j];
        mtx[i][j]=mtx[j][i];
        mtx[j][i]=temp;
      }
  }
  return 1;
}
/*FN****************************************************************************
*
*int add_matrix(int rows, int columns,double mtxA[][columns],double mtxB[][columns],double result[]
*
* Return: Returns 1 to success
*
* Purpose: It adds two matrices
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int add_matrix(int rows, int columns,double mtxA[][columns],double mtxB[][columns],double result[][columns])
{
  for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
        {
          result[i][j]=mtxA[i][j]+mtxB[i][j];
        }
    }
  return 1;
}
/*FN****************************************************************************
*
*int initiate_zeros_mtx(int rows, int columns,double mtx[][columns])
*
* Return: Returns 1 to success
*
* Purpose: It fills a matrix with zeros 
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int initiate_zeros_mtx(int rows, int columns,double mtx[][columns])
{
  for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
        {
          mtx[i][j]=0;
        }
    }
  return 1;
}
/*FN****************************************************************************
*
*int print_mtx(int rows, int columns,double mtx[][columns])
*
* Return: Returns 1 to success
*
* Purpose: It prints a matrix
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int print_mtx(int rows, int columns,double mtx[][columns])
{
  for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
        {
          printf("%f",mtx[i][j]);
          printf(" ");
        }
      printf("\n");
    }
  return 1;
}
/*FN****************************************************************************
*
*int mtx_vct_product(int rows, int columns,double mtx[][columns],double vct[columns],double result[columns])
*
* Return: Returns 1 to success
*
* Purpose: It multiplies a matrix by a vector
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int mtx_vct_product(int rows, int columns,double mtx[][columns],double vct[columns],double result[columns])
{
  double temp=0;
  for(int i=0;i<rows;i++)
    {
      temp=0;
      for(int j=0;j<columns;j++)
        {
          temp=mtx[i][j]*vct[j]+temp;
        }
      result[i]=temp;
    }
    return 1;
}
/*FN****************************************************************************
*
*int number_matrix_product(int rows, int columns,double mtx[][columns],double number,double result[][columns])
*
* Return: Returns 1 to success
*
* Purpose: It multiplies a matrix by a number
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int number_matrix_product(int rows, int columns,double mtx[][columns],double number,double result[][columns])
{
  for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
        {
          result[i][j]=mtx[i][j]*number;
        }
    }
  return 1;
}
/*FN****************************************************************************
*
*bool have_zeros(int rows,int columns,double mtx[][columns])
*
* Return: Returns TRUE if the matrix has zeros and FALSE if it doesn't.
*
* Purpose: It checks if a matrix has zeros
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
bool have_zeros(int rows,int columns,double mtx[][columns])
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<columns;j++)
      {
        if(mtx[i][j]==0)
        {
          return true;
        }  
      }
  }
  return false; 
}
/*FN****************************************************************************
*
*bool is_stochastic_rows(int rows, int columns, double mtx[][columns])
*
* Return: Returns TRUE if the matrix is stochastic and FALSE if it isn't.
*
* Purpose: It checks if a matrix has zeros
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
bool is_stochastic_rows(int rows, int columns, double mtx[][columns])
{
  double temp=0;
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<columns;j++)
      {
        temp=temp+mtx[i][j];//add all the values of a row
      }
    if((temp - 1) > 0.05 ||(temp - 1) > 0.05)//If the sum is different of 1 the code can't run
      /*If a number is irrational or long double and the file not contains the complete number the sum will not be exactly 1. Therefore this function will accept a difference of 0.05*/
    { 
      return false;
    }
    temp=0;
  }
  return true;
}
