# Shakespearian Insult Generator (C++)

This project implements a fully object-oriented **Shakespearian insult generator** in C++, designed to practice references, classes, vectors, strings, file I/O, exceptions, and efficient algorithm design. The program loads word lists from a tab-delimited source file and generates between **1 and 10,000 unique, alphabetically sorted insults**, writing them to the console or to a text file.

---

##  Overview

These define three classes:

### **Main Class**
- `InsultGenerator`  
  - Responsible for loading insult source words  
  - Generating unique random insults  
  - Returning insults in alphabetical order  
  - Saving insults to an output file

### **Exception Classes**
- `FileException`  
- `NumInsultsOutOfBounds`  

All public functionality was tested using the provided `TestInsultGenerator.cpp` driver.

### How Insults Are Formed

The source file `InsultsSource.txt` contains 50 rows of 3 tab-separated columns, e.g.:

## To run:
1. Compile all source files, including the test driver:  
   ```bash
   g++ -std=c++11 TestInsultGenerator.cpp insultgenerator.cpp -o insultgen
   ./insultgen

