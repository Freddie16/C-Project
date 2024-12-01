#include "student.h"
#include <algorithm>

// Default Constructor
Student::Student()
    : lastName(""), firstName(""), studentID(""), maxCourses(10), currentCourses(0), creditHours(0) {
    schedule = new std::string[maxCourses];
}

// Parameterized Constructor
Student::Student(const std::string& lastName, const std::string& firstName, const std::string& studentID, int maxCourses)
    : lastName(lastName), firstName(firstName), studentID(studentID), maxCourses(maxCourses), currentCourses(0), creditHours(0) {
    schedule = new std::string[maxCourses];
}

// Destructor
Student::~Student() {
    delete[] schedule;
}

// Copy Constructor
Student::Student(const Student& other)
    : lastName(other.lastName), firstName(other.firstName), studentID(other.studentID),
      maxCourses(other.maxCourses), currentCourses(other.currentCourses), creditHours(other.creditHours) {
    schedule = new std::string[maxCourses];
    std::copy(other.schedule, other.schedule + currentCourses, schedule);
}

// Copy Assignment Operator
Student& Student::operator=(const Student& other) {
    if (this == &other) return *this;

    delete[] schedule;

    lastName = other.lastName;
    firstName = other.firstName;
    studentID = other.studentID;
    maxCourses = other.maxCourses;
    currentCourses = other.currentCourses;
    creditHours = other.creditHours;

    schedule = new std::string[maxCourses];
    std::copy(other.schedule, other.schedule + currentCourses, schedule);

    return *this;
}

void Student::addCourse(const std::string& courseName, int courseCredits) {
    if (currentCourses < maxCourses) {
        schedule[currentCourses++] = courseName;
        creditHours += courseCredits;
    }
}

std::string Student::getFullName() const {
    return lastName + ", " + firstName;
}

std::string Student::getID() const {
    return studentID;
}

int Student::getCreditHours() const {
    return creditHours;
}

const std::string* Student::getSchedule() const {
    return schedule;
}

int Student::getCurrentCourses() const {
    return currentCourses;
}

bool Student::hasSchedule() const {
    return currentCourses > 0;
}
