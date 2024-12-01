#include "school.h"
#include <cstdio>
#include <cstring>

int main() {
    School school;

    // Allocate buffers for filenames
    const int FILENAME_BUFFER_SIZE = 256;
    char courseFile[FILENAME_BUFFER_SIZE];
    char studentFile[FILENAME_BUFFER_SIZE];

    // Prompt and input course file name
    printf("Enter course file name: ");
    if (fgets(courseFile, FILENAME_BUFFER_SIZE, stdin) == nullptr) {
        fprintf(stderr, "Error reading course file name\n");
        return 1;
    }

    // Remove newline if present
    courseFile[strcspn(courseFile, "\n")] = 0;

    // Prompt and input student file name
    printf("Enter student file name: ");
    if (fgets(studentFile, FILENAME_BUFFER_SIZE, stdin) == nullptr) {
        fprintf(stderr, "Error reading student file name\n");
        return 1;
    }

    // Remove newline if present
    studentFile[strcspn(studentFile, "\n")] = 0;

    // Load courses and students
    school.loadCourses(courseFile);
    school.loadStudents(studentFile);

    // Process the registrations
    school.processRegistrations();

    // Display all data
    school.displayAllData();

    return 0;
}