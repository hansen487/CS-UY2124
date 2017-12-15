#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>

namespace BrooklynPoly{
    class Student;

    class Course{
        public:
            Course(const std::string& name);
//            ~Course();
//            Course(const Course& rhs);
//            Course& operator=(const Course& rhs);
            void enroll_student(Student* student);
            void drop_student(const std::string& student_name);
            const std::string& get_name() const;
            std::vector<Student*> get_students() const;

        private:
            const std::string c_name;
            std::vector<Student*> students;

    };
}


#endif // COURSE_H_INCLUDED
