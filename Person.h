#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Person {
protected:
    string name;
    string id;

public:
    Person(string n, string i);
    virtual ~Person() {} 

    string getName() const;
    string getId() const;

    virtual void displayRole() const = 0; 
    virtual string getDataString() const = 0;
    
    // View All Students vs Lecturers
    virtual string getUserType() const = 0; 
};

class Student : public Person {
private:
    string major;
    vector<GradedEnrollment> enrollments;

public:
    Student(string n, string i, string m);

    void enrollCourse(Course c);
    void setGrade(string code, string grade);
    double calculateGPA() const;

    void displayRole() const override;
    string getDataString() const override;
    string getUserType() const override { return "Student"; }
};

class Lecturer : public Person {
private:
    string department;
    string assignedCourseCode;

public:
    Lecturer(string n, string i, string dept);

    void assignCourse(string code);

    void displayRole() const override;
    string getDataString() const override;
    string getUserType() const override { return "Lecturer"; }
};

#endif