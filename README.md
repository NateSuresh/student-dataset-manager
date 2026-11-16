# Student Dataset Manager

This project is a student dataset system written in C.

The project has two different apps that use different data structures. The goal was to choose a data structure that works best for what each app needs to do.

## App 1

App 1 uses an array of linked lists.

Each spot in the array is for a certain age from 18 to 30. Students with the same age are stored in the same linked list.

This makes it easy to search for students by age because the program already knows which list to check.

### App 1 Features

- Add students
- Delete students by age
- Search for students by age
- Find the biggest age gap
- Store students using linked lists
- Free all memory when the program is done

### Why I Used Linked Lists

App 1 mainly searches students by age.

Since there are only 13 possible ages from 18 to 30, using an array of linked lists makes it easy to go straight to the right age.

Adding a student is also fast because the student is added to the front of the list.

## App 2

App 2 uses a hash table with linear probing.

The hash table stores students using their student ID.

This makes searching for a student by ID fast most of the time.

### App 2 Features

- Add students
- Delete students by ID
- Search for students by ID
- Store student IDs and ages
- Handle collisions using linear probing
- Free the hash table when the program is done

### Why I Used a Hash Table

App 2 mainly searches students by ID.

A hash table works well for this because searching, adding, and deleting are usually close to O(1).

A linked list would be slower because it may have to check every student before finding the right ID.

## Project Structure

```text
student-dataset-manager/
├── app1/
│   ├── college.c
│   ├── dataset.c
│   ├── dataset.h
│   ├── report.txt
│   └── README.md
│
├── app2/
│   ├── college.c
│   ├── dataset.c
│   ├── dataset.h
│   ├── report.txt
│   └── README.md
│
├── .gitignore
└── README.md
```

## Data Structures Used

### App 1

- Array
- Linked Lists
- Pointers
- Dynamic Memory

### App 2

- Hash Table
- Linear Probing
- Arrays
- Pointers
- Dynamic Memory

## Time Complexity

### App 1

- Create dataset: O(1)
- Insert student: O(1)
- Delete by age: O(k)
- Search by age: O(k)
- Destroy dataset: O(n)

`k` is the number of students with the same age.

### App 2

- Create dataset: O(1)
- Insert: O(1) average, O(n) worst case
- Search by ID: O(1) average, O(n) worst case
- Delete by ID: O(1) average, O(n) worst case
- Destroy dataset: O(n)

## What I Learned

This project helped me understand:

- Linked lists
- Hash tables
- Linear probing
- Dynamic memory
- Pointers
- Choosing the right data structure
- Time complexity
- Searching and deleting data
- Organizing a C project into different files

The main thing I learned was that one data structure is not always best for everything. App 1 works better with linked lists because it searches by age, while App 2 works better with a hash table because it searches by student ID.
