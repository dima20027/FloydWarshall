#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define N_A 1001;


class Flights
{
public:
	Flights();
	~Flights();
	void assemble(string fLink)
	{
		setlocale(0, "");
		fileLink = fLink;
		fstream file(fileLink, ios::in);
		if (!file.is_open()) {
			throw invalid_argument("file link error");
		}

		while (!file.eof()) {
			string city;
			getline(file, city, ';');
			pushBack(city);
			getline(file, city, ';');
			pushBack(city);
			while (file.get() != '\n' && !file.eof());
		}
		file.close();
		file.open(fileLink, ios::in);
		createMatrix();
		while (!file.eof())
		{
			string city;
			getline(file, city, ';');
			nodeList *firstCity = find(city);
			getline(file, city, ';');
			nodeList* secondCity = find(city);
			string next;
			string back;
			getline(file, next, ';');
			if (next != "N/A")
			{
				int temp=0;
				temp = atoi(next.c_str());
				matrix[firstCity->num][secondCity->num] = temp;
			}
			else
			{
				matrix[firstCity->num][secondCity->num] = N_A;
			}
			getline(file, back, '\n');
			if (back != "N/A")
			{
				int temp = 0;
				temp = atoi(back.c_str());
				matrix[secondCity->num][firstCity->num] = temp;
			}
			else
			{
				matrix[secondCity->num][firstCity->num] = N_A;
			}
		}
		for (int i = 0; i < listTail->num + 1; i++)
		{
			for (int j = 0; j < listTail->num + 1; j++)
			{
				if (i != j && matrix[i][j] == 0)
				{
					matrix[i][j] = N_A;
				}
			}
		}
		originalFloydWarshall();
	}


	void printCities()
	{
		if (listHead == nullptr)
		{
			throw out_of_range("Lists Empty");
		}
		nodeList* bypass = listHead;
		while (bypass != nullptr)
		{
			cout <<bypass->num<<"."<< bypass->cityName << "\t";
			bypass = bypass->next;
		}
		printMatrix();
	}

	void printMatrix()
	{
		if (matrix == nullptr)
		{
			throw out_of_range("Matrix Empty");
		}
		cout << endl;
		for (int i = 0; i < listTail->num + 1; i++)
		{
			cout << i << "| ";
			for (int j = 0; j < listTail->num + 1; j++)
			{
				if (matrix[i][j] == 1001)
				{
					cout << "N/A\t";
				}
				else
				{
					cout << matrix[i][j] << "\t";
				}
				
			}
			cout << endl;
		}
	}

	int yourFlight(int cityWhence, int cityWhere)
	{
		if (cityWhence > listTail->num || cityWhere > listTail->num)
		{
			throw out_of_range("Error - incorrect cities");
		}
		return matrix[cityWhence][cityWhere];
	}

	void clear()
	{
		for (int i = 0; i < listTail->num + 1; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		while (listHead != nullptr)
		{
			nodeList* del = listHead;
			listHead = listHead->next;
			delete del;
		}
		listTail = nullptr;
	}


private:

	struct nodeList
	{
		int num=0;
		string cityName;
		nodeList* next = nullptr;
	};
	nodeList* listHead;
	nodeList* listTail;
	string fileLink;
	int** matrix;

	void createMatrix()
	{
		matrix = new int* [listTail->num+1];
		for (int i = 0; i < listTail->num+1; i++)
		{
			matrix[i] = new int[listTail->num+1]{};
		}
	}

	nodeList* find(string cityName)
	{
		nodeList* bypass = listHead;
		while (bypass != nullptr && bypass->cityName != cityName)
		{
			bypass = bypass->next;
		}
		return bypass;
	}

	void pushBack(string cityName)
	{
		if (listHead == nullptr)
		{
			listHead = new nodeList;
			listHead->cityName = cityName;
			listTail = listHead;
		}
		else
		{
			if (find(cityName) == nullptr)
			{	
				listTail->next = new nodeList;
				listTail->next->cityName = cityName;
				listTail->next->num = listTail->num + 1;
				listTail = listTail->next;
			}
		}
	}

	void originalFloydWarshall()
	{
		for (int k = 0; k < listTail->num + 1; k++) {
			for (int i = 0; i < listTail->num + 1; i++) {
				for (int j = 0; j < listTail->num + 1; j++) {

					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}

		return;
	}




};

Flights::Flights()
{
	listHead = nullptr;
	listTail = listHead;
	matrix = nullptr;
}

Flights::~Flights()
{
	//clear();
	cout << "all clear";
}

