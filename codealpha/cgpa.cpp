
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double grade, credits;
    double totalCredits = 0;
    double totalGradePoints = 0;

    cout << "Enter the number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of courses!";
        return 0;
    }

    vector<double> grades(n);
    vector<double> creditHours(n);

    // Input grades and credit hours
    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade points: ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        if (grades[i] < 0 || creditHours[i] <= 0) {
            cout << "Invalid grade or credit hours!";
            return 0;
        }

        totalCredits += creditHours[i];
        totalGradePoints += grades[i] * creditHours[i];
    }

    // Calculate semester GPA
    double gpa = totalGradePoints / totalCredits;

    // Display course details
    cout << "\n----- Course Details -----\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << creditHours[i]
             << " | Grade Points: "
             << grades[i] * creditHours[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nSemester GPA: " << gpa << endl;

    // For a single semester, CGPA equals GPA
    cout << "Overall CGPA: " << gpa << endl;

    return 0;
}
