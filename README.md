# Library Management System

The project is split into seperate files. CMakeList.txt is used to compile and link the project.

## Building

Download the folder and go inside the folder.Enter the following command in terminal.

```
mkdir build
cd build
```
Next we use the CMakeList.txt to compile the project.
```
cmake ..
make
```
Finally we get the ELF file as teststudent
```
./teststudent
```
Messages are stated while running the project. In order to populate the database, I have read the data from the text files present in Database folder.
