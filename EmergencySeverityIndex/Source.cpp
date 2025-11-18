#include "heap.h"

using namespace std;

int main()
{
	int size = 15;

	heap patientList;

	for (int i = 0; i < size; i++)
	{
		patientList.newPatient(to_string(i+65), (i%5)+1);
	}

	patientList.print();

	cout << endl;

	string temp = patientList.next();

	cout << "The top priority patient is: " << temp << endl;

	patientList.print();
	cout << endl;

	temp = patientList.next();

	cout << "The top priority patient is: " << temp << endl;

	patientList.print();

	return 0;
}