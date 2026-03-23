#include "pagerank_subfunctions.h"
#include "files_handling.h"
#define ALPHA 0.85
#define EPSILON 0.001
int main(void) { 
  const char *file[100];//File name
  int num=request_file_name(file);//Type of file
  int nodes=0;//Number of nodes
  if(num==1)
  {
    nodes=count_columns(file);//if the file is a matrix it will count the number of columns
  }
  else{
    nodes=read_nodes(file);//if the file is a list it will read the number of nodes
  }
  double matrix[nodes][nodes];
  if(num==1)
  {
    read_mtx(nodes,nodes,file,matrix);//if the file is a matrix it will read the matrix
  }
  else{
    read_list(nodes,nodes,file,matrix);//if the file is a list it will read the list
  }
  pagerank(nodes,nodes,matrix,ALPHA,EPSILON); //Finally it will calculate the pagerank :)
}
/*FN****************************************************************************
*
* 
* The matrix 4 is a 4x4 matrix NOT STOCHASTIC. This is to show that the algorithm works.
* Matrix, matrix 2 and matrix 3 are test matrices. Use it to test the algorithm.
* The format of the list is:
* the first line is the number of nodes.
* The next lines are [row]  [file]  [value of preference]
* If the list does not have a value, the value is 0.
* The code will not work if the list doesn't have this format. Please do it correctly.
*
* Lista.txt and Matriz5.txt are the same matrix. 
*
* Thanks for your attention. 
*
* If you have questions, check malfunctions or have suggestions please contact: juan_aaronp@javeriana.edu.co
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              
*
********************************************************************************/