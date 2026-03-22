# University-Management-System
A C++ console application for university management utilizing OOP, STL, and File I/O.

## Overview
A lightweight, console-based University Management System developed in C++. This project demonstrates core concepts of Object-Oriented Programming (OOP), dynamic memory management, and data persistence.

## Core Technical Features
* **Object-Oriented Design**: Built with a clear class hierarchy. [cite_start]Utilizes **Inheritance** (an abstract `Person` base class extended by `Student` and `Lecturer`) and **Runtime Polymorphism** for flexible user management[cite: 61, 65].
* [cite_start]**Standard Template Library (STL)**: Heavily relies on `std::vector` for dynamic array management (handling unpredictable numbers of user objects) and `std::string` for robust text manipulation[cite: 53, 54, 55, 58].
* [cite_start]**Data Persistence (File I/O)**: Implements `ofstream` to ensure all registered user data is automatically saved to a text file (`university_data.txt`) upon system exit, preventing data loss[cite: 74, 75].
* [cite_start]**Robust Input Validation**: Includes static utility functions to handle `cin` buffer clearing and input validation, preventing system crashes during erroneous user inputs[cite: 71, 76, 77].

## System Functionality
[cite_start]The system features an interactive console menu supporting the following operations[cite: 104]:
1. Add New Student / Lecturer / Course
2. Enroll Student in Course
3. View All Registered Students and Lecturers
4. View All Available Courses
5. Automatically save data upon exit

## How to Compile and Run
Ensure you have a C++ compiler (like `g++`) installed. Run the following command in your terminal:

```bash
g++ main.cpp Person.cpp Course.cpp -o ums
./ums
