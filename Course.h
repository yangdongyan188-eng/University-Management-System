#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

using namespace std;

class Course {
private:
    string courseCode;
    string title;
    int creditHours;

public:
    Course(string code, string t, int credits);
    Course(string code, string t); 

    string getCode() const;
    string getTitle() const;
    int getCredits() const;
    void displayCourse() const; 
};

class GradedEnrollment {
private:
    Course course;
    string grade;

public:
    GradedEnrollment(Course c);
    void setGrade(string g);
    string getGrade() const;
    Course getCourse() const;
    double getGradePoint() const; 
};

#endif