// dataset.h - Header file for App2

#ifndef DATASET_H
#define DATASET_H

typedef struct dataset DATASET;

DATASET *createDataSet(int maxStudents);
void destroyDataSet(DATASET *ds);
void insertion(DATASET *ds, int id, int age);
void deletion(DATASET *ds, int id);
void searchID(DATASET *ds, int id);

#endif

