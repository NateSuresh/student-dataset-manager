// college.c - Main program for App2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataset.h"

#define MAX_STUDENTS 3000
#define NUM_RECORDS 1000

int getRandomStep() {
    return (rand() % 2) + 1;
}

int getRandomAge() {
    return (rand() % 13) + 18;
}

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

    int searchIDVal = getRandomID();
    searchID(ds, searchIDVal);

    int deleteIDVal = getRandomID();
    deletion(ds, deleteIDVal);

    destroyDataSet(ds);
    return 0;
}

