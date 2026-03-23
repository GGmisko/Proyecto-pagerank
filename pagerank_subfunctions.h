#include "vector_handling.h"
#include "matrix_handling.h"
/*FN****************************************************************************
*
* int replace_absorbent_nodes(int rows, int columns,double mtx[rows][columns])
*
* Return: Returns 1 to success 
*
* Purpose: It replaces absorbent nodes with 1/columns 
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int replace_absorbent_nodes(int rows, int columns,double mtx[rows][columns]) {
  double temp = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      temp = temp + mtx[i][j];
    }
    if (temp == 0) {
      initiate_probability_vct(columns, mtx[i]);
    }
    temp = 0;
  }
  return 1;
}
/*FN****************************************************************************
*
* int sort_vct_ranking(int columns, double vct[columns], int positions[columns])
*
* Return: Returns 1 to success 
*
* Purpose: It sorts a vector by ranking
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int sort_vct_ranking(int columns, double vct[columns], int positions[columns]) {
  double temp = 0;
  double temp_pos = 0;
  for (int i = 0; i < columns; i++) {
    for (int j = i; j < columns; j++) {
      if (vct[i] < vct[j]) {
        temp = vct[i];
        temp_pos = positions[i];
        vct[i] = vct[j];
        positions[i] = positions[j];
        vct[j] = temp;
        positions[j] = temp_pos;
      }
    }
  }
  return 1;
}
/*FN****************************************************************************
*
* int replace_zeros(int rows, int columns, double mtx[rows][columns], double alpha)
*
* Return: Returns 1 to success 
*
* Purpose: It eliminates 0 of a matrix
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int replace_zeros(int rows, int columns, double mtx[rows][columns], double alpha) {
if (have_zeros(rows, columns, mtx)) {
  double auxrows=rows;
  double ones_vct[columns];
  double temp_mtx[rows][columns];
  initiate_zeros_mtx(rows, columns, temp_mtx);
  initiate_ones_vct(rows, ones_vct);
  vct_vct_product(rows, columns, ones_vct, ones_vct, temp_mtx);
  number_matrix_product(rows, columns, temp_mtx, 1 - alpha, temp_mtx);
  number_matrix_product(rows, columns, temp_mtx, 1 / auxrows, temp_mtx);
  number_matrix_product(rows, columns, mtx, alpha, mtx);
  add_matrix(rows, columns, mtx, temp_mtx, mtx);
}
return 1;
}
/*FN****************************************************************************
*
* int print_ranking(int columns,double vct[columns], int positions[columns])
*
* Return: Returns 1 to success 
*
* Purpose: It prints a good look table
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int print_ranking(int columns,double vct[columns], int positions[columns]) {
  int top[columns];
  initiate_vct_123(columns,top);
  printf("Top:      Node:     Result: \n");
  for (int j = 0; j < columns; j++) {
    printf("%d", top[j]);
    printf("          %d", positions[j]);
    printf("       %f", vct[j]);
    printf("\n");
  }
  return 1;
}
/*FN****************************************************************************
*
* int power_method(int rows, int columns,double matrix[][columns],float convergence_factor, double ranking[columns])
*
* Return: Returns number of iterations
*
* Purpose: It applies the power method to a matrix
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int power_method(int rows, int columns,double matrix[][columns],float convergence_factor, double ranking[columns]) {
  int iterations = 0;
  double distance=0;
  double temp[columns];
  initiate_probability_vct(columns, ranking);// initiate the vector with the probability of each node (Constant probability)
    do {
      copy_vct(columns, ranking, temp);//copy the result to the old vector
      iterations++;//count the iterations
      mtx_vct_product(rows, columns, matrix, ranking, ranking);//Product of the matrix and the vector
      distance = euclidean_distance(columns, temp, ranking);//Calculate the euclidean distance of the old vector and result
    } while (convergence_factor < distance);//Repeat until the euclidean distance is less
  return iterations;
}
/*FN****************************************************************************
*
* int pagerank(int rows, int columns,double matrix[][columns],float alpha ,float convergence_factor)
*
* Return: Returns 1 to success 
*
* Purpose: It applies the pagerank algorithm to a matrix
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int pagerank(int rows, int columns,double matrix[][columns],float alpha ,float convergence_factor) {
  int iterations = 0;
  double ranking[columns];
  int positions[columns];
  replace_absorbent_nodes(rows,columns,matrix);//replace absorbent nodes with 1/columns to avoid a non stochastic matrix
  if (is_stochastic_rows(rows, columns, matrix) == true) {//If the matrix is stochastic the algorithm will works
    initiate_vct_123(columns, positions);//initiate a vector to name each node
    replace_zeros(rows, columns, matrix, alpha);// eliminate 0 of the matrix
    transpose_mtx(rows, columns, matrix);// transpose the matrix
    iterations=power_method(rows, columns,matrix,convergence_factor,ranking);
    sort_vct_ranking(columns, ranking, positions);//order the ranking
    print_ranking(columns,ranking, positions);//show results
    printf("Iterations: %d", iterations);//show iteration
    return 1;
  } else {
    printf("The matrix is not stochastic");//if the matrix is not stochastic it will print an error
    return 0;
  }
}