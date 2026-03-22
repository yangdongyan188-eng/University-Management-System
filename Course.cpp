#include "Course.h"
#include <iomanip>

// --- Course ---
Course::Course(string code, string t, int credits) 
    : courseCode(code), title(t), creditHours(credits) {}

Course::Course(string code, string t) 
    : courseCode(code), title(t), creditHours(3) {}

string Course::getCode() const { return courseCode; }
string Course::getTitle() const { return title; }
int Course::getCredits() const { return creditHours; }

void Course::displayCourse() const {
    cout << "Code: " << left << setw(10) << courseCode 
         << " Title: " << setw(20) << title 
         << " Credits: " << creditHours << endl;
}

// --- GradedEnrollment ---
GradedEnrollment::GradedEnrollment(Course c) : course(c), grade("N/A") {}

void GradedEnrollment::setGrade(string g) { grade = g; }
string GradedEnrollment::getGrade() const { return grade; }
Course GradedEnrollment::getCourse() const { return course; }

double GradedEnrollment::getGradePoint() const {
    if (grade == "A") return 4.0;
    if (grade == "A-") return 3.7;
    if (grade == "B+") return 3.3;
    if (grade == "B") return 3.0;
    if (grade == "B-") return 2.7;
    if (grade == "C+") return 2.3;
    if (grade == "C") return 2.0;
    if (grade == "F") return 0.0;
    return 0.0;
}