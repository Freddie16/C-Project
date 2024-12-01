#include "school.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "utils.h" // For utility functions like split_string

// Constructor
School::School() : students(nullptr), courses(nullptr), numStudents(0), numCourses(0) {}

// Destructor
School::~School() {
    delete[] students;
    delete[] courses;
}

void School::loadStudents(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string lastName, firstName, studentID;

        std::getline(ss, lastName, ',');
        std::getline(ss, firstName, ',');
        std::getline(ss, studentID, ',');

        // Resize student array if needed
        if (numStudents % 10 == 0) {
            Student* newStudents = new Student[numStudents + 10];
            for (int i = 0; i < numStudents; ++i) {
                newStudents[i] = students[i];
            }
            delete[] students;
            students = newStudents;
        }

        // Add the new student
        students[numStudents++] = Student(lastName, firstName, studentID);
    }
}

void School::loadCourses(const std::string& filename) {
    std::ifstream file(filename);
    std::string courseName;
    int creditHours, maxEnrollment;

    while (file >> courseName >> creditHours >> maxEnrollment) {
        // Resize course array if needed
        if (numCourses % 10 == 0) {
            Course* newCourses = new Course[numCourses + 10];
            for (int i = 0; i < numCourses; ++i) {
                newCourses[i] = courses[i];
            }
            delete[] courses;
            courses = newCourses;
        }

        // Add the new course
        courses[numCourses++] = Course(courseName, creditHours, maxEnrollment);
    }
}

void School::processRegistrations() {
    // Process student registrations
    for (int i = 0; i < numStudents; ++i) {
        for (int j = 0; j < numCourses; ++j) {
            if (courses[j].getName() == "COL101" && !courses[j].isFull()) {
                if (courses[j].addStudent(students[i].getFullName())) {
                    students[i].addCourse(courses[j].getName(), courses[j].getCreditHours());
                }
                break;
            }
        }
    }

    // Sort students alphabetically by last name
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = i + 1; j < numStudents; ++j) {
            if (students[i].getFullName() > students[j].getFullName()) {
                std::swap(students[i], students[j]);
            }
        }
    }
}

void School::displayAllData() const {
    // Display all courses before scheduling
    std::cout << "All Courses - Before Scheduling\n";
    std::cout << "course Name:credit hours:enrollment:max\n";
    std::cout << "========================================\n";
    for (int i = 0; i < numCourses; ++i) {
        std::cout << courses[i].getName() << ":" << courses[i].getCreditHours() << ":"
                  << courses[i].getCurrentEnrollment() << ":" << courses[i].getMaxEnrollment() << "\n";
    }

    // Display all students before scheduling
    std::cout << "\nAll Students - Before Scheduling\n";
    std::cout << "last Name, First Name:Student ID:Hours\n";
    std::cout << "========================================\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << students[i].getFullName() << ":" << students[i].getID() << ":"
                  << students[i].getCreditHours() << "\n";
    }

    // Display course rosters after processing
    std::cout << "\nAll Course Rosters\n";
    for (int i = 0; i < numCourses; ++i) {
        std::cout << "Course Roster: " << courses[i].getName() << "\n";
        std::cout << "========================================\n";

        const std::string* roster = courses[i].getRoster();
        int enrolled = courses[i].getCurrentEnrollment();

        if (enrolled == 0) {
            std::cout << "No students registered\n";
        } else {
            std::string* sortedRoster = new std::string[enrolled];
            for (int j = 0; j < enrolled; ++j) {
                sortedRoster[j] = roster[j];
            }

            // Sort roster
            for (int j = 0; j < enrolled - 1; ++j) {
                for (int k = j + 1; k < enrolled; ++k) {
                    if (sortedRoster[j] > sortedRoster[k]) {
                        std::swap(sortedRoster[j], sortedRoster[k]);
                    }
                }
            }

            // Display sorted roster
            for (int j = 0; j < enrolled; ++j) {
                std::cout << j + 1 << ". " << sortedRoster[j] << "\n";
            }

            delete[] sortedRoster;
        }
    }

    // Display all student schedules after processing
    std::cout << "\nAll Student Schedules\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << students[i].getFullName() << "'s Schedule\n";
        std::cout << "ID: " << students[i].getID() << "\n";
        std::cout << "Hours: " << students[i].getCreditHours() << "\n";
        std::cout << "========================================\n";

        const std::string* schedule = students[i].getSchedule();
        int courses = students[i].getCurrentCourses();
        if (courses == 0) {
            std::cout << "No Schedule\n";
        } else {
            for (int j = 0; j < courses; ++j) {
                std::cout << schedule[j] << "\n";
            }
        }
    }

    // Display all students after scheduling
    std::cout << "All Students - After Scheduling\n";
    std::cout << "last Name, First Name:Student ID:Hours\n";
    std::cout << "========================================\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << students[i].getFullName() << ":" << students[i].getID() << ":"
                  << students[i].getCreditHours() << "\n";
    }

    // Display all courses after scheduling
    std::cout << "\nAll Courses - After Scheduling\n";
    std::cout << "course Name:credit hours:enrollment:max\n";
    std::cout << "========================================\n";
    for (int i = 0; i < numCourses; ++i) {
        std::cout << courses[i].getName() << ":" << courses[i].getCreditHours() << ":"
                  << courses[i].getCurrentEnrollment() << ":" << courses[i].getMaxEnrollment() << "\n";
    }
}
