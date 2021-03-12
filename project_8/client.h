#pragma once
#include <iostream>
#include<vector>
#include"setarr.h"
#include "selectsort.h"
#include "insertsort.h"
#include "bubblesort.h"
#include "context.h"
#include "setArrFromFile.h"


int Client()
{
	vector<int> arr = {};
	int actionOne;
	do {
		cout << "1- set array from consol,  2- set array from file" << endl;
		cin >> actionOne;
		if (actionOne == 1) { setArr(arr); break; }
		else if (actionOne == 2)
		{
			try { setArrFromFile(arr); }
			catch (int a)
			{
				cout << "file is not opening!!!" << endl;
				return 0;
			}
			break; 
		}
	} while (actionOne > 2 || actionOne <= 0);

	const vector<int> constArr = arr;
	Context *context = new Context(arr, new SelectionSort());

	cout << "1- Bubble sorting " << " 2-Selection sorting " << " 3-Insertion sorting " << " 0-exit to programm!" << endl;
	int action;
	cout << "Enter number of action: ";
	cin >> action;
	cout << endl;

	while (action != 0)
	{
		switch (action)
		{
		case(1):
		{
			vector<int> copyArr = constArr;
			context->setSort(copyArr, new BubbleSort());
			cout << "  Bubble sorting!  " << endl;
			context->callSort();
			break;
		}
		case(2):
		{
			vector<int> copyArr = constArr;
			context->setSort(copyArr, new SelectionSort());
			cout << "  Selection sorting!  " << endl;
			context->callSort();
			break;
		}
		case(3):
		{
			vector<int> copyArr = constArr;
			context->setSort(copyArr, new InsertSort());
			cout << "  Insertion sorting!  " << endl;
			context->callSort();
			break;
		}
		default:
			cout << "Entering invalid number, try again!" << endl;
			break;
		}
		cout << "Enter number of action: ";
		cin >> action;
		cout << endl;
	}

};