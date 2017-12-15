#include "Student.h"
#include "Course.h"
#include <iostream>
#include <string>

using namespace std;

namespace BrooklynPoly{
    class Course;

    Student::Student(const std::string& name) : name(name) {}

    const string& Student::get_name() const{
        return name;
    }
//    Student::~Student(){
//        for (Course* course: courses){
//            course -> drop_student(name);
//            delete course;
//        }
//        courses.clear();
//    }
//    Student::Student(const Student& rhs) : name(name) {
//        for (Course* course: rhs.get_students()){
//            new_course = new Course(course -> get_name());
//            courses.push_back(new_course);
//            new_course -> enroll_student(this);
//        }
//    }
//
//    Student::Student& operator=(const Student& rhs){
//        for (Course* course: courses){
//            course.drop_student(name);
//            delete course;
//        }
//        courses.clear();
//        name = rhs.get_name()
//        for (Course* course: rhs.get_students()){
//            new_course = new Course(course -> get_name());
//            courses.push_back(new_course);
//            new_course.enroll(this);
//        }
//    }

    void Student::enroll_course(Course* course){
        courses.push_back(course);
    }

    void Student::drop_course(const string& course_name){
        int position, counter = 0;
        for (Course* course: courses){
            if (course -> get_name() == course_name){
                position = counter;
            }
            counter++;
        }
        Course* temp = courses[position];
        courses[position] = courses.back();
        courses.back() = temp;
        courses.pop_back();
    }

    vector<Course*> Student::get_courses() const{
        return courses;
    }
}
