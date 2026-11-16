# App 1 - Student Age Dataset

This app stores student records using an array of linked lists.

Each spot in the array represents an age from 18 to 30. Students with the same age are stored in the same linked list.

## Features

- Add students
- Delete all students with a certain age
- Search for students by age
- Find the biggest age gap
- Store multiple students with the same age
- Free allocated memory when the program ends

## Why I Used Linked Lists

This app does a lot of searching by age.

Since there are only 13 possible ages from 18 to 30, the program can go directly to the correct list instead of searching through every student.

Students are added to the front of the linked list, so insertion is O(1).

## Time Complexity

- Create dataset: O(1)
- Insert student: O(1)
- Delete by age: O(k)
- Search by age: O(k)
- Destroy dataset: O(n)
- Find max age gap: O(n)

`k` is the number of students with the same age.

## Files

- `college.c` - Runs and tests the program
- `dataset.c` - Contains the main dataset functions
- `dataset.h` - Contains the function declarations
- `report.txt` - Explains the data structure and time complexity
