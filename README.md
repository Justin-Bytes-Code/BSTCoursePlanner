# BSTCousePlanner
This was a medium-level assignment done in C++ to help academic advisors look up courses with a Binary Search Tree. This assinment was done mainly to assist me in my futher understanding of data structures. 

---
**It Includes:**

- Binary Search Tree Implementation
- File Inputs Support using CSV
- File Editing
- Course Search Controls
- Course Deletion Controls
- Course Listing Controls
- Error Handling
- Basic Menu Interface
- File Parsing

---
**Rubric Of Project 1 (Document Submission)**

CS 300 Project One Guidelines and Rubric
Competencies
In this project, you will demonstrate your mastery of the following competencies:

Apply non-coding development methodologies for outlining an algorithmic design
Evaluate complex data structures that solve a given problem using advanced algorithmic designs
Scenario
The academic advisors in the Computer Science department at ABCU are very happy with the pseudocode you completed. You are now prepared to expand the pseudocode to directly respond to the two items advising hopes to accomplish with this program. Remember, your program will need to do the following tasks:

Print a list of all the computer science courses in alphanumeric order.
For a given course, print out its title and prerequisites.
You will write pseudocode to address each advisor’s requirements. You will do so for each of the data structures you explored in the previous assignments, including vector, hash table, and tree. Then you will perform a runtime analysis to determine which data structure will be the best to use when you begin coding in the next project.

Directions
In the milestones leading to this project, you wrote a description for the course object that will be stored in different data structures. To determine the running time of each of those data structures in this application, you must finish writing all the pseudocode for the rest of the code and perform a Big O analysis. 

Specifically, you must address the following rubric criteria:

Pseudocode

Resubmit pseudocode from previous pseudocode assignments and update as necessary. In the previous assignments, you created pseudocode for each of the three data structures: vector, hash table, and tree. Be sure to resubmit the following pseudocode for each data structure:
Design pseudocode to define how the program opens the file, reads the data from the file, parses each line, and checks for formatting errors.
Design pseudocode to show how to create course objects so that one course object holds data from a single line from the input file.
Design pseudocode that will print out course information and prerequisites.
Create pseudocode for a menu. The menu will need to perform the following actions:
Option 1: Load the file data into the data structure. Note that before you can print the course information or the sorted list of courses, you must load the data into the data structure.
Option 2: Print an alphanumerically ordered list of all the courses in the Computer Science department.
Option 3: Print the course title and the prerequisites for any individual course.
Option 9: Exit the program.
Design pseudocode that will print out the list of the courses in the Computer Science program in alphanumeric order. Continue working with the Pseudocode Document linked in the Supporting Materials section. Note that you will design for the same three data structures that you have been using in your previous pseudocode milestones: vector, hash table, and tree. This time, you will create the final pieces of pseudocode that you will need for ABCU’s advising program. To complete this part of the process, do the following actions:
Sort the course information by alphanumeric course number from lowest to highest.
Print the sorted list to a display.
Evaluation

Evaluate the run time and memory of data structures that could be used to address the requirements. In previous assignments, you created pseudocode to define how the program opens the file, reads the data from the file, parses each line, and checks for formatting errors and to show how to create course objects so that one course object holds data from a single line from the input file.
Using the pseudocode you wrote for the previous assignments, analyze the worst-case running time of each, reading the file and creating course objects, which will be the Big O value. This analysis should not include the pseudocode written for the menu or the search/print functions Print Course List (Option 2) above. To complete this part of the project, do the following actions:
Specify the cost per line of code and the number of times the line will execute. Assume there are n courses stored in the data structure.
Assume the cost for a line to execute is 1 unless it is calling a function, in which case the cost will be the running time of that function.
Based on the advisor’s requirements, analyze each of the vector, hash table, and tree data structures. Explain the advantages and disadvantages of each structure in your evaluation.
Now that you have analyzed all three data structures, make a recommendation for which data structure you plan to use in your code. Provide justification for your recommendation based on the Big O analysis results and your analysis of the three data structures.
Milestones
Resubmit your pseudocode for the Milestones One, Two, and Three assignments, and update it as necessary based on the feedback you received. In these assignments, you already created pseudocode for each of the three data structures:

Milestone One: Vector 
Milestone Two: Hash Table
Milestone Three: Binary Search Tree
Be sure to resubmit all three milestones that had the following components:

Pseudocode designed to define how the program opens the file, reads the data from the file, parses each line, and checks for formatting errors 
Pseudocode designed to show how to create course objects so that one course object holds data from a single line from the input file
Pseudocode designed to find and print out course information and prerequisites for a single course
This submission is graded with the Final Project Part I Rubric below.

What to Submit
To complete this project, you must submit the following item:

Pseudocode and Runtime Analysis
Your submission should be formatted in a double-spaced 1- to 2-page Word document that includes your completed pseudocode, your runtime analysis in a chart, and your analysis of both the advantages and disadvantages of each structure.

---
**Rubric of Project 2 (Code Submission)**

Competency
In this project, you will demonstrate your mastery of the following competency:

