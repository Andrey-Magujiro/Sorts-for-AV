#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include<ctime>

using namespace std;

int whriteToFile()
{
	int * arr = new int[1000]{ 0 };
	srand(time(0));
	for (int i = 0; i < 1000; i++)
	{
		arr[i] = rand() % 99;
	}

	fstream inOut("D:\\c++\\inOutFile.txt", ios::out);
	if (!inOut.is_open()) { throw - 1; }

	for (int i = 1; i < 1001; i++)
	{
		if (i % 20 != 0) { inOut << arr[i - 1] << " "; }
		if (i % 20 == 0 && i != 0) { inOut << arr[i - 1] << endl; }
	}

	inOut.close();
	delete[] arr;
}


int setArrFromFile(std::vector<int> &arr)
{
	try { whriteToFile(); }
	catch (int a)
	{
		cout << "file is not opening!!!" << endl;
		return 0;
	}
	ifstream in("D:\\c++\\inOutFile.txt", ios::in);
	if (!in.is_open()) { throw - 1; }
	int buff;
	int i = 1;
	do {
		in >> buff;
		arr.push_back(buff);
		i++;
	} while (!in.eof());

	try {}
	catch (int a)
	{
		cout << "file is not opening!!!" << endl;
		return 0;
	}

	in.close();
}
