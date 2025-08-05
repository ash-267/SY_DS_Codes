/*Write a program for Tracking daily temperatures of 3 cities for a week . The program calculates the average temperature for each day and for the week.*/

#include <iostream>

using namespace std;

int main() {
    float temp[3][7];
    float total_temp[3];
    float avg_temp[3];
    cout << "Input rainfall of 3 cities below: " << endl;
    for (int i=0; i < 3; i++) {
        int a = i+1;
        cout << "Enter data for city " << a << endl;
        for (int j=0; j < 7; j++) {
            int b = j+1;
            cout << "Enter temperature in deg celcius for day " << b << ": ";
            cin >> temp[i][j];
        }
    }

    for (int e=0; e < 3; e++) {
        total_temp[e] = temp[e][0] + temp[e][1] + temp[e][2] + temp[e][3] + temp[e][4] + temp[e][5] + temp[e][6] + temp[e][7];
        avg_temp[e] = total_temp[e]/7;
    }
	
	cout << "\nGiven below is temperature of 3 cities in degrees celcius: " << endl;
    cout << "City            day 1\t\t day 2\t\t day 3\t\t day 4\t\t day 5\t\t day 6\t\t day 7\t\t Average\n";
    cout << "==============================================================================================================================================" << endl;
    for (int c=0; c < 3; c++) {
        int d = c+1;
        cout << "City "  << d << "\t|\t" << temp[c][0] << "\t|\t" << temp[c][1] << "\t|\t" << temp[c][2] << "\t|\t" << temp[c][3] << "\t|\t" << temp[c][4] << "\t|\t" << temp[c][5] << "\t|\t" << temp[c][6] << "\t|\t" << avg_temp[c] << endl;
    }
    cout << "==============================================================================================================================================" << endl;

    return 0;
}
