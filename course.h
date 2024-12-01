#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    std::string courseName;
    int creditHours;
    int maxEnrollment;
    int currentEnrollment;
    std::string* roster; // Dynamically allocated

public:
    Course(); // Default Constructor
    Course(const std::string& courseName, int creditHours, int maxEnrollment);
    ~Course(); // Destructor
    Course(const Course& other); // Copy Constructor
    Course& operator=(const Course& other); // Copy Assignment Operator

    bool addStudent(const std::string& studentName);
    bool isFull() const;

    std::string getName() const;
    int getCreditHours() const;
    int getMaxEnrollment() const;
    int getCurrentEnrollment() const;
    const std::string* getRoster() const;
};

#endif
