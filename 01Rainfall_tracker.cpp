Problem Statement - 1

/*Write a program to track rainfall data for 3 cities over 4 months. Using a 2D array, we can store the data, calculate the average rainfall for each city, and display the rainfall data in a tabular format*/

#include <iostream>

using namespace std;

int main() {
    float rainfall[3][4];
    float total_rain[3];
    float average_rainfall[3];
    printf("Input rainfall of 3 cities below:\n");
    for (int i=0; i < 3; i++) {
        int a = i+1;
        printf("Enter data for city %d:\n", a);
        for (int j=0; j < 4; j++) {
            int b = j+1;
            printf("Enter rainfall for month %d: ", b);
            scanf("%f", &rainfall[i][j]);
        }
    }

    for (int e=0; e < 3; e++) {
        total_rain[e] = rainfall[e][0] + rainfall[e][1] + rainfall[e][2] + rainfall[e][3];
        average_rainfall[e] = total_rain[e]/4;
    }

    printf("City            Month 1            Month 2             Month 3            Month 4             total             Average\n");
    for (int c=0; c < 3; c++) {
        int d = c+1;
        printf("City %d          %f          %f          %f          %f          %f          %f\n", d, rainfall[c][0], rainfall[c][1], rainfall[c][2], rainfall[c][3], total_rain[c], average_rainfall[c]);
    }

    return 0;
}