Develop code using algorithms and data structures to solve basic programming problems
Scenario
The academic advisors in the Computer Science department at ABCU are very happy with the planning and design you have completed for the advising assistance software. Now, they would like you to write the code for the application so the department advisors can use it to help when they talk with students.

Directions
Complete all of your coding in the integrated development environment (IDE). Additional references on the use of this IDE are linked in the Supporting Materials section. As you begin coding, use the data structure that you recommended in Project One to complete the following actions:

Input: Design code to correctly read the course data file. The program you submit should be a command-line program written in C++. The program should prompt the user to ask for the file name that contains the course data and read that file into course objects that are stored in your chosen data structure. Your data structure will hold course objects.
Menu: Design code to create a menu that prompts a user for menu options. The menu should include the following options:
Option 1: Load the file data into the data structure. Note that before you can print the course information or the sorted list of courses, you must load the data into the data structure. 
Option 2: Print an alphanumeric list of all the courses in the Computer Science department.
Option 3: Print the course title and the prerequisites for any individual course.
Option 9: Exit the program.
Loading Data Structure: Develop working code to load data from the file into the data structure.
Course List: Develop working code to sort and print out a list of the courses in the Computer Science program in alphanumeric order, including all math courses. To print out a course list, use the pseudocode you created previously to guide your work. Then create code that will allow advisers to print a course list in alphanumeric order. Remember that this code should do the following actions:
Sort the course information alphanumerically from lowest to highest.
Print the sorted list to a display.
Course Information: Develop working code to print course information. This code should allow users to look up a course and print out information about its title and prerequisites. Your program must prompt the user to enter the course number. You will then print the name of the course and the prerequisite course numbers and titles. See Project Two Sample Program Output in the Supporting Documents section.
Industry Standard Best Practices: Apply industry standard best practices in code design. Your program should display an error message when user input does not fall within the parameters. You should also use in-line comments and appropriate naming conventions to enhance readability and maintainability.
What to Submit
To complete this project, you must submit the following item:

Advising Assistance Program
Submit your ProjectTwo.cpp C++ code file. Ideally, all of your code should be in a single CPP file with all of the necessary functions working correctly without any CSVParser or other header files being used. Do not zip or compress your submission. Make sure the code compiles and runs and has been thoroughly tested.

---
**Questions**

(You don't have to read this. This is only for a homework assignment with this repository) 

What was the problem you were solving in the projects for this course?

- The problem was solving a issue advisors would have of needing to use paperwork to look up courses to assist students. This program will help solve this issue allowing academic advisors to look up a course almost instantly after loading it into the program. This program is a base that could allow in the future almost any CSV formatted correctly to be used as well as even have multiple CSVs. 

How did you approach the problem? Consider why data structures are important to understand.

- When approaching this problem, I first considered how much data the program would need to handle. Schools like SNHU have hundreds of classes, especially with their online division, so it was clear that a proper data structure was necessary. Advisors needed a fast way to search for classes, so two options immediately came to mind: Hash Tables and Binary Search Trees (BSTs). I compared the pros and cons of both and realized that a BST was the better choice, mainly because it keeps data ordered.

-Hash tables are great for quick lookups, but they don’t maintain order, meaning the courses would have to be sorted alphabetically every time the program runs. A BST, on the other hand, allows for efficient insertions, searching, and ordered traversal, which fits perfectly with the program’s needs. Understanding data structures is crucial here picking the wrong one could make the program slower and defeat its purpose. For example, a simple linked list would work for small datasets, but with 800+ courses and prerequisites, it would quickly become slower than using paper.

How did you overcome any roadblocks you encountered while going through the activities or project?

- My first Roadblock in this challange was the CSV. The CSV was the 1 piece in this project I was not allowed to alter. This means I would have to make the program work around this document rather then format a document to my program. At first this gave me trouble as I struggled to parse the file correctly but I overcame this by focusing on ensure the program can read CSV correctly. For an example one I personally made. Then I can build the rest of the functionality as the entire program relied on this CSV. 

How has your work on this project expanded your approach to designing software and developing programs?

- This project has taught me a lot in program design! Program design shouldn't be about UI or the looks of the program it should be made with a data structure in mind and how to build around it. Every data structure is great and comes with it's own perks/flaws this is something you have to keep in mind when making a program. Failing to keep this in mind will only lead to a mandatory refactor if the program can even release. Data Structure and algorithm are one of if not the most important part of creating a program. 

How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

-Keeping programs maintable and readable personally has never been something I struggle with much but this project reinforced why it mattered a lot. Even when coding on my own I always ensure that my code is heavily documented incase I take a break or need to stop programming for a bit. It also allows for you to build a lot easier ontop of the program to support it with rapid development. Keeping the code readable and adaptable also helps when designing multiple functions like the menu in this program. I was able to code 1 part then go to bed and comeback the next day and instantly know what to do with the TODO comment I left myself as well as find all parts I needed to edit as they were labeled easily. When I code I never have to search around for snipets/functions as it's easily found with comments and a search key. 

