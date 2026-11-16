// dataset.c - Implementation for App2
#include <stdio.h>
#include <stdlib.h>
#include "dataset.h"

#define TABLE_SIZE 1009

typedef struct student {
    int id;
    int age;
    int filled; // 0 = empty, 1 = filled, -1 = deleted
} STUDENT;

struct dataset {
    STUDENT *table;
};

// Hash function with linear probing
int findSlot(STUDENT *table, int id, int *found) {
    int i, index;
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (id + i) % TABLE_SIZE;
        if (table[index].filled == 0) {
            *found = 0;
            return index;
        } else if (table[index].filled == 1 && table[index].id == id) {
            *found = 1;
            return index;
        }
    }
    *found = 0;
    return -1; // table full
}

DATASET *createDataSet(int maxStudents) {
    DATASET *ds = malloc(sizeof(DATASET));
    ds->table = calloc(TABLE_SIZE, sizeof(STUDENT));
    return ds;
}

void destroyDataSet(DATASET *ds) {
    free(ds->table);
    free(ds);
}

void insertion(DATASET *ds, int id, int age) {
    int found;
    int index = findSlot(ds->table, id, &found);
    if (index != -1 && !found) {
        ds->table[index].id = id;
        ds->table[index].age = age;
        ds->table[index].filled = 1;
    }
}

void deletion(DATASET *ds, int id) {
    int found;
    int index = findSlot(ds->table, id, &found);
    printf("Trying to delete ID: %d\n", id);
    if (found) {
        printf("Deleted student ID: %d, Age: %d\n", ds->table[index].id, ds->table[index].age);
        ds->table[index].filled = -1; // mark as deleted
    } else {
        printf("Student ID %d not found\n", id);
    }
}

void searchID(DATASET *ds, int id) {
    int found;
    int index = findSlot(ds->table, id, &found);
    printf("Searching for ID: %d\n", id);
    if (found) {
        printf("Found student ID: %d, Age: %d\n", ds->table[index].id, ds->table[index].age);
    } else {
        printf("Student ID %d not found\n", id);
    }
}

