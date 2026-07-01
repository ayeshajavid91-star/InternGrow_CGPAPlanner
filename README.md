# InternGrow_CGPAPlanner

## 📌 Project Overview
**Automated Semester CGPA Planner** is a C++ console application developed as part of the **InternGrow C++ Programming Track (Module 1 – Task 1)**. It allows students to input their course details, grades, and credit hours to automatically calculate their **Semester GPA** and **Cumulative CGPA (CGPA)**.

## 🚀 Features

### Core Features
- Accepts input for multiple semesters and multiple courses per semester
- Converts letter grades (A, B, C, D, F) into grade points automatically
- Calculates **individual Semester GPA** using the standard weighted formula
- Calculates **Cumulative CGPA** across all entered semesters
- Displays a clean, formatted final report of all results

### 🔥 Upgrade Feature — Predictive CGPA Simulation
- Allows the user to enter a **target CGPA**
- Calculates the **minimum GPA required in upcoming semesters** to achieve that target, based on remaining credit hours
- Warns the user if the target is mathematically unachievable (required GPA > 4.0)
- Notifies the user if they have already surpassed their target CGPA

## 🛠️ Tech Stack
- **Language:** C++
- **Concepts Used:** Structures, Functions, Vectors, Loops, Conditional Logic

## ⚙️ How It Works
1. The program calculates GPA using:
GPA = (Σ Grade Point × Credit Hours) / (Σ Credit Hours)

2. It accumulates grade points and credit hours across semesters to compute:
CGPA = (Σ All Grade Points) / (Σ All Credit Hours)

3. For the predictive feature, it works backward from a target CGPA to determine the required future GPA:
Required GPA = (Target CGPA × Total Future Credits − Current Total Points) / Remaining Credits

## ▶️ How to Run
1. Compile the program:
g++ CGPA_Planner_Upgraded.cpp -o CGPA_Planner
2. Run the executable:
./CGPA_Planner
3. Follow the on-screen prompts to enter semester, course, grade, and credit hour details.

## 📸 Sample Output
===== Automated Semester CGPA Planner =====
Semester 1 GPA: 3.43
Overall CGPA (ab tak): 3.43

Target CGPA (3.80) hasil karne ke liye,
aapko baaki semesters mein kam se kam GPA chahiye: 3.89

## 🎓 About InternGrow
This project was developed as part of the **InternGrow C++ Programming Track**, a project-based internship program focused on providing hands-on programming experience.

## 👤 Author
Developed by [Your Name] as part of InternGrow Internship — Module 1.
