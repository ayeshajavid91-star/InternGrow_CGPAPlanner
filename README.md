# 🎓 CGPA Insight

An automated **Semester GPA & CGPA calculator** with a predictive planning feature, built as a **C++ console application** with an accompanying interactive **web version**.

**🔗 Live Demo:** [https://ayeshajavid91-star.github.io/CGPA-Insight/](https://ayeshajavid91-star.github.io/CGPA-Insight/)

---

## 📌 Project Overview

CGPA Insight takes course details, grades, and credit hours as input and automatically computes both **Semester GPA** and **Cumulative CGPA**. Its standout feature works backward from a target CGPA to tell students exactly what GPA they need in upcoming semesters to reach their goal.

---

## ✨ Features

### 🔢 Core Features
- Accepts multiple semesters and multiple courses per semester
- Automatically converts letter grades (A, B, C, D, F) into grade points
- Calculates **individual Semester GPA** using the standard weighted formula
- Calculates **Cumulative CGPA** across all entered semesters
- Displays a clean, formatted final report

### 🔮 Predictive CGPA Planning
- Enter a **target CGPA** and get the minimum GPA required in future semesters to reach it
- Warns when the target is mathematically unachievable (required GPA exceeds 4.0)
- Notifies the user if the target has already been surpassed

---

## 🛠️ Tech Stack

| Layer | Technology |
|---|---|
| Core Logic | C++ (Structures, Functions, Vectors, Conditional Logic) |
| Web Version | HTML, CSS, JavaScript |

---

## ⚙️ How It Works

**Semester GPA:**
```
GPA = (Σ Grade Point × Credit Hours) / (Σ Credit Hours)
```

**Cumulative CGPA:**
```
CGPA = (Σ All Grade Points) / (Σ All Credit Hours)
```

**Predictive Required GPA:**
```
Required GPA = (Target CGPA × Total Future Credits − Current Total Points) / Remaining Credits
```

---

## ▶️ How to Run

### C++ Console Version
```bash
g++ CGPA_Insight.cpp -o CGPA_Insight
./CGPA_Insight
```
Follow the on-screen prompts to enter semester, course, grade, and credit-hour details.

### Web Version
No installation needed — try it live:
👉 **[Open CGPA Insight](https://ayeshajavid91-star.github.io/CGPA-Insight/)**

Or run locally:
```bash
git clone https://github.com/ayeshajavid91-star/CGPA-Insight.git
cd CGPA-Insight
```
Then open `index.html` in your browser.

---

## 📂 Project Structure

```
CGPA-Insight/
├── CGPA_Insight.cpp     # C++ console application
├── index.html            # Web version
└── README.md
```

---

## 🏷️ Suggested GitHub Topics

```
cpp
gpa-calculator
cgpa-calculator
academic-tools
javascript
web-app
```

---

## 👤 Author

Developed by **Ayesha Javid**.

---

## 📄 License

**All Rights Reserved.**

This project and its source code are the intellectual property of the author. No part of this repository — including the code, design, or documentation — may be copied, modified, distributed, used, or reproduced in any form without the explicit written permission of the author.

© 2026 Ayesha Javid. Unauthorized use is strictly prohibited.

For permissions or licensing inquiries, contact: **ayeshajavid91@gmail.com**
