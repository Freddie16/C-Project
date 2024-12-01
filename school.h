#ifndef SCHOOL_H
#define SCHOOL_H

#include "student.h"
#include "course.h"

class School {
private:
    Student* students;
    Course* courses;
    int numStudents;
    int numCourses;

public:
    School(); // Constructor
    ~School(); // Destructor

    void loadStudents(const std::string& filename);
    void loadCourses(const std::string& filename);
    void processRegistrations();
    void displayAllData() const;
};

#endif
