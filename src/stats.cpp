#include "stats.h"

char letterGrade(double score) {
    if (score >= 90.0) return 'A';
    if (score >= 80.0) return 'B';
    if (score >= 70.0) return 'C';
    if (score >= 60.0) return 'D';
    return 'F';
}

double studentAverage(const double scores[][ASSIGNMENT_COUNT], int studentIndex, int assignmentCount) {
    double sum = 0.0;
    for (int j = 0; j < assignmentCount; ++j) {
        sum += scores[studentIndex][j];
    }
    return (assignmentCount > 0) ? (sum / assignmentCount) : 0.0;
}

double classAverage(const double scores[][ASSIGNMENT_COUNT], int studentCount, int assignmentCount) {
    double totalSum = 0.0;
    for (int i = 0; i < studentCount; ++i) {
        totalSum += studentAverage(scores, i, assignmentCount);
    }
    return (studentCount > 0) ? (totalSum / studentCount) : 0.0;
}
