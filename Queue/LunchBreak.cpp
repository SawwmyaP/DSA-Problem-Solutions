// LunchBreak Problem.cpp
#include <bits/stdc++.h>
using namespace std;

int countStudentsUnableToEat(vector<int>& students, vector<int>& sandwiches) {
    int preferCircular = 0;
    int preferSquare = 0;

    for (int choice : students) {
        if (choice == 0)
            preferCircular++;
        else
            preferSquare++;
    }
    for (int sandwich : sandwiches) {

        if (sandwich == 0) {
            if (preferCircular == 0)
                break; 
            preferCircular--;
        } else {
            if (preferSquare == 0)
                break;
            preferSquare--;
        }
    }
    return preferCircular + preferSquare;
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    int result = countStudentsUnableToEat(students, sandwiches);
    cout << "Students unable to eat: " << result << endl;

    return 0;
}
