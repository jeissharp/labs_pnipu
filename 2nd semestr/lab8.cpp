#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

struct Film
{
	string Name;
	string Producer;
	string Country;
	int Income;
	void Input()
	{
		cout << "Enter the name of the film: ";
		getline(cin, Name);
		cout << "Enter the producer of the film: ";
		getline(cin, Producer);
		cout << "Enter the country of the film: ";
		getline(cin, Country);
		cout << "Enter the income of the film (in dollars): ";
		cin >> Income;
		cin.get();
	}
	void Output()
	{
		cout << "Name:    \t" << Name << "\nProducer:\t" << Producer << "\nCountry: \t" << Country << "\nIncome:  \t" << Income << "$\n_______________________" << endl;
	}
	void DeletePrelasts()
	{
		Name = "";
		Producer = "";
		Country = "";
		Income = NULL;
	}	
};

void adding(struct Film str[101], int n, int r)
{
	for (int i = n; i >= r; i--)
	{
		str[i + 1].Name = str[i].Name;
		str[i + 1].Producer = str[i].Producer;
		str[i + 1].Country = str[i].Country;
		str[i + 1].Income = str[i].Income;
	}
	str[r].Name = "";
	str[r].Producer = "";
	str[r].Country = "";
	str[r].Income = 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream exit("Result.txt");
	Film arr[101];
	int r,n = 2;
	exit << "__________________________\n\n\tList of Films:\n__________________________\n"; 
	while (n <= 2 || n > 100)
	{
		cout << "Enter the amount of films (Min is 3, Max is 100): ";
		cin >> n;
	}
	cin.get();
	for (int i = 0; i < n; i++)
	{
		arr[i].Input();
	}
	cout << "_______________________\n\n\tPRINTING:\n_______________________\n";
	for (int i = 0; i < n; i++)
	{
		arr[i].Output();
	}
	cout << "Deleting the last 2 elements: \n";
	arr[n - 1].DeletePrelasts();
	arr[n - 2].DeletePrelasts();
	n = n - 2;
	cout << "_______________________\n\n\tPRINTING:\n_______________________\n";
	for (int i = 0; i < n; i++)
	{
		arr[i].Output();
	}
	cout << "Select the film: \n";
	for (int i = 0; i < n; i++)
	{
		cout <<"("<< i+1 <<") "<<arr[i].Name<<endl;
	}
	cin >> r;
	while (r <= 0 || r > n)
	{
		cout << "Wrong input, try again: ";
		cin >> r;
	}
	cin.get();
	n++;
	adding(arr, n, r);
	cout << "Enter the film: \n";
	arr[r].Input();
	cout << "_______________________\n\n\tPRINTING:\n_______________________\n";
	for (int i = 0; i < n; i++)
	{
		arr[i].Output();
		exit << "Name:    \t" << arr[i].Name << "\nProducer:\t" << arr[i].Producer << "\nCountry: \t" << arr[i].Country << "\nIncome:  \t" << arr[i].Income << "$\n_______________________" << endl;
	}
	cout << "File \"Result.txt\" created.\n_______________________\n";
	exit.close();
	return 0;
}
