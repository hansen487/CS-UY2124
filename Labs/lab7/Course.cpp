#include "Student.h"
#include "Course.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace BrooklynPoly{
    class Student;

    Course::Course(const string& name) : c_name(name) {}
//    Course::~Course(){
//        for (Student* student: students){
//            student -> drop_course(name);
//            delete student;
//        }
//        students.clear();
//    }
//    Course::Course(const Course* rhs): name(name){
//        for (Student* student: rhs.students){
//            Student* new_student = new Student(student -> get_name());
//            new_student -> enroll_course(this);
//            students.push_back(new_student);
//        }
//    }
//    Course::Course& operator=(const Course* rhs){
//        for (Student* student: students){
//            student -> drop_course(name);
//            delte student;
//        }
//        students.clear();
//        for (Student* student: rhs.students){
//            Student* new_student = new Student(student -> get_name());
//            new_student -> enroll_course(this);
//            students.push_back(new_student);
//        }
//    }

    void Course::enroll_student(Student* student){
        students.push_back(student);
    }

    void Course::drop_student(const string& student_name){
        int counter, position = 0;
        for (Student* student: students){
            if (student -> get_name() == student_name){
                position = counter;
            }
            counter++;
        }
        Student* temp = students[position];
        students[position] = students.back();
        students.back() = temp;
        students.pop_back();
    }

    const string& Course::get_name() const{
        return c_name;
    }

    vector<Student*> Course::get_students() const{
        return students;
    }


}
