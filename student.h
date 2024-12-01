#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string lastName;
    std::string firstName;
    std::string studentID;
    std::string* schedule; // Dynamically allocated
    int maxCourses;
    int currentCourses;
    int creditHours;

public:
    Student(); // Default Constructor
    Student(const std::string& lastName, const std::string& firstName, const std::string& studentID, int maxCourses = 10);
    ~Student(); // Destructor
    Student(const Student& other); // Copy Constructor
    Student& operator=(const Student& other); // Copy Assignment Operator

    void addCourse(const std::string& courseName, int courseCredits);
    std::string getFullName() const;
    std::string getID() const;
    int getCreditHours() const;
    const std::string* getSchedule() const;
    int getCurrentCourses() const;
    bool hasSchedule() const;
};

#endif
