#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>

using namespace std;

void Simple(int *x);

void linearSearch(int *key, int *arr);

void binarySearch(int *key, int *a, int arr);





int q;

void main()

{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int nz;

	do
	{
		cout << "Vedite nomer zd ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			/* "Написать функцию, которая проверяет, является ли переданное ей" 
				 "число простым? Число называется простым, если оно делится без " 
				"остатка только на себя и на единицу*/
			int a;
			cout << "Vedite chislo  ";
			cin >> a;
			Simple(&a);

		}break;

		case 2:
		{
			/*Написать функцию, реализующую алгоритм линейного поиска заданного
				ключа в одномерном массиве*/
			int mas[10] = { 0 };
			int a;
			cout << "Vedite chislo   "; 
			cin >> a;
			cout << "Massiv"<<endl;
			for (int i = 0; i < 10; i++)
			{
				mas[i] = rand() % 25;
				cout << mas[i] << "\t";
			}

			linearSearch(&a, mas);

		}break;

		case 3:
		{
			/*Написать функцию, реализующую алгоритм бинарного поиска заданного 
				ключа в одномерном массиве*/
			int mas[10] = { 0 };
			int a;
			cout << "Vedite chislo ";
			cin >> a;
			cout << "Massiv"<<endl;
			for (int i = 0; i < 10; i++)
			{
				mas[i] = rand() % 25;
				cout << mas[i] << "\t";
			}
			binarySearch(&a, mas, 10);
		}break;

		


		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
		{
			cout << "ошибка" << endl;
		}
		}
	} while (nz > 0);


}


void Simple(int *x)
{
	int i, count = 0;
	for (i = 2; i < *x; i++)
	{
		if (*x%i == 0)
			count++;
	}

	if (count > 0)
		cout << "Ne prostoe chislo";

	if (count == 0)
		cout << "Prostoe chislo";
}

void linearSearch(int *key, int *arr)
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == *key)
		{
			cout << "True " << i + 1 << endl;
			count++;
		}
	}

	if (count == 0)
		cout << "Takogo net chisla";
}

void binarySearch(int *key, int *a, int rr)
{
	int j;
	cout << "Sortyrovka";
	for (int i = 0; i <= rr - 1; i++)
	{
		for (j = (rr - 1); j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}

		}
		cout << "a[" << i << "] = " << a[j] << endl;
	}


	int left = 0;
	int right = 19;
	int count = 0;
	int issearch = -1;

	while (left <= right)
	{
		count++;
		int mid = (left + right) / 2;

		if (*key == a[mid])
		{
			issearch = mid;
			break;
		}

		if (*key < a[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (issearch == -1)
		cout << "Eror" << endl;
	else
	{
		cout << "a[" << issearch << "]=" << a[issearch] << " (за " << count << " проход(-а, -ов)" << endl;
	}
}
