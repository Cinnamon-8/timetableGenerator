# Automatic Timetable Generator

The Automatic Timetable Generator is a command-line program written in C that helps generate a timetable for a set of courses based on user-provided inputs. The program uses backtracking to efficiently generate a timetable that avoids conflicts between courses.

## Features

- Allows the user to specify the number of courses and time slots.
- Collects course details such as name and duration.
- Collects time slot details such as day, start time, and end time.
- Generates a timetable by assigning courses to available time slots.
- Displays the generated timetable in a tabular format.
- Provides error handling for invalid user inputs.
- Provides a user-friendly interface with a clear screen option.

## Getting Started

### Prerequisites

To compile and run the program, you need to have a C compiler installed on your system, such as GCC.

### Installation

1. Clone the repository or download the source code files.

```
git clone https://github.com/Cinnamon-8/timetableGenerator
```
Compile the program using the C compiler.
```
gcc -o timetable_generator main.c
```
Usage
Run the program.
```
./timetable_generator
```
Follow the prompts to enter the number of courses, time slots, course details, and time slot details.

The program will generate and display the timetable.

To run the program again, simply execute the program file.


```
./timetable_generator
```
Contributing
Contributions to this project are welcome. Feel free to fork the repository, make improvements, and submit a pull request.
