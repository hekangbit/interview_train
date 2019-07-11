#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


//Find in the vector, is vector has 2 elements v1, v2
//and v1 + v2 can equal to target value

void addsToTarget(vector<int> &numbers, int target)
{
	unordered_map<int, int> numToIndex;
	for (auto it = numbers.begin(); it != numbers.end(); it++)
	{
		if (numToIndex.count(target - *it))
		{
			cout << "index a:" << numToIndex[target-*it] <<
				"; value a:" << target - *it << endl;
			cout << "index b:" << it - numbers.begin() <<
				"; value b:" << *it << endl;

		}
		numToIndex[*it] = it - numbers.begin();
	}
	cout << "No result!" << endl;
}

int main()
{
	vector<int> v = {1,2,3,4,5,11,22,33,44,55,23,34,45,56,67};
	addsToTarget(v, 77);
	return 0;
}
