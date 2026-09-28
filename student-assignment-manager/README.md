# Student Assignment Manager

A console app for managing students, assignments and grades: add, remove and update students and assignments, give assignments to a student or a whole group, grade them, and see statistics (students ranked by grade on an assignment, late students, best averages). Supports undo/redo.

Storage is configurable in `src/main/settings.properties`: in memory, text files or binary (pickle) files.

## Run

Open `student-assignment-manager` as the project root (e.g. in PyCharm) and run `src/main/start.py` with `src/main` as the working directory. Tests are in `src/test/tests.py`.
