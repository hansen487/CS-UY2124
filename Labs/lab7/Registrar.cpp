#include "Student.h"
#include "Course.h"
#include "Registrar.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace BrooklynPoly{
        Registrar::Registrar() {}

        void Registrar::addCourse(const std::string& course_name){
            Course* course = new Course(course_name);
            courses.push_back(course);
            //cout << courses.back();
        }
        void Registrar::addStudent(const std::string& student_name){
            Student* student = new Student(student_name);
            students.push_back(student);
        }

        void Registrar::enrollStudentInCourse(const std::string& student_name, const std::string& course_name){
            for (Course* course: courses){
                if (course -> get_name() == course_name){
                    for (Student* student: students){
                        if (student -> get_name() == student_name){
                            student -> enroll_course(course);
                            course -> enroll_student(student);
                        }
                    }
                }
            }
        }
        void Registrar::cancelCourse(const std::string& course_name){
            for (Course* course: courses){
                if (course -> get_name() == course_name){
                    for (Student* student: students){
                        student -> drop_course(course_name);
                    }
                    Course* temp = course;
                    course = courses.back();
                    courses.back() = temp;
                    delete temp;
                    courses.pop_back();
                }
            }
        }
        void Registrar::purge(){
            for (Student* student: students){
                delete student;
            }
            students.clear();
            for (Course* course: courses){
                delete course;
            }
            courses.clear();
        }
        void Registrar::printReport() const{
            for (Course* course: courses){
                cout << "Course: " << course -> get_name() << endl;
                cout << '\t' << "Students:";
                if (course -> get_students().size() != 0){
                    for (Student* student: course -> get_students()){
                        cout << ' ' << student -> get_name();
                    }
                    cout << endl;
                }
                else{cout << " none" << endl;}
            }
            for (Student* student: students){
                cout << "Student: " << student -> get_name() << endl;
                cout << '\t' << "Courses:";
                if (student -> get_courses().size() != 0){
                    for (Course* course: student -> get_courses()){
                        cout << ' ' << course -> get_name();
                    }
                    cout << endl;
                }
                else{cout << " none" << endl;}
            }
            cout << endl;
        }
}
