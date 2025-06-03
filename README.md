# CS133-To-Do-List

## Classes
### Task
- An object that represents a singular task.
- Should have a getter and setter for the data stored in this object.

### TaskNode
- A linked list that holds a task and points to the next TaskNode
- Has a compare operator for a priority queue
- Constructors for the initialization of Nodes.

### TaskManager
- Used to handle all the manipulation of tasks
- Function for removing
- Function for adding
- Function for editing the task
- Function for changing priority
- Function for printing a list of things to do

### FileManager
- Used to load up and save lists to text files
- Function for loading files
- Function for saving files
- Function for removing a file

### MenuInterface
- Used to handle all user input as well as produce a graphical interface.
- Function to display choices.
- Function to allow a user to interact with a button to remove a task
- Function to allow a user to interact with a button to add a task
- Function to display the GUI
- Function to allow the user to save files from GUI
- Function to allow user to load files from GUI

## Code Runner
-g++ -std=c++11 Task.cpp TaskManager.cpp TaskNode.cpp ToDoMain.cpp -o main.exe
-./main
