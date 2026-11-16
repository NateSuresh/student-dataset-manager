# App 2 - Student ID Hash Table

This app stores student records using a hash table.

Each student has an ID and age. The student ID is used to decide where the student is stored in the table.

Linear probing is used when two IDs try to use the same spot.

## Features

- Add students
- Search for students by ID
- Delete students by ID
- Store student IDs and ages
- Handle hash collisions using linear probing
- Free allocated memory when the program ends

## Why I Used a Hash Table

This app mainly needs to search for students by ID.

A hash table works well because searching, adding, and deleting are usually O(1) on average.

Using a linked list or normal array would usually require checking students one by one.

## Time Complexity

- Create dataset: O(1)
- Insert student: O(1) average, O(n) worst case
- Search by ID: O(1) average, O(n) worst case
- Delete by ID: O(1) average, O(n) worst case
- Destroy dataset: O(n)

## Files

- `college.c` - Runs and tests the program
- `dataset.c` - Contains the hash table functions
- `dataset.h` - Contains the function declarations
- `report.txt` - Explains the data structure and time complexity
