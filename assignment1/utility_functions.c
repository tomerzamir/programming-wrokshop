//Name: Tomer Zamir		id: 316123181
//
#include"Header.h"
//
void printArray(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
//
void buildMatrix(int m[][C], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			scanf_s("%d", &m[i][j]);
		if (i != rows - 1) printf("next row:\n");
	}
}
int** allocMatrix(int rows, int cols)
{
	int i;
	int** mat = calloc(rows, sizeof(int));
	assert(mat);
	for (i = 0; i < rows; i++)
	{
		mat[i] = (int*)calloc(cols, sizeof(int));
		if (!mat[i])
		{
			freeMatrix(mat, i);
			return NULL;
		}
	}
	return mat;
}
void printMatrix(int mat[][C], int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			printf("%4d ", mat[i][j]);
		printf("\n");
	}
}
void printResMatrix(int** mat,int r,int* c)
{
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < (c[i]); j++)
			printf("%4d ", mat[i][j]);
		printf("\n");
	}
}
void freeMatrix(int** mat, int rows)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		if (mat[i])
			free(mat[i]);
	}
	free(mat);
}
//
item* build_list()
{
	item* lst, * curr_point = NULL;
	int c;
	printf("enter a positive number for the list, to stop enter a negative number.\n");
	scanf_s("%d", &c);
	lst = NULL;
	while (c >= 0)
	{
		if (lst == NULL)
		{
			lst = (item*)malloc(sizeof(item));
			curr_point = lst;
		}
		else
		{
			curr_point->next = malloc(sizeof(item));
			curr_point = curr_point->next;
		}
		curr_point->data = c;
		scanf_s("%d", &c);
	}
	curr_point->next = NULL;
	return lst;
}
void print_item_list(item* h)
{
	item* p = h;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void free_item_list(item* h)
{
	item* ptr = h;
	while (ptr)
	{
		item* next = ptr->next;
		free(ptr);
		ptr = next;
	}
}
//
int** alloc_dynamic_matrix(int rows,int cols)
{
	int i;
	int** mat = calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++)
	{
		mat[i] = calloc(cols, sizeof(int));
	}
	return mat;
}
void build_dynamic_matrix(int** m, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			scanf_s("%d", &m[i][j]);
		if (i != rows - 1) printf("next row:\n");
	}
}
void print_dynamic_Matrix(int** mat, int r, int c)
{
	printf("matrix:\n");
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			printf("%4d ", mat[i][j]);
		printf("\n");
	}
}
void print_trio_array(trio_data* arr,int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("i = %d ", (arr[i]).i);
		printf("j = %d ", (arr[i]).j);
		printf("num = %d,  ", (arr[i]).num);
	}
	printf("\n");
}
void print_trio_list(trio* h)
{
	trio* p = h;
	while (p)
	{
		printf("i = %d ", (p->data.i));
		printf("j = %d ", (p->data.j));
		printf("num = %d,  ", (p->data.num));
		p = p->next;
	}
	printf("\n");
}
void free_trio_list(trio* h)
{
	trio* ptr = h;
	while (ptr)
	{
		trio* next = ptr->next;
		free(ptr);
		ptr = next;
	}
}