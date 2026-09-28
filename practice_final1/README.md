# Practice Final 1: Volunteers

A Qt exam-practice app for managing volunteers across departments. Each department gets its own window listing its volunteers, where you can add new volunteers and assign unassigned ones. A separate window shows all departments with their volunteer counts. Windows stay in sync through the Observer pattern.

Built with C++, Qt 6 and CMake.

## Run

Build with CMake (Qt 6 required). The app reads `departments.txt` and `volunteers.txt` from the working directory (the build folder), one comma-separated record per line:

```
departments.txt:  name,description
volunteers.txt:   name,email,interests,department
```
