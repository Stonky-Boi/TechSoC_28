#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void register_user()
{
    string ID, password, role;
    cout << "Enter User ID: ";
    cin >> ID;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Role (admin/student): ";
    cin >> role;

    ofstream users_file("Task_2_Users.txt", ios::app);
    if (users_file.is_open())
    {
        users_file << ID << " " << password << " " << role << endl;
        cout << "User registered successfully!" << endl;
    }
    else
        cout << "Error opening user file." << endl;
    users_file.close();
}

bool login_user(string &ID, string &role)
{
    string password, file_ID, file_password, file_role;
    cout << "Enter User ID: ";
    cin >> ID;
    cout << "Enter Password: ";
    cin >> password;

    ifstream users_file("Task_2_Users.txt");
    if (users_file.is_open())
    {
        while (users_file >> file_ID >> file_password >> file_role)
        {
            if (file_ID == ID && file_password == password)
            {
                role = file_role;
                users_file.close();
                return true;
            }
        }
        users_file.close();
    }
    cout << "Invalid credentials." << endl;
    return false;
}

void add_grades()
{
    string ID, semester, course_code, grade;
    cout << "Enter Student ID: ";
    cin >> ID;
    cout << "Enter Semester (e.g., semester_1): ";
    cin >> semester;

    ofstream grades_file("Task_2_Grades.txt", ios::app);
    if (grades_file.is_open())
    {
        grades_file << ID << endl;
        grades_file << semester << endl;
        int number_courses;
        cout << "Enter number of courses: " << endl;
        cin >> number_courses;
        cin.ignore();
        for (int i = 0; i < number_courses; i++)
        {
            cout << "Enter Course Code: " << endl;
            getline(cin, course_code);
            cout << "Enter Grade: " << endl;
            getline(cin, grade);
            grades_file << course_code << " " << grade << endl;
        }
        grades_file << "END" << endl;
        cout << "Grades added successfully!" << endl;
    }
    else
        cout << "Error opening grades file." << endl;
    grades_file.close();
}

float calculate_SPI(const vector<pair<string, int>> grades)
{
    int total_credits = grades.size() * 4;
    int total_points = 0;
    for (int i = 0; i < grades.size(); i++)
        total_points += grades[i].second * 4;
    return static_cast<float>(total_points) / total_credits;
}

float calculate_CPI(const vector<vector<pair<string, int>>> all_semester_grades)
{
    int total_credits = 0, total_points = 0;
    for (int i = 0; i < all_semester_grades.size(); i++)
    {
        total_credits += all_semester_grades[i].size() * 4;
        for (int j = 0; j < all_semester_grades[i].size(); j++)
            total_points += all_semester_grades[i][j].second * 4;
    }
    return static_cast<float>(total_points) / total_credits;
}

void view_grades()
{
    string ID, semester, course_code, grade;
    cout << "Enter your Student ID: ";
    cin >> ID;

    ifstream grades_file("Task_2_Grades.txt");
    if (grades_file.is_open())
    {
        bool found = false;
        vector<vector<pair<string, int>>> all_semester_grades;
        while (grades_file >> semester)
        {
            if (semester == ID)
            {
                found = true;
                vector<pair<string, int>> semester_grades;
                while (grades_file >> course_code >> grade && grade != "END")
                {
                    int grade_value = -1;
                    if (grade == "AP" || grade == "AA")
                        grade_value = 10;
                    else if (grade == "AB")
                        grade_value = 9;
                    else if (grade == "BB")
                        grade_value = 8;
                    else if (grade == "BC")
                        grade_value = 7;
                    else if (grade == "CC")
                        grade_value = 6;
                    else if (grade == "CD")
                        grade_value = 5;
                    else if (grade == "DD")
                        grade_value = 4;
                    else if (grade == "FR" || grade == "FF")
                        grade_value = 0;
                    else if (grade == "PP" || grade == "AU" || grade == "SS")
                        grade_value = 0;
                    else if (grade == "NP" || grade == "US")
                        grade_value = 0;
                    semester_grades.push_back(make_pair(course_code, grade_value));
                }
                all_semester_grades.push_back(semester_grades);
            }
        }
        if (!found)
            cout << "No grades found for this student." << endl;
        else
        {
            for (int i = 0; i < all_semester_grades.size(); i++)
            {
                cout << "Semester " << i + 1 << ":" << endl;
                for (int j = 0; j < all_semester_grades[i].size(); j++)
                    cout << all_semester_grades[i][j].first << ": " << all_semester_grades[i][j].second << endl;
                cout << "SPI: " << calculate_SPI(all_semester_grades[i]) << endl;
            }
            cout << "CPI: " << calculate_CPI(all_semester_grades) << endl;
        }
    }
    else
        cout << "Error opening grades file." << endl;
    grades_file.close();
}

int main()
{
    int choice;
    string ID, role;
    while (true)
    {
        cout << "--- Academic Roll Record System ---" << endl
             << "1. Register" << endl
             << "2. Login" << endl
             << "3. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            register_user();
            break;
        case 2:
            if (login_user(ID, role))
            {
                if (role == "admin")
                {
                    int admin_choice;
                    cout << "Welcome, Admin " << ID << "!" << endl
                         << "1. Add/Update Grades" << endl
                         << "2. Logout" << endl
                         << "Enter your choice: ";
                    cin >> admin_choice;
                    if (admin_choice == 1)
                        add_grades();
                }
                else if (role == "student")
                {
                    cout << "Welcome, Student " << ID << "!" << endl;
                    view_grades();
                }
            }
            break;
        case 3:
            cout << "Exiting the system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}
