/*
    InternGrow C++ Programming Track
    TASK 1: Automated Semester CGPA Planner (WITH UPGRADE FEATURE)
    -----------------------------------------------------------------
    Basic Feature:
        - Courses, grades, aur credit hours ka input le kar
          har semester ka GPA aur overall CGPA calculate karta hai.

    Upgrade Feature:
        - Predictive Simulation: User apna TARGET CGPA aur BAKI
          semesters ke credit hours batata hai, aur program calculate
          karta hai ke target CGPA hasil karne ke liye aane wale
          semesters mein kam se kam kitna GPA lena hoga.
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ---------- Structure: Ek course ki details store karne ke liye ----------
struct Course {
    string name;
    char grade;
    double gradePoint;
    int creditHours;
};

// ---------- Grade letter ko grade point mein convert karna ----------
double getGradePoint(char grade) {
    switch (toupper(grade)) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default:
            cout << "Invalid grade entered! Default 0.0 assign kiya gaya.\n";
            return 0.0;
    }
}

// ---------- Ek semester ka GPA calculate karna ----------
double calculateGPA(vector<Course> &courses) {
    double totalPoints = 0.0;
    int totalCredits = 0;

    for (size_t i = 0; i < courses.size(); i++) {
        totalPoints += courses[i].gradePoint * courses[i].creditHours;
        totalCredits += courses[i].creditHours;
    }

    if (totalCredits == 0) return 0.0;
    return totalPoints / totalCredits;
}

// ---------- UPGRADE FEATURE: Predictive Simulation ----------
// Ye function batata hai ke target CGPA hasil karne ke liye
// baaki semesters mein kam se kam kitna GPA chahiye.
void predictRequiredGPA(double currentPoints, int currentCredits) {
    double targetCGPA;
    int remainingCredits;

    cout << "\n===== Predictive CGPA Simulation =====\n";
    cout << "Aapka Target CGPA kya hai? ";
    cin >> targetCGPA;

    cout << "Baaki semesters ke total credit hours kitne hain? ";
    cin >> remainingCredits;

    if (remainingCredits <= 0) {
        cout << "Remaining credit hours 0 ya negative nahi ho sakte!\n";
        return;
    }

    // Total credits jo course completion tak honge (current + remaining)
    int totalFutureCredits = currentCredits + remainingCredits;

    // Formula: Required Future GPA =
    // (Target CGPA * Total Future Credits - Current Total Points) / Remaining Credits
    double requiredPoints = (targetCGPA * totalFutureCredits) - currentPoints;
    double requiredGPA = requiredPoints / remainingCredits;

    cout << fixed << setprecision(2);

    if (requiredGPA > 4.0) {
        cout << "\n⚠ Ye target is waqt mumkin nahi hai, kyunke required GPA ("
             << requiredGPA << ") 4.0 scale se zyada hai.\n";
        cout << "Aapko apna target CGPA thora kam rakhna hoga.\n";
    }
    else if (requiredGPA < 0.0) {
        cout << "\n✅ Mubarak ho! Aap already apna target CGPA se aagay hain.\n";
        cout << "Aane wale semesters mein sirf 0.0 GPA bhi target maintain rakhega.\n";
    }
    else {
        cout << "\n>> Target CGPA (" << targetCGPA << ") hasil karne ke liye,\n";
        cout << "   aapko baaki semesters mein kam se kam GPA chahiye: "
             << requiredGPA << "\n";
    }
}

// ---------- MAIN FUNCTION ----------
int main() {
    int totalSemesters;

    cout << "===== Automated Semester CGPA Planner =====\n\n";
    cout << "Kitne semesters ka data enter karna hai (jo already complete ho chuke hain)? ";
    cin >> totalSemesters;

    double cumulativePoints = 0.0;   // Sab semesters ke grade points ka total
    int cumulativeCredits = 0;       // Sab semesters ke credit hours ka total
    vector<double> semesterGPAs;     // Har semester ka GPA store karne ke liye

    for (int s = 1; s <= totalSemesters; s++) {
        int numCourses;
        cout << "\n--- Semester " << s << " ---\n";
        cout << "Is semester mein kitne courses hain? ";
        cin >> numCourses;

        vector<Course> courses(numCourses);

        for (int i = 0; i < numCourses; i++) {
            cout << "\nCourse " << (i + 1) << " ka naam (bina space ke): ";
            cin >> courses[i].name;

            cout << "Grade enter karo (A, B, C, D, F): ";
            cin >> courses[i].grade;
            courses[i].gradePoint = getGradePoint(courses[i].grade);

            cout << "Credit hours enter karo: ";
            cin >> courses[i].creditHours;
        }

        // Is semester ka GPA nikalna
        double semGPA = calculateGPA(courses);
        semesterGPAs.push_back(semGPA);

        // Cumulative totals update karna (CGPA ke liye)
        for (size_t i = 0; i < courses.size(); i++) {
            cumulativePoints += courses[i].gradePoint * courses[i].creditHours;
            cumulativeCredits += courses[i].creditHours;
        }

        cout << fixed << setprecision(2);
        cout << "\n>> Semester " << s << " GPA: " << semGPA << "\n";
    }

    // Final CGPA calculate karna
    double cgpa = (cumulativeCredits > 0) ? (cumulativePoints / cumulativeCredits) : 0.0;

    // ===== Final Result Print Karna =====
    cout << "\n\n========== FINAL REPORT ==========\n";
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < semesterGPAs.size(); i++) {
        cout << "Semester " << (i + 1) << " GPA: " << semesterGPAs[i] << "\n";
    }
    cout << "-----------------------------------\n";
    cout << "Overall CGPA (ab tak): " << cgpa << "\n";
    cout << "===================================\n";

    // ===== UPGRADE FEATURE: Predictive Simulation =====
    char choice;
    cout << "\nKya aap Predictive Simulation feature use karna chahte hain? (y/n): ";
    cin >> choice;

    if (tolower(choice) == 'y') {
        predictRequiredGPA(cumulativePoints, cumulativeCredits);
    } else {
        cout << "\nTheek hai, program yahan khatam hota hai. Shukriya!\n";
    }

    return 0;
}
