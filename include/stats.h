#pragma once

#include <array>
#include <string>

constexpr int ASSIGNMENT_COUNT = 5;
constexpr int STUDENT_COUNT = 6;

double studentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);
double assignmentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int assignmentIndex);
void findExtremes(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex, double &lowest, double &highest);
char letterGrade(double average);
double gradePoints(char letter);
int countGrade(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, char target);
double classAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores);
bool hasPerfectScore(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);
bool isAtRisk(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);
std::string initialsOf(std::string fullName);
