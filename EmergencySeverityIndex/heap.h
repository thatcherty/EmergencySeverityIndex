#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class heap
{
public:
	void newPatient(string, int);
	string next();
	void print();
private:
	void heapify(vector<pair<string, int>>&, int size);
	vector<pair<string, int>> patients;
};

