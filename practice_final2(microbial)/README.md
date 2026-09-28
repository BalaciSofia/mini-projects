# Practice Final 2: Microbial

A Qt exam-practice app for a microbiology lab. Each biologist gets a window listing the bacteria from the species they study (name, species, size, diseases), can filter the list by species and can add new bacteria. All windows update together through the Observer pattern.

Built with C++, Qt 6 and CMake.

## Run

Build with CMake (Qt 6 required). The app reads `biologist.txt` and `bacteria.txt` from the working directory (the build folder):

```
biologist.txt:  name,species1;species2;...
bacteria.txt:   name,species,size,disease1;disease2;...
```
