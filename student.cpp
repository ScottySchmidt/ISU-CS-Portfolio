/******************************************************************************
SCOTT SCHMIDT  |   Java to C++  | Student.Java
-------------------------------------------
Last login: Mon Sep 15 07:03:23 on ttys002
scottschmidt@Scotts-MacBook-Pro ~ % /Users/scottschmidt/Desktop/main ; exit;
Name: Rishi Saripalle - has student id: rsaripa, email: rishi.saripalle@ilstu.edu, and final GPA of: 4

Saving session...
...copying shared history...
...saving history...truncating history files...
...completed.

[Process completed]

--------------------------------------------
# Simple Makefile for building the Student project

main: main.cpp Student.cpp Address.cpp
	clang++ main.cpp Student.cpp Address.cpp -o main

clean:
	rm -f main
--------------------------------------------

package it180;
public class Student {
private String studentId;
public String email;
public String name;
private Address address;
public Student(String id) {
studentId = id;
}
public addAddress(String sn, int hn, String an, String ct, String st, String
cou){
address = new Address(sn,hn,an,ct,st,cou);
}
public void display() {
System.out.println(
name + " - has student id: " + studentId + ", email: " + email + ",
and final GPA of: " + grade);
address.display();
}
public static void main(String args[]) {
Student rishi = new Student("rsaripa");
rishi.email = "rishi.saripalle@ilstu.edu";
rishi.name = "Rishi Saripalle";
rishi.display();
}
}
*******************************************************************************/
#include <iostream>
#include <string>

// Address class holding street, house, apartment, city, state, country details.
class Address {
public:
    std::string streetName;
    int houseNumber;
    std::string apartmentNumber;
    std::string city;
    std::string state;
    std::string country;

    Address(const std::string& sn, int hn, const std::string& an,
            const std::string& ct, const std::string& st, const std::string& cour)
        : streetName(sn), houseNumber(hn), apartmentNumber(an),
          city(ct), state(st), country(cour) {}

    void display() const {
        std::cout << "Address Details:\n"
                  << "Street: " << houseNumber << " " << streetName << "\n"
                  << "Apartment: " << apartmentNumber << "\n"
                  << "City: " << city << "\n"
                  << "State: " << state << "\n"
                  << "Country: " << country << "\n";
    }
};

// STUDENT CONSTRUCTOR that takes studentId, email, name, and address.
class Student {
private:
    std::string studentId;
    Address* address; // may be null
public:
    std::string email;
    std::string name;
    double grade; 
    
    // Constructor (special function) that creates a Student using an ID.
    explicit Student(const std::string& id) : studentId(id), address(nullptr) {}

    // Method to add address
    void addAddress(const std::string& sn, int hn, const std::string& an,
                    const std::string& ct, const std::string& st, const std::string& cou) {
        // Replace existing address if needed
        delete address; // prevent memory leak if address was previously set
        address = new Address(sn, hn, an, ct, st, cou);
    }

    // Method to display student details
    void printDetails() const {
        std::cout << "Name: " << name
                  << " - has student id: " << studentId
                  << ", email: " << email
                  << ", and final GPA of: " << grade << std::endl;
        //Display Address if not null:
        if (address != nullptr) {
            address->display();
        }
    }
};

// Creates a Student, sets email and name, then prints details.
int main() {
    Student rishi("rsaripa");
    rishi.email = "rishi.saripalle@ilstu.edu";
    rishi.name = "Rishi Saripalle";
    rishi.printDetails();
    return 0;
}

/* 
Name: Rishi Saripalle - has student id: rsaripa, email: rishi.saripalle@ilstu.edu, and final GPA of: 2.11653e+214

...Program finished with exit code 0
Press ENTER to exit console.
*/
