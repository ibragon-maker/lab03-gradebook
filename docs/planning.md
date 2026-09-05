# Lab 03 Gradebook - Planning Notes

## Final Project Structure
* `include/stats.h`: Contains the constants (`::ASSIGNMENT_COUNT`, `STUDENT_COUNT`) and prototypes for calculation functions.
* `include/display.h`: Defines formatting constants and function prototypes for printing reports and tables.
* `src/stats.cpp`: Implements all calculation logic (student averages, class average, letter grades, etc.).
* `src/display.cpp`: Implements the UI output functions (printing headers, rows, histograms, and rosters).
* `src/gradebook.cpp`: Main control file containing only `main()` and the menu loop.

## Compilation Steps
```bash
g++ -Wall -Iinclude -c src/stats.cpp -o stats.o
g++ -Wall -Iinclude -c src/display.cpp -o display.o
g++ -Wall -Iinclude -c src/gradebook.cpp -o gradebook.o
g++ gradebook.o stats.o display.o -o gradebook
