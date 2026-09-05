#pragma once

#include <array>
#include <string>
#include "stats.h"

constexpr int NAME_WIDTH = 14;

std::string padName(std::string fullName, int width);
void printHeader();
void printStudentRow(const std::array<std::string, STUDENT_COUNT>& names, const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);
void printHistogram(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, const std::array<std::string, STUDENT_COUNT>& names);
void printAssignmentSummary(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores);
void printRoster(const std::array<std::string, STUDENT_COUNT>& names);
