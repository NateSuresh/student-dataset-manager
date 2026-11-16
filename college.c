// college.c - Main function for App1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataset.h"

#define MAX_STUDENTS 3000
#define NUM_RECORDS 1000

// Helper: returns 1 or 2 randomly
int getRandomStep() {
    return (rand() % 2) + 1;
}

// Helper: returns random age between 18 and 30
int getRandomAge() {
    return (rand() % 13) + 18;
}

// Helper: returns random ID between 1 and 2000
int getRandomID() {
    return (rand() % 2000) + 1;
}

int main() {
    srand(time(NULL));

    DATASET *ds = createDataSet(MAX_STUDENTS);

    int id = getRandomStep();
    for (int i = 0; i < NUM_RECORDS; i++) {
        int age = getRandomAge();
        insertion(ds, id, age);
        id += getRandomStep();
    }

    // Search by random age
    int searchAgeVal = getRandomAge();
    printf("Searching for age %d:\n", searchAgeVal);
    searchAge(ds, searchAgeVal);

    // Delete all with random age
    int deleteAgeVal = getRandomAge();
    printf("Deleting all students with age %d:\n", deleteAgeVal);
    deletion(ds, deleteAgeVal);

    // Get max age gap
    int gap = maxAgeGap(ds);
    printf("Max age gap is: %d\n", gap);

    destroyDataSet(ds);
    return 0;
}

