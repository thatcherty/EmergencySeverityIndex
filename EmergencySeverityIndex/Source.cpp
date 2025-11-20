#include "heap.h"

using namespace std;

int main()
{
	int size;
	int priority;
	heap patientList;

	cout << "Enter the number of patients to add: " << endl;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Please enter the priority for patient number " << i+1 << " (1-5): " << endl;
		cin >> priority;

		while (priority > 5 || priority < 1)
		{
			cout << "Please enter a valid priority for patient number " << i+1 << " (1-5): " << endl;
			cin >> priority;
		}

		patientList.newPatient(to_string(i+1), priority);
	}

	cout << "The initial patient list: " << endl;

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