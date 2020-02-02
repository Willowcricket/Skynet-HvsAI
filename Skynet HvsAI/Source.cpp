#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	char retry = 'Y';
	do {
		srand(static_cast<unsigned int>(time(0)));
		int AI_BinarySearchGridLowNumber = 1;
		int AI_BinarySearchGridHighNumber = 64;
		int AI_LinearSearchGridLowNumber = 1;
		int AI_LinearSearchGridHighNumber = 64;
		int AI_RandomSearchGridLowNumber = 1;
		int AI_RandomSearchGridHighNumber = 64;
		int Human_SearchGridLowNumber = 1;
		int Human_SearchGridHighNumber = 64;

		int AI_BinaryNumberOfPredictions = 0;
		int AI_BinaryCurrentLocationPrediction = 0;
		int AI_LinearNumberOfPredictions = 0;
		int AI_LinearCurrentLocationPrediction = 0;
		int AI_RandomNumberOfPredictions = 0;
		int AI_RandomCurrentLocationPrediction = 0;
		int Human_NumberOfPredictions = 0;
		int Human_CurrentLocationPrediction = 0;

		int actualTargetLocation = rand() % AI_BinarySearchGridHighNumber + AI_BinarySearchGridLowNumber;
		int AI_BinaryAttemptToLocateTarget = rand() % AI_BinarySearchGridHighNumber + AI_BinarySearchGridLowNumber;
		int AI_LinearAttemptToLocateTarget = 1;
		int AI_RandomAttemptToLocateTarget = rand() % AI_RandomSearchGridHighNumber + AI_RandomSearchGridLowNumber;

		cout << "\n\n\tWelcome to the AI Drone Hunter 3000! \n" << endl;

		//Human tries to find target
		cout << " Human Predictions" << endl;
		do {
			cout << " -------------------------------------------------" << endl;
			cout << " The target is in a random sector location" << endl;
			cout << " Human, please select a sector between sectors: " << Human_SearchGridLowNumber << " and " << Human_SearchGridHighNumber << endl;
			cin >> Human_CurrentLocationPrediction;
			cout << " The human guesses that the target is in sector " << Human_CurrentLocationPrediction << endl;
			++Human_NumberOfPredictions;

			if (Human_CurrentLocationPrediction > actualTargetLocation) {
				cout << " The human target prediction was too high" << endl;
				Human_SearchGridHighNumber = Human_CurrentLocationPrediction - 1;
				cout << " -------------------------------------------------\n" << endl;
			}
			else if (Human_CurrentLocationPrediction < actualTargetLocation) {
				cout << " The human target prediction was too low" << endl;
				Human_SearchGridLowNumber = Human_CurrentLocationPrediction + 1;
				cout << " -------------------------------------------------\n" << endl;
			}
			else {
				cout << " That's it! The Human found the target in " << Human_NumberOfPredictions << " predictions!" << endl;
				cout << " -------------------------------------------------" << endl;
			}
		} while (Human_CurrentLocationPrediction != actualTargetLocation);

		cout << "\n The Human is done, start Binary AI?" << endl;
		system("Pause");

		//Binary AI Tries to find target
		cout << "\n AI Binary Predictions" << endl;
		do {
			cout << " -------------------------------------------------" << endl;
			cout << " The real target location is in sector " << actualTargetLocation << endl;
			AI_BinaryAttemptToLocateTarget = ((AI_BinarySearchGridHighNumber - AI_BinarySearchGridLowNumber) / 2) + AI_BinarySearchGridLowNumber;
			cout << " The AI guesses that the target is in sector " << AI_BinaryAttemptToLocateTarget << endl;
			++AI_BinaryNumberOfPredictions;

			if (AI_BinaryAttemptToLocateTarget > actualTargetLocation) {
				cout << " The AI target prediction was too high" << endl;
				AI_BinarySearchGridHighNumber = AI_BinaryAttemptToLocateTarget - 1;
				cout << " -------------------------------------------------\n" << endl;
			}
			else if (AI_BinaryAttemptToLocateTarget < actualTargetLocation) {
				cout << " The AI target prediction was too low" << endl;
				AI_BinarySearchGridLowNumber = AI_BinaryAttemptToLocateTarget + 1;
				cout << " -------------------------------------------------\n" << endl;
			}
			else {
				cout << " That's it! The Binary AI found the target in " << AI_BinaryNumberOfPredictions << " predictions!" << endl;
				cout << " -------------------------------------------------" << endl;
			}
		} while (AI_BinaryAttemptToLocateTarget != actualTargetLocation);

		cout << "\n The Binary AI is done, start Linear AI?" << endl;
		system("Pause");

		//Linear AI Tries to find target
		cout << "\n AI Linear Predictions" << endl;
		do {
			cout << " -------------------------------------------------" << endl;
			cout << " The real target location is in sector " << actualTargetLocation << endl;
			cout << " The AI guesses that the target is in sector " << AI_LinearAttemptToLocateTarget << endl;
			++AI_LinearNumberOfPredictions;

			if (AI_LinearAttemptToLocateTarget < actualTargetLocation) {
				cout << " The AI target prediction was too low" << endl;
				AI_LinearAttemptToLocateTarget = AI_LinearAttemptToLocateTarget + 1;
				cout << " -------------------------------------------------\n" << endl;
			}
			else {
				cout << " That's it! The Linear AI found the target in " << AI_LinearNumberOfPredictions << " predictions!" << endl;
				cout << " -------------------------------------------------" << endl;
			}
		} while (AI_LinearNumberOfPredictions != actualTargetLocation);

		cout << "\n The Linear AI is done, start Random AI?" << endl;
		system("Pause");

		//Random AI Tries to find target
		cout << "\n AI Random Predictions" << endl;
		do {
			cout << " -------------------------------------------------" << endl;
			cout << " The real target location is in sector " << actualTargetLocation << endl;
			AI_RandomAttemptToLocateTarget = rand() % AI_RandomSearchGridHighNumber + AI_RandomSearchGridLowNumber;
			cout << " The AI guesses that the target is in sector " << AI_RandomAttemptToLocateTarget << endl;
			++AI_RandomNumberOfPredictions;

			if (AI_RandomAttemptToLocateTarget > actualTargetLocation) {
				cout << " The AI target prediction was too high" << endl;
				cout << " -------------------------------------------------\n" << endl;
			}
			else if (AI_RandomAttemptToLocateTarget < actualTargetLocation) {
				cout << " The AI target prediction was too low" << endl;
				cout << " -------------------------------------------------\n" << endl;
			}
			else {
				cout << " That's it! The Random AI found the target in " << AI_RandomNumberOfPredictions << " predictions!" << endl;
				cout << " -------------------------------------------------" << endl;
			}
		} while (AI_RandomAttemptToLocateTarget != actualTargetLocation);

		//Scores
		cout << "\n Now that all the drones have found the Target," << endl;
		cout << " To see who won" << endl;
		system("Pause");

		cout << "\n -------------------------------------------------" << endl;
		cout << " The Human found the target in " << Human_NumberOfPredictions << " predictions!" << endl;
		cout << " The Binary AI found the target in " << AI_BinaryNumberOfPredictions << " predictions!" << endl;
		cout << " The Linear AI found the target in " << AI_LinearNumberOfPredictions << " predictions!" << endl;
		cout << " The Random AI found the target in " << AI_RandomNumberOfPredictions << " predictions!" << endl;
		cout << " -------------------------------------------------" << endl;
		cout << "\n Would you like to play again? Y/N?" << endl;
		cin >> retry;

	} while (retry == 'Y' || retry == 'y');

	return 0;
}