#include <iostream>
#include <vector>
#include <fstream>
#include <limits> 
#include "Person.h"
#include "Course.h"

using namespace std;

class SystemManager {
private:
    vector<Person*> users;
    vector<Course> courses;

public:
    SystemManager() {
        courses.push_back(Course("CST209", "OOP C++", 4));
    }

    ~SystemManager() {
        for (auto p : users) delete p;
        users.clear();
    }

    void saveData() {
        ofstream outFile("university_data.txt");
        if (outFile.is_open()) {
            for (const auto& p : users) {
                outFile << p->getDataString() << endl;
            }
            outFile.close();
            cout << "   -> Data saved to file." << endl;
        }
    }

    Person* findUser(string id) {
        for (auto p : users) {
            if (p->getId() == id) return p;
        }
        return nullptr;
    }

    Course* findCourse(string code) {
        for (auto& c : courses) {
            if (c.getCode() == code) return &c;
        }
        return nullptr;
    }

    static void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void run() {
        int choice = -1;
        while (choice != 0) {
            // UI Header - Strictly matching the image
            cout << "\n==============================================" << endl;
            cout << "      UNIVERSITY MANAGEMENT SYSTEM MENU" << endl;
            cout << "==============================================" << endl;
            cout << "1. Add New Student" << endl;
            cout << "2. Add New Lecturer" << endl;
            cout << "3. Add New Course" << endl;
            cout << "4. Enroll Student in Course" << endl;
            cout << "5. View All Students" << endl;
            cout << "6. View All Lecturers" << endl;
            cout << "7. View All Courses" << endl;
            cout << "0. Exit System" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "Enter choice: ";

            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number." << endl;
                clearInput();
                continue;
            }

            if (choice == 1) {
                cout << "\n--- Add New Student ---" << endl;
                string id, name, major;
                cout << "Enter Student ID: "; cin >> id;
                cin.ignore(); 
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Major: "; getline(cin, major);
                
                users.push_back(new Student(name, id, major));
                cout << "Success: Student added." << endl;
            }
            else if (choice == 2) {
                cout << "\n--- Add New Lecturer ---" << endl;
                string id, name, dept;
                cout << "Enter Lecturer ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Department: "; getline(cin, dept);

                users.push_back(new Lecturer(name, id, dept));
                cout << "Success: Lecturer added." << endl;
            }
            else if (choice == 3) {
                cout << "\n--- Add New Course ---" << endl;
                string code, title;
                int credit;
                cout << "Enter Course Code: "; cin >> code;
                cin.ignore();
                cout << "Enter Course Title: "; getline(cin, title);
                cout << "Enter Credit Hours: "; cin >> credit;

                courses.push_back(Course(code, title, credit));
                cout << "Success: Course added." << endl;
            }
            else if (choice == 4) {
                cout << "\n--- Enroll Student in Course ---" << endl;
                string sid, ccode;
                cout << "Enter Student ID: "; cin >> sid;
                cout << "Enter Course Code: "; cin >> ccode;

                Person* p = findUser(sid);
                Course* c = findCourse(ccode);

                if (p && c) {
                    Student* s = dynamic_cast<Student*>(p);
                    if (s) {
                        s->enrollCourse(*c);
                    } else {
                        cout << "Error: ID belongs to a Lecturer, not a Student." << endl;
                    }
                } else {
                    cout << "Error: Invalid Student ID or Course Code." << endl;
                }
            }
            else if (choice == 5) {
                cout << "\n--- All Students List ---" << endl;
                bool found = false;
                for (const auto& p : users) {
                    if (p->getUserType() == "Student") {
                        p->displayRole();
                        found = true;
                    }
                }
                if (!found) cout << "No students found." << endl;
            }
            else if (choice == 6) {
                cout << "\n--- All Lecturers List ---" << endl;
                bool found = false;
                for (const auto& p : users) {
                    if (p->getUserType() == "Lecturer") {
                        p->displayRole();
                        found = true;
                    }
                }
                if (!found) cout << "No lecturers found." << endl;
            }
            else if (choice == 7) {
                cout << "\n--- All Courses List ---" << endl;
                if (courses.empty()) {
                    cout << "No courses available." << endl;
                } else {
                    for (const auto& c : courses) {
                        c.displayCourse();
                    }
                }
            }
            else if (choice == 0) {
                saveData();
                cout << "Exiting system. Goodbye!" << endl;
            }
            else {
                cout << "Invalid choice." << endl;
            }
        }
    }
};

int main() {
    SystemManager app;
    app.run();
    return 0;
}