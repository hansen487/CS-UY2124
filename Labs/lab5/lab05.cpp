//Hansen Chen CS Lab grades
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int weeks = 14;

class Student{
public:
	Student(const string& name) : name(name), grades (14, -1){}

	void display() const{
		cout << "Name: " << name << ", Grades: ";
		for (int grade: grades){
			cout << grade << ' ';
		}
		cout << endl;
	}

	void setGrade(int grade, int week){
		grades[week - 1] = grade;
	}

	string get_name() const{
		return name;
	}

	vector<int> get_grades() const{
		return grades;
	}

private:
	string name;
	vector<int> grades;
};

class Section{
public:
	Section(const string& section, const string& day, int time) : section_name(section), timeslot(day, time) {}
	~Section() {
		cout << "deleting students in Section " << section_name << endl;
		for (Student* student: students){
			delete student;
		}
	}
	Section(const Section &section) : section_name(section.section_name), timeslot(section.timeslot.get_day(), section.timeslot.get_t()){
		for (Student* student: section.students){
			Student* student_copy = new Student(*student);
			students.push_back(student_copy);
		}
	}
	void display() const{
		cout << "Section: " << section_name << ", Time slot: [Day: " << timeslot.get_day() << ", Start time: "
		<< timeslot.get_time() << "], Students: ";
		if (students.size() == 0){
			cout << "None" << endl;
		}
		else{
			cout << endl;
			for (Student* student: students){
				student -> display();
			}
		}
	}



	void addStudent(const string& student_name){
		Student* student = new Student(student_name);
		//Student student(student_name);
		students.push_back(student);
	}

	vector<Student*> get_class() const {
		return students;
	}
private:
	class TimeSlot{
	public: 
		TimeSlot() {}
		TimeSlot(const string& day, int time) : day(day), time(time) {}

		string get_day() const {
			return day;
		}

		string get_time() const{
			string am_pm = "am";
				if (time >= 12){
					am_pm = "pm";
				}
			string string_time = to_string(time%12);
			return string_time + am_pm;
		}

		int get_t() const {
			return time;
		}
	private:
		string day;
		int time;
	};
	string section_name;
	TimeSlot timeslot;
	vector<Student*> students;
};

class LabWorker{
public:
	LabWorker(const string& name) : name(name) {}

	void addSection(Section& class_section){
		section = &class_section;
	}

	void display() const{
		if (section == nullptr){
			cout << name << " does not have a section" << endl;
		}
		else{
			cout << name << " has ";
			section -> display();
		}
	}

	void addGrade(const string& student_name, int grade, int week){
		for (Student* student: section -> get_class()){
			if (student -> get_name() == student_name){
				student -> setGrade(grade, week);
			}
		}
	}


private:
	string name;
	Section* section = nullptr;
};

void doNothing(Section sec) { sec.display(); }

int main() {

    // cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    // secA2.display();

    // cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    // secA2.display();

    // cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    // moe.display();

    // cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    // moe.display();

    // cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    //jane.display();

    //cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);  
    moe.addGrade("Paul", 19, 1);  
    moe.addGrade("George", 16, 1);  
    moe.addGrade("Ringo", 7, 1);  
    //moe.display();

    //cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);  
    moe.addGrade("Paul", 20, 3);  
    moe.addGrade("Ringo", 0, 3);  
    moe.addGrade("George", 16, 3);  
    //moe.display();

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, then make sure the following call works\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main