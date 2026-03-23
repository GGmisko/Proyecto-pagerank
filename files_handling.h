#include <stdio.h>
#include <stdlib.h>
/*FN****************************************************************************
*
* int count_columns(const char *file_name) 
*
* Return: Returns number of coloumns in a matrix
*
* Purpose: It counts the number of coloumns in a matrix
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int count_columns(const char *file_name) {
  int aux=0;
  int max_char_row=1000;//if the matrix is really big please increase this value
  char temp[max_char_row];
  FILE *file = fopen(file_name, "r");//Open the file
  if (file == NULL)
  {
      printf("Error opening file.\n");//If the file doesn't exist it will print an error
    exit(-1);
  }
  while(feof(file)==0)//It will read the file until it reaches the end of it
    {
      aux++;//It will count the number of lines. It is the same number of rows
      fgets(temp, 1000, file);
    };
  fclose(file);//the file is closed
  return aux;//It will return the number of rows (nodes)
}
/*FN****************************************************************************
*
* int read_mtx(int rows, int columns,const char *file_name,double mtx[][columns])
*
* Return: Returns 1 to success
*
* Purpose: It reads a matrix from a file
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int read_mtx(int rows, int columns,const char *file_name,double mtx[][columns]) {
  FILE *file = fopen(file_name, "r");//Open the file
  if (file == NULL)
  {
      printf("Error opening file.\n");//If the file doesn't exist it will print an error
    exit(-1);
  }
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<columns;j++)
      {
        fscanf(file, "%lf", &mtx[i][j]);//It will read box by box the file and store It in a matrix
      }
  }
  fclose(file);//the file is closed
  return 1;
}
/*FN****************************************************************************
*
* int request_file_name(char *file_name[100])
*
* Return: Returns type of file. 0 if the file is a list or 1 if the list is a matrix
*
* Purpose: It requests the name of a file and the type 
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int request_file_name(char *file_name[100]) {
  int type;
  printf("Enter the file name: ");
  scanf( "%s",file_name); //It will request the name of the file
  printf("Enter 0 if the file is a list or 1 if the file is a matrix: ");
  scanf( "%d",&type); //It will request the type of file
  return type;//It will return the type of file
}

/*FN****************************************************************************
*
* int read_nodes(const char *file_name)
*
* Return: Returns number of nodes
*
* Purpose: It read the first line of a list to know the number of nodes.
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int read_nodes(const char *file_name) {
  int nodes=0;
  FILE *file = fopen(file_name, "r");//Open the file
  if (file == NULL)
  {
      printf("Error opening file.\n");//If the file doesn't exist it will print an error
    exit(-1);
  }
  fscanf(file, "%d",&nodes);//It will read the first line of the file
  fclose(file);
  return nodes;//It will return the number of nodes
}
/*FN****************************************************************************
*
* int read_list(int rows, int columns,const char *file_name,double mtx[][columns])
*
* Return: Returns 1 to success
*
* Purpose: It reads a list from a file and make it a matrix
*
* Register of Revisions:
*
* [2024-02-24] - Juan David Aarón Parra
*              -Function created
*
********************************************************************************/
int read_list(int rows, int columns,const char *file_name,double mtx[][columns]) {
  int row=0;
  int column=0;
  float value=0;
  initiate_zeros_mtx(rows,columns,mtx);//It will initiate the matrix with zeros
  FILE *file = fopen(file_name, "r");//Open the file
  if (file == NULL)
  {
      printf("Error opening file.\n");//If the file doesn't exist it will print an error
    exit(-1);
  }
  fscanf(file, "%d",&value);//It will read the first line of the file (It will not be used, but it's neccesary to trash this value)
  while (fscanf(file, "%d %d %f", &row, &column, &value) == 3) {
      mtx[row - 1][column - 1] = value;//It will conect the nodes with the value of preference
  }
  fclose(file);
  return 1;
}