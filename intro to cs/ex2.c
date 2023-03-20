// Tomer Zamir	ID: 316123181
#include <stdio.h>
#include <math.h>
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

/* Declarations of other functions */
int sumofodd_even(int flag);
int func2(int num, int flag);
int func3(int n, int i, int res);
int func4(int n, int max);
void func5(int n);
/* ------------------------------- */
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/*.............................*/
void Ex1()
{
	int f = 1, res;
	res = sumofodd_even(f);
	printf("sum is: %d\n", res - 1);
}
int sumofodd_even(int flag)
{
	int num = 0;
	printf("enter a number. to stop enter -1 >> \n");
	scanf_s("%d", &num);	
	if (num != -1)
	{
		if (flag == -1)
			num *= -1;
		return num + sumofodd_even((-1) * flag);
	}
}

void Ex2()
{
	int num, flag = 0;
	printf("Enter a number >> ");
	scanf_s("%d", &num);
	printf("result = %d\n", func2(num, flag));
}
int func2(int n, int flag)
{
	int left, right, sumleft = 0, sumright = 0, digits = 0, temp = n;
	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}
	right = n % 100;
	left = (n / 100) % 100;
	if (right == n)
		return 0;
	while (right > 0)
	{
		sumright += right % 10;
		right /= 10;
	}
	while (left > 0)
	{
		sumleft += left % 10;
		left /= 10;
	}
	if (sumright == sumleft)
		return 0;
	if (sumleft > sumright && flag != 1)
	{
		if (digits > 4)
			return func2(n / 100, -1);
		return -1;
	}
	if (sumright > sumleft && flag != -1)
	{
		if (digits > 4)
			return func2(n / 100, 1);
		return 1;
	}
	else flag = 0;
	return flag;
}

void Ex3()
{
	int n;
	printf("Enter a postivie integer >> ");
	scanf_s("%d", &n);
	printf("new number is: %d\n", func3(n, 0, 0));
}
int func3(int n, int i, int res)
{
	int d = n % 10;
	int power = pow(10, i);
	if (d > 7)
		d -= 8;
	else d += 2;
	if (n < 10)
		return 	res += (d * power);
	res += (d * power);
	return func3(n / 10, i + 1, res);
}

void Ex4()
{
	int n;
	printf("Enter  number>> ");
	scanf_s("%d", &n);
	printf("max is: %d\n", func4(n, 0));
}
int func4(int n, int max)
{
	int temp, sumoftemp = 0;
	temp = n % 1000;
	while (temp > 0)
	{
		sumoftemp += temp % 10;
		temp /= 10;
	}
	if (sumoftemp > max)
		max = sumoftemp;
	if (n < 1000 && sumoftemp > max)
		return sumoftemp;
	else if (n < 1000)
		return max;
	return func4(n / 10, max);
}

void Ex5() 
{
	int num;
	printf("Enter a positive number: ");
	scanf_s("%d", &num);
	func5(num);
}
void func5(int n)
{
	if (n % 2 != 0)
		return;
	else printf("%d\n", 2);
	func5(n / 2);
}