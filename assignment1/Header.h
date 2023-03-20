//Name: Tomer Zamir		id: 316123181
//
#pragma once
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define R 4
#define C 4
//structs:
typedef int list_type;
typedef struct item
{
	list_type data;
	struct item* next;
}item;
//
typedef struct trio_data
{
	int i;
	int j;
	int num;
}trio_data;
typedef struct trio
{
	trio_data data;
	struct trio* next;
} trio;
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
//other functions declerations:
int* powerArray(int n); //Ex1
int** matrixSubtraction(int mat1[][C], int mat2[][C],int**cols); //Ex2
item* reverse_list(item* h); //Ex3
int is_ij_equal_element(int*** mat, int r, int c, trio_data** arr, trio** lst); //Ex4
//utility functions declerations:
void buildMatrix(int m[][C], int rows, int cols);
void printArray(int* arr, int size);
int** allocMatrix(int rows, int cols);
void freeMatrix(int** mat, int r);
void printMatrix(int mat[][C], int r, int c);
void printResMatrix(int** mat,int r, int* c);
void freeMatrix(int** mat, int rows);
//
item* build_list();
void print_item_list(item* h);
void free_item_list(item* h);
//
int** alloc_dynamic_matrix(int rows,int cols);
void build_dynamic_matrix(int** m, int rows, int cols);
void print_dynamic_Matrix(int** mat, int r, int c);
void print_trio_array(trio_data* arr, int size);
void print_trio_list(trio* h);
void free_trio_list(trio* h);
