/*Application: When playing card games, players often use an approach similar to insertion 	sort to  organize their cards. They pick one card at a time and insert it into the correct 		position in their hand, maintaining a sorted sequence. Write a program that demonstrates 		how to organize (sort) cards in a hand using insertion sort.*/

#include <iostream>

using namespace std;

int main () {
	int cards[5];
	int j,  key;
	
	// Input
	cout << "Enter the cards you have in terms of their numeric value: " << endl;
	for (int i=0; i < 5; i++) {
		cin >> cards[i];
	} 
	
	// Sorting
	for (int pass=1; pass < 6; pass++) {
		key = cards[pass];
		j = pass - 1;
		while (j>=0 && key < cards[j]) {
			cards[j+1]=cards[j];
			j--;
		}
		cards[j+1] = key;
		cout << "\nCurrent order of cards: ";
		for (int i=0; i < 5; i++) {
			cout << cards[i] << ", ";
		}
		cout << endl;
		}
	
	//Displaying sorted card values
	cout << "\nSorted cards: ";
	for (int i=0; i < 5; i++) {
		cout << cards[i] << ", ";
	}
	cout << endl;
	
	return 0;
}
