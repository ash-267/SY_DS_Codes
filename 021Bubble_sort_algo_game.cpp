/*write a game development program that implements the Bubble Sort algorithm. The program 	will simulate a simple game where the player can input a set of numbers, and the numbers 	will be sorted using Bubble Sort to simulate a "level-up" scenario where the player's scores 	are sorted in ascending order.*/

#include <iostream>

using namespace std;

int main () {
	int player1[5];
	int player2[5];
	int a;
	
	// Input
	cout << "Enter the scores for Player 1: " << endl;
	for (int i=0; i < 5; i++) {
		cin >> player1[i];
	} 
	cout << "\n\nEnter scores of player 2: " << endl;
	for (int i=0; i < 5; i++) {
		cin >> player2[i];
	}
	
	// Sorting
	for (int pass=0; pass < 5; pass++) {
		for (int i=0; i < (5-pass-1); i++) {
			if (player1[i] < player1[i+1]) {
				a = player1[i];
				player1[i] = player1[i+1];
				player1[i+1] = a;
			}
		}
	}
	
	for (int pass=0; pass < 5; pass++) {
		for (int i=0; i < (5-pass-1); i++) {
			if (player2[i] < player2[i+1]) {
				a = player2[i];
				player2[i] = player2[i+1];
				player2[i+1] = a;
			}
		}
	}
	
	cout << "Swapping scores and leveling up!!!" << endl;
	cout << "Scores have been swapped!" << endl;
	cout << "The scores are: " << endl;
	
	//Displaying scores 
	cout << "The sorted scores are: " << endl;
	cout << "Scores of Player 1: ";
	for (int i=0; i < 5; i++) {
		cout << player1[i] << ", ";
	}
	cout << endl;
	cout << "Scores of Player 2: ";
	for (int i=0; i < 5; i++) {
		cout << player2[i] << ", ";
	}
	cout << endl;
	
	if (player1[0] > player2[0]) {
		cout << "Player 1 is the winner!" << endl;
	} else if (player2[0] > player1[0]) {
		cout << "Player 2 is the winner!" << endl;
	} else {
		cout << "Its a tie!" << endl;
	}
		
	return 0;
}
