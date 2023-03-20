//Name: Tomer Zamir		id: 316123181
//
#include"Header.h"
//
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 4; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-4 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 4));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}
//
void Ex1()
{
	int num;
	printf("enter the size of the array: ");
	scanf_s("%d", &num);
	int* p = powerArray(num);
	printArray(p, num);
	free(p);
}
int* powerArray(int n)
{
	int i;
	int* pa = (int*)calloc(n, sizeof(int));
	assert(pa);
	for (i = 0; i < n; i++)
	{
		pa[i] = (int)pow(2, i);
	}
	return pa;
}
//
void Ex2()
{
	int mat1[R][C] = { { 2,7,12,1 },{3,4,5,9},{13,1,0,9},{5,3,2,9} };
	int mat2[R][C]= { { 1,7,7,3 },{3,4,5,9},{13,1,0,9},{5,3,2,9} };
	int* cols;
	printf("first matrix:\n");
	printMatrix(mat1, R, C);
	printf("second matrix:\n");
	printMatrix(mat2, R, C);
	printf("result matrix:\n");
	int**resMat = matrixSubtraction(mat1, mat2,&cols);
	printResMatrix(resMat,R,cols);
	freeMatrix(resMat, R);
	free(cols);
}
int** matrixSubtraction(int mat1[][C], int mat2[][C],int**cols)
{
	int x, i, j, flag, b;
	*cols = (int*)calloc(R, sizeof(int));
	int** resMat = (int**)malloc(R * sizeof(int*));
	for (i = 0; i < C; i++)
	{
		resMat[i] = (int*)malloc(C * sizeof(int));
	}
	for (i = 0; i < R; i++)
	{
		b = 0;
		for (j = 0; j < C; j++)
		{
			x = mat1[i][j] - mat2[i][j];
			if (x > 0)
			{
				resMat[i][b] = x;
				b++;
			}
		}
		(*cols)[i] = b;
		if (b == 0)
		{
			free(resMat[i]);
			resMat[i] = NULL;
		}
		else resMat[i] = (int*)realloc(resMat[i], b * sizeof(int));
	}
	return resMat;
}
//
void Ex3() 
{
	item* head = build_list();
	print_item_list(head);
	head = reverse_list(head);
	print_item_list(head);
	free_item_list(head);
}
item* reverse_list(item* h)
{
	item* next;
	item* pre = NULL;
	while (h)
	{
		next = h->next;
		h->next = pre;
		pre = h;
		h = next;
	}
	h = pre;
	return h;
}
//
void Ex4() 
{
	int rows, cols;
	printf("enter the number of rows in the matrix:\n");
	scanf_s("%d", &rows);
	printf("enter the number of cols in the matrix:\n");
	scanf_s("%d", &cols);
	int** mat = alloc_dynamic_matrix(rows,cols);
	printf("enter values for the first row of the matrix:\n");
	build_dynamic_matrix(mat,rows,cols);
	print_dynamic_Matrix(mat, rows, cols);
	trio_data* arr = NULL;
	trio* lst = NULL;
	int size = is_ij_equal_element(mat, rows,cols, &arr, &lst);
	printf("array:\n");
	print_trio_array(arr, size);
	printf("list:\n");
	print_trio_list(lst);
	printf("size: %d\n", size);
	free(arr);
	free_trio_list(lst);
	freeMatrix(mat, rows);
}
int is_ij_equal_element(int*** mat, int r, int c, trio_data** arr, trio** lst)
{
	int i, j, x, b = 0, count = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			x = i + j;
			if (mat[i][j] == x)
			{
				count++;
			}
		}
	}
	if (count)
		*arr = malloc(count * sizeof(trio_data));
	else *arr = NULL;
	*lst = NULL;
	trio* ptr = lst;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			x = i + j;
			if (mat[i][j] == x)
			{
				(*arr)[b].num = x;
				(*arr)[b].i = i;
				(*arr)[b].j = j;
				if (!(*lst))
				{
					*lst = (trio*)malloc(sizeof(trio));
					ptr = *lst;
				}
				else
				{
					ptr->next = malloc(sizeof(trio));
					ptr = ptr->next;
				}
				ptr->data = (*arr)[b];
				ptr->next = NULL;
				b++;
			}
		}
	}
	return count;
}
