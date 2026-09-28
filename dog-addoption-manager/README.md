# Dog Adoption Manager

A Qt desktop app for a dog shelter, with two modes:

- **Admin:** add, remove and update dogs in a table, with undo/redo.
- **User:** browse the dogs one by one and adopt them, filter by breed and age, see a bar chart of dogs per breed, and export your adoption list as CSV or HTML.

Built with C++, Qt 6 (Widgets) and CMake, using a layered design (domain, repository, controller, UI).

## Run

Open the folder in CLion or Qt Creator (Qt 6 required) and build with CMake. Dogs are loaded from `dog_repo.txt` in the working directory.
