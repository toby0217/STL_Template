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

#define FULL_MARK 100 //Initialize the Full Mark to 100 points.

void AddStudent(map<string, Student>& STL)
{
    //1.Read the ID.
    string stuId;
    cout << "Student Number(ID): ";
    cin >> stuId;

    //2.If the ID already exists, refuse to store and print error.
    if (STL.find(stuId) != STL.end()) {
        cout << "Error: The Student Number already exists." << endl;
        return;
    }
    
    //3.Read the student data, the Student object will be created in STL[ID].
    //add the score check
    Student stu;
    stu.id = stuId;
    cout << "Student Name: ";
    cin >> stu.name;
    cout << "Score: ";
    cin >> stu.score;
    while (stu.score < 0 || stu.score > FULL_MARK) {
        cout << "Error score, please enter a vaild score again." << endl;
        cout << "Score: ";
        cin >> stu.score;
    }
    STL[stuId] = stu;
}

void OutputList(const map<string, Student>& STL)
{
    //1.Empty check
    if (STL.empty()) {
        cout << "No student data available, failed to perform." << endl;
        return;
    }

    //2.Print the students data which is sorted by ID.
    cout << "Loading..." << endl;
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
    //1.Empty check
    if (STL.empty()) {
        cout << "No student data available, failed to perform." << endl;
        return;
    }

    //2.Fill the vector, and use "sort" to sort the vector.
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
    //1.Empty check
    if (STL.empty()) {
        return;
    }

    //2.Print the students data which is sorted by score.
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
    //1.Empty check
    if (STL.empty()) {
        cout << "No student data available, failed to perform." << endl;
        return;
    }
    
    //2.Input ID
    string searchId;
    cout << "Enter the ID to search: ";
    cin >> searchId;

    //3.Search whether the ID exist, and output the student's data.
    auto it = STL.find(searchId);
    if (it == STL.end()) {
        cout << "Cannot find this ID." << endl;
    }
    else {
        cout << "Name: " << it->second.name << endl;
        cout << "Score: " << it->second.score << endl;
    }
}

void ShowStatistics(map<string, Student>& STL)
{
    //1.Empty check
    if (STL.empty()) {
        cout << "No student data available, failed to perform." << endl;
        return;
    }

    //2.Evaluate the sum and number of passed/not passed students, and find the maximum and minimum.
    int totalScore = 0;
    int passed = 0;
    int notPassed = 0;
    int maxScore = -1;
    int minScore = FULL_MARK + 1;

    for (const auto& pair : STL) {
        int s = pair.second.score;
        totalScore += s;

        if (s >= 60) {
            passed++;
        }
        else {
            notPassed++;
        }
        
        if (s > maxScore) {
            maxScore = s;
        }
        if (s < minScore) {
            minScore = s;
        }
    }

    //3.Output the result.
    cout << "\n--- Statistics ---" << endl;
    cout << "Average: " << 1.0 * totalScore / STL.size() << endl;
    cout << "Max: " << maxScore << endl;
    cout << "Min: " << minScore << endl;
    cout << "Passed: " << passed << endl;
    cout << "Not Passed: " << notPassed << endl;
}

int
main()
{
    map<string, Student> STL; //Use map to store the students data.
    vector<Student> ScoreSortedSTL; //Use vector to sort the data by score.
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