/*
	Don Morton
	10/21/2018
	Skynet-HK Aerial
*/

//
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));  //seeds a random number generator

	// initial values of the variables.
	int searchhigh = 64;
	int searchlow = 1;
	int targetlocation = rand() % 64 + 1; // gives "taget locatoin" on the 8x8 grid
	int targetsearchprediction = 0;
	int attemptB = 0;
	int attemptH = 0;
	int attemptR = 0;
	int attemptL = 0;
	int humanguess;
	

	// bool variables
	bool istargetfoundB = false;
	bool istargetfoundH = false;
	bool istargetfoundR = false;
	bool istargetfoundL = false;
	bool cont = true;

	// used for the repeat function
	char again = 'y';

	// words to initiate person playing game
	cout << "==========================================================\n";
	cout << "This is the HK Aerial software testing suite.\n";
	cout << "The purpose of this is to test Human intuition versus a linear search program\n and a random search program.\n";
	cout << "We will start with the Human. The target grid is 8x8 (64 total positions)\n";
	

	while (cont)
	{
		// sets vaules to base each iteration
		istargetfoundH = false;
		istargetfoundB = false;
		istargetfoundR = false;
		istargetfoundL = false;
		targetlocation = rand() % 64 + 1;
		searchlow = 1;
		searchhigh = 64;
		attemptB = 0;
		attemptH = 0;
		attemptR = 0;
		attemptL = 0;

		// Human Guess
		while (!istargetfoundH)
		{
			cout << "Please enter your first guess (1-64):";
			cin >> humanguess;
			++attemptH;
			if (humanguess > targetlocation)
			{
				cout << "\n======================================\n";
				cout << "Too high! Try again.\n";
			}
			else if (humanguess < targetlocation)
			{
				cout << "======================================\n";
				cout << "Too low. Try again.\n";
			}
			else if (humanguess == targetlocation)
			{
				istargetfoundH = true;
				cout << "======================================\n";
				cout << " You have found the target at " << targetlocation << endl;
			}
		}

		//Binary algorithm
		while (!istargetfoundB)
		{
			// Binary guess
			targetsearchprediction = ((searchhigh - searchlow) / 2) + searchlow;
			++attemptB;

			if (targetsearchprediction > targetlocation)
			{
				searchhigh = targetsearchprediction - 1;
			}

			else if (targetsearchprediction < targetlocation)
			{
				searchlow = targetsearchprediction + 1;
			}

			else if (targetsearchprediction == targetlocation)
			{
				istargetfoundB = true;
			}
		}

		// Random algorithm
		while (!istargetfoundR)
		{
			int randsearch = rand() % 64 + 1;
			++attemptR;

			if (randsearch > targetlocation)
			{
			}
			else if (randsearch < targetlocation)
			{
			}
			else if (randsearch == targetlocation)
			{
				istargetfoundR = true;
			}
		}

		// Linear algorithm
		while (!istargetfoundL)
		{ 
			for ( attemptL = 0; attemptL < targetlocation; ++attemptL)
			{
			}
			istargetfoundL = true;
		}

		cout << "======================================\n";
		cout << "Target located in grid " << targetsearchprediction << ".\n";
		cout << "It took the HUMAN " << attemptH << " attempts to find the target.\n";
		cout << "It took the Binary Search program " << attemptB << " attempts to find the target.\n";
		cout << "It took the Random Search program " << attemptR << " attempts to find the target.\n";
		cout << "It took the Linear Search program " << attemptL << " attempts to find the target.\n";

		cout << "Continue playing?";
		cin >> again;
		if (again == 'n' || again == 'N')
		{
			cont = false;
		}
	}


	system("pause");

	return 0;
}