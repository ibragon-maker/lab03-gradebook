#include <iostream>
#include <limits>
#include "stats.h"

double studentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    if (studentIndex < 0 || studentIndex >= STUDENT_COUNT) {
        std::cout << "Invalid index provided\n";
        return -1.0;
    }
    double total{};
    for (int i = 0; i < ASSIGNMENT_COUNT; i++) {
        total += scores[studentIndex][i];
    }
    return total / ASSIGNMENT_COUNT;
}

double assignmentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int assignmentIndex) {
    double total{};
    for (int i = 0; i < STUDENT_COUNT; i++) {
        total += scores[i][assignmentIndex];
    }
    return total / STUDENT_COUNT;
}

void findExtremes(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex, double &lowest, double &highest) {
    lowest = std::numeric_limits<double>::max();
    highest = std::numeric_limits<double>::lowest();

    for (int i = 0; i < ASSIGNMENT_COUNT; i++) {
        if (scores[studentIndex][i] < lowest) {
            lowest = scores[studentIndex][i];
        }
        if (scores[studentIndex][i] > highest) {
            highest = scores[studentIndex][i];
        }
    }
}

char letterGrade(double average) {
    if (average >= 90.0) return 'A';
    if (average >= 80.0) return 'B';
    if (average >= 70.0) return 'C';
    if (average >= 60.0) return 'D';
    return 'F';
}

double gradePoints(char letter) {
    switch(letter) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        default: return 0.0;
    }
}

int countGrade(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, char target) {
    int count{};
    for (int i = 0; i < STUDENT_COUNT; i++) {
        if (letterGrade(studentAverage(scores, i)) == target) {
            count++;
        }
    }
    return count;
}

double classAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores) {
    double total{0.0};
    for (int i = 0; i < STUDENT_COUNT; i++) {
        for (int j = 0; j < ASSIGNMENT_COUNT; j++) {
            total += scores[i][j];
        }
    }
    return total / (STUDENT_COUNT * ASSIGNMENT_COUNT);
}

bool hasPerfectScore(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    for (int i = 0; i < ASSIGNMENT_COUNT; i++) {
        if (scores[studentIndex][i] >= 100.0) {
            return true;
        }
    }
    return false;
}

bool isAtRisk(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    if (studentAverage(scores, studentIndex) < 70.0) {
        return true;
    }
    for (int i = 0; i < ASSIGNMENT_COUNT; i++) {
        if (scores[studentIndex][i] < 50.0) {
            return true;
        }
    }
    return false;
}

std::string initialsOf(std::string fullName) {
    std::string result{};
    result += fullName[0];
    result += ". ";
    auto index = fullName.find(" ");
    if (index != std::string::npos && index + 1 < fullName.length()) {
        result += fullName[index + 1];
        result += ".";
    }
    return result;
}
