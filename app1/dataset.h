// dataset.h - Header file for App1

#ifndef DATASET_H
#define DATASET_H

typedef struct dataset DATASET;

DATASET *createDataSet(int maxStudents);
void destroyDataSet(DATASET *ds);
void insertion(DATASET *ds, int id, int age);
void deletion(DATASET *ds, int age);
void searchAge(DATASET *ds, int age);
int maxAgeGap(DATASET *ds);

#endif

