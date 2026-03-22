#include "Person.h"
#include <iostream>
#include <iomanip>

// --- Person ---
Person::Person(string n, string i) : name(n), id(i) {}
string Person::getName() const { return name; }
string Person::getId() const { return id; }

// --- Student ---
Student::Student(string n, string i, string m) : Person(n, i), major(m) {}

void Student::enrollCourse(Course c) {
    enrollments.push_back(GradedEnrollment(c));
    cout << "   -> Success: Enrolled in " << c.getTitle() << endl;
}

void Student::setGrade(string code, string g) {
    bool found = false;
    for (auto& rec : enrollments) {
        if (rec.getCourse().getCode() == code) {
            rec.setGrade(g);
            found = true;
            cout << "   -> Grade updated to " << g << endl;
            break;
        }
    }
    if (!found) cout << "   -> Error: Course not found." << endl;
}

double Student::calculateGPA() const {
    double totalPoints = 0;
    int totalCredits = 0;
    for (const auto& rec : enrollments) {
        if (rec.getGrade() != "N/A") {
            totalPoints += (rec.getGradePoint() * rec.getCourse().getCredits());
            totalCredits += rec.getCourse().getCredits();
        }
    }
    return (totalCredits == 0) ? 0.0 : (totalPoints / totalCredits);
}

void Student::displayRole() const {
    cout << left << setw(12) << id 
         << setw(15) << name 
         << setw(15) << major 
         << "GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
}

string Student::getDataString() const {
    return "Student," + id + "," + name + "," + major;
}

// --- Lecturer ---
Lecturer::Lecturer(string n, string i, string dept) 
    : Person(n, i), department(dept), assignedCourseCode("None") {}

void Lecturer::assignCourse(string code) {
    assignedCourseCode = code;
    cout << "   -> Assigned to " << code << endl;
}

void Lecturer::displayRole() const {
    cout << left << setw(12) << id 
         << setw(15) << name 
         << setw(15) << department 
         << "Course: " << assignedCourseCode << endl;
}

string Lecturer::getDataString() const {
    return "Lecturer," + id + "," + name + "," + department + "," + assignedCourseCode;
}