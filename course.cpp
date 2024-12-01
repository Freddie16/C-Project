#include "course.h"
#include <algorithm>

// Default Constructor
Course::Course()
    : courseName(""), creditHours(0), maxEnrollment(0), currentEnrollment(0), roster(nullptr) {}

// Parameterized Constructor
Course::Course(const std::string& courseName, int creditHours, int maxEnrollment)
    : courseName(courseName), creditHours(creditHours), maxEnrollment(maxEnrollment), currentEnrollment(0) {
    roster = new std::string[maxEnrollment];
}

// Destructor
Course::~Course() {
    delete[] roster;
}

// Copy Constructor
Course::Course(const Course& other)
    : courseName(other.courseName), creditHours(other.creditHours), maxEnrollment(other.maxEnrollment),
      currentEnrollment(other.currentEnrollment) {
    roster = new std::string[maxEnrollment];
    std::copy(other.roster, other.roster + currentEnrollment, roster);
}

// Copy Assignment Operator
Course& Course::operator=(const Course& other) {
    if (this == &other) return *this;

    delete[] roster;

    courseName = other.courseName;
    creditHours = other.creditHours;
    maxEnrollment = other.maxEnrollment;
    currentEnrollment = other.currentEnrollment;

    roster = new std::string[maxEnrollment];
    std::copy(other.roster, other.roster + currentEnrollment, roster);

    return *this;
}

bool Course::addStudent(const std::string& studentName) {
    if (isFull()) return false;
    roster[currentEnrollment++] = studentName;
    return true;
}

bool Course::isFull() const {
    return currentEnrollment >= maxEnrollment;
}

std::string Course::getName() const {
    return courseName;
}

int Course::getCreditHours() const {
    return creditHours;
}

int Course::getMaxEnrollment() const {
    return maxEnrollment;
}

int Course::getCurrentEnrollment() const {
    return currentEnrollment;
}

const std::string* Course::getRoster() const {
    return roster;
}
