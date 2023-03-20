// Tomer Zamir    ID: 316123181
#include <stdio.h>
#include<limits.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();

/* Declarations of other functions */
int even_odd(int n);
void func2(int n);
void minmaxsum(int n);
void func4(int n);
void func5(int n);
double func6(int n, double x);
int factorial(int i);
/* ------------------------------- */
// no need to change the main function for matala 1.
// 
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 6; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-6 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 6));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/*.............................*/
void Ex1()
{
	int n;
	printf("Enter a number: ");
	scanf_s("%d", &n);
	printf("\nsum of even digits - sum of odd digits = %d\n", even_odd(n));
}

int even_odd(int n)
{
	int temp, sumeven = 0, sumodd = 0;
	while (n > 0)
	{
		temp = n % 10;
		if (temp % 2 == 0)
			sumeven += temp;
		else sumodd += temp;
		n /= 10;
	}
	return (sumeven - sumodd);
}
// below you will enter your answers to Ex2-Ex5
void Ex2()
{
	int n;
	printf("enter a number>9 : ");
	scanf_s("%d", &n);
	func2(n);
}
void func2(int n)
{
	int x = 1, y = 1;
	for (x = 1; x < n; x++)
	{
		y = 1;
		for (y = 1; y < n; y++)
		{
			if (2 * x + 7 * y == n)
				printf("\n(%d,%d)\n", x, y);
		}
	}
}
void Ex3()
{
	int n = 0;
	while (n < 5)
	{
		printf("enter a number >= 5: ");
		scanf_s("%d", &n);
	}
	rewind(stdin);
	minmaxsum(n);
}
void minmaxsum(int n)
{
	int temp = 0, min = INT_MAX, max = 0, sum = 0;
	printf("enter %d numbers:\n", n);
	while (n > 0)
	{
		scanf_s("%d", &temp);
		if (temp < 0)
		{
			temp = 0;
			printf("don't be so negative, please enter a positive integer:\n");
			continue;
		}
		sum += temp;
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
		n--;
	}
	printf("\nsum = %d\nmin = %d\nmax = %d\n", sum, min, max);
}
void Ex4()
{
	int n;
	printf("Enter a number:\n");
	scanf_s("%d", &n);
	func4(n);
}
void func4(int n)
{
	int temp = n, digits = 0, right, left, f, newnum, res = 0, leftright;
	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}
	if (digits % 2 == 0)
	{
		f = pow(10, digits / 2);
		left = n / f;
		right = n - left * f;
		leftright = left + right;
		newnum = pow(leftright, 2);
		if (newnum == n)
			res = leftright;
	}
	printf("\n%d\n", res);
}
void Ex5()
{
	int n;
	printf("Enter a number\n");
	scanf_s("%d", &n);
	func5(n);
}
void func5(int n)
{
	int i, temp, newnum = 0;
	for (i = 1; n > 0; i *= 10)
	{
		temp = n % 10;
		if (temp == 9)
		{
			newnum += temp * i;
			n /= 10;
			continue;
		}
		else temp = 8 - temp;
		newnum += temp * i;
		n /= 10;
	}
	printf("The new number is: %d\n", newnum);
}
void Ex6()
{
	int n;
	double x;
	printf("Enter a number for n >= 0:\n");
	scanf_s("%d", &n);
	printf("Enter a number for x:\n");
	scanf_s("%lf", &x);
	printf("S = %lf\n", func6(n, x));

}
double func6(int n, double x)
{
	int i, limit = 2 * n + 1;
	double j = 2, s = 0, power, mone, mechane;
	s += x - 1;
	power = x - 1;
	for (i = 3; i <= limit; i += 2)
	{
		mone = pow(power, i);
		mechane = j * factorial(i);
		j++;
		s += mone / mechane;
	}
	return s;
}
int factorial(int i)
{
	int f, res = 1;
	for (f = 1; f <= i; f++)
	{
		res *= f;
	}
	return res;
}