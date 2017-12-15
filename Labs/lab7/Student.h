#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "Course.h"
#include <iostream>
#include <string>

namespace BrooklynPoly{
    class Course;

    class Student{
    public:
        Student(const std::string& name);
//        ~Student();
//        Student(const Student& rhs);
//        Student& operator=(const Student& rhs);
        const std::string& get_name() const;
        void enroll_course(Course* course);
        void drop_course(const std::string& course_name);
        std::vector<Course*> get_courses() const;

    private:
        const std::string name;
        std::vector<Course*> courses;
    };
}



#endif // STUDENT_H_INCLUDED
