// dataset.c - Implementation for App1
#include <stdio.h>
#include <stdlib.h>
#include "dataset.h"

#define MIN_AGE 18
#define MAX_AGE 30
#define AGE_RANGE (MAX_AGE - MIN_AGE + 1)

typedef struct student {
    int id;
    int age;
    struct student *next;
} STUDENT;

struct dataset {
    STUDENT *ageLists[AGE_RANGE];
    int minAge;
    int maxAge;
};

// Create empty dataset
DATASET *createDataSet(int maxStudents) {
    DATASET *ds = malloc(sizeof(DATASET));
    for (int i = 0; i < AGE_RANGE; i++) {
        ds->ageLists[i] = NULL;
    }
    ds->minAge = MAX_AGE;
    ds->maxAge = MIN_AGE;
    return ds;
}

// Free all memory
void destroyDataSet(DATASET *ds) {
    for (int i = 0; i < AGE_RANGE; i++) {
        STUDENT *curr = ds->ageLists[i];
        while (curr != NULL) {
            STUDENT *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(ds);
}

// Insert student
void insertion(DATASET *ds, int id, int age) {
    STUDENT *s = malloc(sizeof(STUDENT));
    s->id = id;
    s->age = age;
    int index = age - MIN_AGE;
    s->next = ds->ageLists[index];
    ds->ageLists[index] = s;

    if (age < ds->minAge) ds->minAge = age;
    if (age > ds->maxAge) ds->maxAge = age;
}

// Delete all students with given age
void deletion(DATASET *ds, int age) {
    int index = age - MIN_AGE;
    STUDENT *curr = ds->ageLists[index];
    while (curr != NULL) {
        STUDENT *temp = curr;
        printf("Deleting student with ID: %d and Age: %d\n", curr->id, curr->age);
        curr = curr->next;
        free(temp);
    }
    ds->ageLists[index] = NULL;
}

// Print students with matching age
void searchAge(DATASET *ds, int age) {
    int index = age - MIN_AGE;
    STUDENT *curr = ds->ageLists[index];
    if (curr == NULL) {
        printf("No students found with age %d\n", age);
        return;
    }
    while (curr != NULL) {
        printf("Found student with ID: %d and Age: %d\n", curr->id, curr->age);
        curr = curr->next;
    }
}

// Return max age gap
int maxAgeGap(DATASET *ds) {
    // Confirm actual min/max
    int min = MAX_AGE + 1;
    int max = MIN_AGE - 1;
    for (int i = 0; i < AGE_RANGE; i++) {
        if (ds->ageLists[i] != NULL) {
            int age = i + MIN_AGE;
            if (age < min) min = age;
            if (age > max) max = age;
        }
    }
    int gap = (max > min) ? (max - min) : 0;
    printf("Max Age Gap: %d\n", gap);
    return gap;
}

