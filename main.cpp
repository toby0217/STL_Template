#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string id;
    string name;
    int score;
};

void AddStudent(map<string, Student>& STL)
{
    string stuId;
    cout << "Student Number(ID): ";
    cin >> stuId;

    if (STL.find(stuId) != STL.end()) {
        cout << "Error: The Student Number already exists." << endl;
        return;
    }
    
    Student stu;
    stu.id = stuId;
    cout << "Student Name: ";
    cin >> stu.name;
    cout << "Score: ";
    cin >> stu.score;
    STL[stuId] = stu;
}

void OutputList(const map<string, Student>& STL)
{
    if (STL.empty()) {
        cout << "No student data available, failed to perform." << endl;
        return;
    }

    cout << "\n--- Students List ---" << endl;
    cout << "---------------------------------------" << endl;
    cout << "ID\t\tName\t\tScore" << endl;
    cout << "---------------------------------------" << endl;

    for (const auto& pair : STL) {
        cout << pair.second.id << "\t"
             << pair.second.name << "\t\t"
             << pair.second.score << endl;
    }
    cout << "---------------------------------------" << endl;
}

void SortByScore(map<string, Student>& STL, vector<Student>& students)
{
    if (STL.empty()) {
        cout << "No student data available, failed to perform." << endl;
        return;
    }

    students.clear();
    for (const auto& pair : STL) {
        students.push_back(pair.second);
    }
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });
}

void ShowScoreSort(map<string, Student>& STL, vector<Student>& students)
{
    if (STL.empty()) {
        return;
    }

    cout << "\n--- Score Sorted Students List ---" << endl;
    cout << "---------------------------------------" << endl;
    cout << "ID\t\tName\t\tScore" << endl;
    cout << "---------------------------------------" << endl;

    for (size_t i = 0; i < students.size(); i++) {
        cout << students[i].id << "\t"
             << students[i].name << "\t\t"
             << students[i].score << endl;
    }
    cout << "---------------------------------------" << endl;
}

void IdSearch(map<string, Student>& STL)
{
    cout << "To be developed..." << endl;
}

void ShowStatistics(map<string, Student>& STL)
{
    cout << "To be developed..." << endl;
}

int
main()
{
    map<string, Student> STL; //Use map to store the students data.
    vector<Student> ScoreSortedSTL;
    int choice;
    do
    {
        cout << "\n===============================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. List all students" << endl;
        cout << "3. Sort by score" << endl;
        cout << "4. Search by id" << endl;
        cout << "5. Show statistics" << endl;
        cout << "0. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter the number of the function you want to perform: ";
        cin >> choice; //Input the number to run the function.

        switch (choice) {
            case 1:
                AddStudent(STL);
                break;
            case 2:
                OutputList(STL);
                break;
            case 3:
                SortByScore(STL, ScoreSortedSTL);
                cout << "Sort Complete!!!\n";
                ShowScoreSort(STL, ScoreSortedSTL);
                break;
            case 4:
                IdSearch(STL);
                break;
            case 5:
                ShowStatistics(STL);
                break;
            case 0:
                cout << "System closing..." << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        } //Run the function represented by the number.
    } while (choice != 0);

    return 0;
}