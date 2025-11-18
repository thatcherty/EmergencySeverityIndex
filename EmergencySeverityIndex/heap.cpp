#include "heap.h"

void heap::newPatient(string name, int priority)
{
	patients.push_back({ name, priority });
	heapify(patients, patients.size());
}

string heap::next()
{
	if (!patients.size()) return "";

	string nextPatient = patients[0].first;
	pair<string, int> temp = patients[patients.size() - 1];
	patients.pop_back();
	patients[0] = temp;
	heapify(patients, patients.size());

	return nextPatient;
}

void heap::print()
{
	for (int i = 0; i < patients.size(); i++)
	{
		cout << patients[i].first << " " << patients[i].second << endl;
	}
}

void heap::heapify(vector<pair<string,int>>& arr, int size)
{
	int start = (size / 2) - 1;

	for (int i = start; i >= 0; i--)
	{
		int curr = i;

		while (2 * curr + 1 < size)
		{
			bool left = false;
			bool right = false;

			if (curr > size)
			{
				break;
			}

			if (arr[2 * curr + 1].second > arr[curr].second)
			{
				// left child is greater than parent
				left = true;
			}

			if (2 * curr + 2 < size && arr[2 * curr + 2].second > arr[curr].second)
			{
				// right child is greater than parent
				right = true;
			}

			if (left && right)
			{
				if (arr[2 * curr + 1].second > arr[2 * curr + 2].second)
				{
					// swap parent and left node
					pair<string,int> temp = arr[2 * curr + 1];
					arr[2 * curr + 1] = arr[curr];
					arr[curr] = temp;

					// set curr to child to check heap requirement
					curr = 2 * curr + 1;
				}
				else
				{
					// swap parent and right node
					pair<string, int> temp = arr[2 * curr + 2];
					arr[2 * curr + 2] = arr[curr];
					arr[curr] = temp;

					// set curr to child to check heap requirement
					curr = 2 * curr + 2;
				}
			}
			else if (left)
			{
				// swap parent and left node
				pair<string, int> temp = arr[2 * curr + 1];
				arr[2 * curr + 1] = arr[curr];
				arr[curr] = temp;

				// set curr to child to check heap requirement
				curr = 2 * curr + 1;
			}
			else if (right)
			{
				// swap parent and right node
				pair<string, int> temp = arr[2 * curr + 2];
				arr[2 * curr + 2] = arr[curr];
				arr[curr] = temp;

				// set curr to child to check heap requirement
				curr = 2 * curr + 2;
			}
			else
			{
				break;
			}

		}
	}
}

