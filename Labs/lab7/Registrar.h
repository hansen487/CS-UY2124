#ifndef REGISTRAR_H_INCLUDED
#define REGISTRAR_H_INCLUDED

#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"

namespace BrooklynPoly{
    class Student;
    class Course;

    class Registrar{
        public:
            Registrar();
//            ~Registrar();
//            Registrar(const Registrar& rhs);
//            Registrar& operator=(const Registrar& rhs);
            void addCourse(const std::string& course_name);
            void addStudent(const std::string& student_name);
            void enrollStudentInCourse(const std::string& student_name, const std::string& course_name);
            void cancelCourse(const std::string& course_name);
            void purge();
            void printReport() const;
        private:
            std::vector<Student*> students;
            std::vector<Course*> courses;

    };

}


#endif // REGISTRAR_H_INCLUDED
