#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    string grade;
};

int main() {
    vector<Student> students;
    int numStudents;

    cout << "Enter the total number of students: ";
    cin >> numStudents;
    cin.ignore();

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        cout << "Enter the name of student " << i + 1 << ": ";
        getline(cin, student.name);
        cout << "Enter the grade of student " << i + 1 << ": ";
        getline(cin, student.grade);
        students.push_back(student);
    }

    // Calculate the average grade
    double sumGrades = 0.0;
    string highestGrade = "A";
    string lowestGrade = "D";
    for (const auto& student : students) {
        sumGrades += student.grade[0]; // Add ASCII value for average calculation

        highestGrade = (student.grade < highestGrade) ? student.grade : highestGrade;
        lowestGrade = (student.grade > lowestGrade) ? student.grade : lowestGrade;
    }
    double averageGrade = sumGrades / numStudents;

    // Display results
    cout << "\nStudent Grades Summary:\n";
    for (const auto& student : students) {
        cout << student.name << ": " << student.grade << endl;
    }

    cout << "\nAverage Grade: " << static_cast<char>(averageGrade) << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}
