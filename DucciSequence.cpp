

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;



void vectorAssign(vector<int> &aVector, string myString)

{
	stringstream ss;
	string temp;
	int num;
	
	myString.erase(0, 1); //remove leading "("
	ss << myString;
	while (!ss.eof())
	{

		ss >> temp;
		if (stringstream(temp) >> num)
		{
			aVector.push_back(num);
		}
		
		temp = "";
	
	
	}

	



}

void ducciSeq(vector<int> &aVector, vector<vector<int>> &masterList)
{

	int temp, difference, sum = 0, count = 1; //holds temp values for ducci sequence
	bool done = false;
	masterList.push_back(aVector); //load initial given numbers to master list

	cout << "[";
	for (unsigned int i = 0; i < aVector.size() - 1; i++)
	{
		cout << aVector[i] << "; ";

	}
	cout << aVector.back() << "]" << endl;


	while (!done)

	{

		

		temp = (aVector[0] > aVector.back()) ? aVector[0] - aVector.back() : aVector.back() - aVector[0];
		for (unsigned int i = 0; i < aVector.size() - 1; i++)
		{
			aVector[i] = (aVector[i] > aVector[i + 1]) ? aVector[i] - aVector[i + 1] : aVector[i + 1] - aVector[i]; //decide which is larger, value in vector[i] or vector[i+1]. 
																													//Then subtract the smaller one from the larger one.
		}
		
		aVector.back() = temp;
		
		cout << "[";
		for (unsigned int i = 0; i < aVector.size()-1; i++)
		{
			cout << aVector[i] << "; ";

		}
		cout << aVector.back() << "]" << endl;


		for (unsigned int i = 0; i < masterList.size(); i++)
		{
			if (aVector == masterList[i])
			{
				done = true;
				break;

			}
		}
		count++;
		
		if (done)
			break;
		

		masterList.push_back(aVector);
		sum = 0;
		for (unsigned int i = 0; i < aVector.size(); i++)
		{
			sum += aVector[i];
		}

		if (sum == 0)
			done = true;
		


	}

	cout << count << " steps." << endl;


}



int main()
{
	vector<int> myVector; // vector to hold all int values
	vector < vector<int> > listOfVectors;
	string userInput;	 // hold input string
	string message = "Please enter your values: " ;


	cout << message;
	getline(cin, userInput);
	vectorAssign(myVector, userInput);
	ducciSeq(myVector, listOfVectors);


	system("Pause");
	return 0;



    
}

