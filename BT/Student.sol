// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract StudentData {

    // Structure
    struct Student {
        string name;
        uint rollno;
    }

    // Array
    Student[] public studentarr;

    function addStudent(string memory name, uint rollno) public {
        for(uint i = 0; i < studentarr.length; i++) {
            if(studentarr[i].rollno == rollno) {
                revert("Student roll no already exist");
            }
        }
        studentarr.push(Student(name, rollno));
    }

    function displayAllStudents() public view returns(Student[] memory) {
        return studentarr;
    }

    function getStudentByIndex(uint idx) public view returns(Student memory) {
        require(idx < studentarr.length, "index out of bound");
        return studentarr[idx];
    }

    function getStudentCount() public view returns(uint) {
        return studentarr.length;
    }

    fallback() external payable {
        // This function handles calls that do not match
        // any function in the contract.
    }

    receive() external payable {
        // This function handles Ether sent without data.
    }
}

/*
COMMENTS / EXPLANATION:

1. SPDX-License-Identifier:
   Specifies the license of the smart contract.

2. pragma solidity ^0.8.0:
   Specifies the compatible Solidity compiler version.

3. contract StudentData:
   Creates a smart contract named StudentData.

4. struct Student:
   Defines a structure to store student information.

5. string name:
   Stores the student's name.

6. uint rollno:
   Stores the student's roll number.

7. Student[] public studentarr:
   Creates a dynamic array to store multiple student records.
   'public' automatically creates a getter for individual
   array elements.

8. function addStudent(string memory name, uint rollno):
   Adds a new student to the array.

9. memory:
   Stores temporary data in memory while the function executes.

10. for loop:
    Iterates through all existing student records.

11. studentarr[i].rollno == rollno:
    Checks whether the given roll number already exists.

12. revert("Student roll no already exist"):
    Stops execution and reverts the transaction if a duplicate
    roll number is found.

13. studentarr.push(Student(name, rollno)):
    Creates a Student record and adds it to the end of the array.

14. function displayAllStudents():
    Returns all student records stored in the array.

15. view:
    Indicates that the function reads data without modifying it.

16. returns(Student[] memory):
    Returns the complete array of student records in memory.

17. function getStudentByIndex(uint idx):
    Returns the student record at the specified array index.

18. require(idx < studentarr.length, "index out of bound"):
    Checks that the index exists within the array.
    Array indexing starts from 0.

19. return studentarr[idx]:
    Returns the student at the given index.

20. function getStudentCount():
    Returns the total number of students in the array.

21. studentarr.length:
    Gives the current number of student records.

22. fallback() external payable:
    Executes when a call does not match any existing function
    and does not qualify for the receive function.
    It can also handle calls containing data.

23. receive() external payable:
    Executes when Ether is sent to the contract with empty
    calldata, provided the function is available.

24. payable:
    Allows the fallback and receive functions to accept Ether.

IMPORTANT:
- Duplicate roll numbers are not allowed through addStudent().
- getStudentByIndex() uses zero-based indexing.
- fallback() and receive() handle certain calls and Ether
  transfers; they do not automatically store student data.
*/