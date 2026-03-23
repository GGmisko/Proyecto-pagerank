#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/*FN****************************************************************************
*
* int initiate_zeros_vct( int rows,double vct[rows])
*
* Return: Returns 1 to success 
*
* Purpose: It fills a empty vector  with zeros
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int initiate_zeros_vct( int rows,double vct[rows])
{
  for(int i=0;i<rows;i++)
    {
      vct[i]=0;
    }
  return 1;
}
/*FN****************************************************************************
*
* int initiate_ones_vct(int rows, double vct[rows])
*
* Return: Returns 1 to success 
*
* Purpose: It fills a empty vector with ones
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int initiate_ones_vct(int rows, double vct[rows])
{
  for(int i=0;i<rows;i++)
    {
      vct[i]=1;
    }
  return 1;
}
/*FN****************************************************************************
*
* int print_vct(int columns, double vct[columns])
*
* Return: Returns 1 to success 
*
* Purpose: It prints a vector 
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int print_vct(int columns, double vct[columns])
{
  for(int j=0;j<columns;j++)
    {
      printf("%f",vct[j]);
      printf(" ");
    }
  return 1;
}
/*FN****************************************************************************
*
* int vct_vct_product(int rows, int columns,double vctA[columns],double vctB[columns],double result[]
*
* Return: Returns 1 to success 
*
* Purpose: It multiplies two vectors of same size, and stores the result in a third vector
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int vct_vct_product(int rows, int columns,double vctA[columns],double vctB[columns],double result[][columns])
{
  for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
        {
          result[i][j]=result[i][j]+vctA[i]*vctB[j];
        }
    }
    return 1;
}
/*FN****************************************************************************
*
* int copy_vct(int columns, double vctA[columns],double vctB[columns])
*
* Return: Returns 1 to success 
*
* Purpose: It copies a vector into another vector
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int copy_vct(int columns, double vctA[columns],double vctB[columns])
{
  for(int i=0;i<columns;i++)
    {
      vctB[i]=vctA[i];
    }
  return 1;
}
/*FN****************************************************************************
*
* double euclidean_distance(int columns,double vctA[columns],double vctB[columns])
*
* Return: Returns the euclidean distance between two vectors
*
* Purpose: It calculates the euclidean distance between two vectors
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
double euclidean_distance(int columns,double vctA[columns],double vctB[columns])
{
  double temp=0;
  for(int i=0;i<columns;i++)
    {
      temp=pow(vctA[i]-vctB[i],2)+temp;
    }
  temp=sqrt(temp);
  return temp;
}
/*FN****************************************************************************
*
* int initiate_probability_vct(int columns,double vct[columns])
*
* Return: Returns 1 to success
*
* Purpose: It fills a vector with a probability of 1/columns
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int initiate_probability_vct(int columns,double vct[columns])
{
  double column=columns;
  for(int i=0;i<column;i++)
    {
      vct[i]=1/column;
    }
  return 1;
}
/*FN****************************************************************************
*
* int initiate_vct_123(int columns, int vct[columns]) {
*
* Return: Returns 1 to success
*
* Purpose: It fills a vector with a sequency 1+
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int initiate_vct_123(int columns, int vct[columns]) {
  for (int i = 0; i < columns; i++) {
    vct[i] = i + 1;
  }
  return 1;
}