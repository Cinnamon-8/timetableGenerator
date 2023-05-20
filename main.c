#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_TIMESLOTS 10

typedef struct {
    char name[20];
    int duration;
} Course;

typedef struct {
    char day[10];
    char startTime[10];
    char endTime[10];
} TimeSlot;

typedef struct {
    Course course;
    TimeSlot timeslot;
} TimetableEntry;

TimetableEntry timetable[MAX_COURSES];

bool isSlotAvailable(int index, TimeSlot timeslot) {
    for (int i = 0; i < index; i++) {
        if (strcmp(timetable[i].timeslot.day, timeslot.day) == 0 &&
            strcmp(timetable[i].timeslot.startTime, timeslot.startTime) == 0)
        {
            return false;
        }
    }
    return true;
}

void clearScreen() {
    printf("\033[2J\033[H"); // ANSI escape sequence to clear screen
}

void collectCourseData(Course courses[], int numCourses) {
    printf("Enter course details:\n");
    for (int i = 0; i < numCourses; i++) {
        printf("Course %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", courses[i].name);
        printf("Duration (in hours): ");
        while (scanf("%d", &courses[i].duration) != 1 || courses[i].duration <= 0) {
            printf("Invalid input. Please enter a positive integer for duration: ");
            while (getchar() != '\n'); // Clear input buffer
        }
        printf("\n");
    }
}

void collectTimeSlotData(TimeSlot timeslots[], int numTimeslots) {
    printf("Enter time slot details:\n");
    for (int i = 0; i < numTimeslots; i++) {
        printf("Time Slot %d:\n", i + 1);
        printf("Day: ");
        scanf("%s", timeslots[i].day);
        printf("Start Time: ");
        scanf("%s", timeslots[i].startTime);
        printf("End Time: ");
        scanf("%s", timeslots[i].endTime);
        printf("\n");
    }
}

void generateTimetable(int index, Course courses[], int numCourses, TimeSlot timeslots[], int numTimeslots) {
    if (index == numCourses) {
        // All courses have been scheduled, print the timetable
        clearScreen();
        printf("Generated Timetable:\n");
        printf("+---------------------------------------+\n");
        printf("| %-10s | %-10s | %-10s |\n", "Course", "Day", "Time");
        printf("+---------------------------------------+\n");
        for (int i = 0; i < numCourses; i++) {
            printf("| %-10s | %-10s | %-10s |\n", timetable[i].course.name, timetable[i].timeslot.day, timetable[i].timeslot.startTime);
            printf("+---------------------------------------+\n");
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < numTimeslots; i++) {
        if (isSlotAvailable(index, timeslots[i])) {
            timetable[index].course = courses[index];
            timetable[index].timeslot = timeslots[i];

            generateTimetable(index + 1, courses, numCourses, timeslots, numTimeslots);
        }
    }
}

int main() {
    int numCourses, numTimeslots;

    printf("Automatic Timetable Generator\n");
    printf("------------------------------\n\n");

    printf("Enter the number of courses: ");
    while (scanf("%d", &numCourses) != 1 || numCourses <= 0 || numCourses > MAX_COURSES) {
        printf("Invalid input. Please enter a positive integer up to %d for the number of courses: ", MAX_COURSES);
        while (getchar() != '\n'); // Clear input buffer
    }

    printf("Enter the number of time slots: ");
    while (scanf("%d", &numTimeslots) != 1 || numTimeslots <= 0 || numTimeslots > MAX_TIMESLOTS) {
        printf("Invalid input. Please enter a positive integer up to %d for the number of time slots: ", MAX_TIMESLOTS);
        while (getchar() != '\n'); // Clear input buffer
    }

    Course* courses = malloc(numCourses * sizeof(Course));
    TimeSlot* timeslots = malloc(numTimeslots * sizeof(TimeSlot));

    collectCourseData(courses, numCourses);
    collectTimeSlotData(timeslots, numTimeslots);

    generateTimetable(0, courses, numCourses, timeslots, numTimeslots);

    free(courses);
    free(timeslots);

    return 0;
}
