#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <algorithm>

struct Student
{
    std::string name{""};
    int grade{ 0 };
};

void assignGrade(std::vector<Student>& students)
{
    for (int studentNum{ 1 }; Student& student : students)
    {

        std::cout << "What is the name of student #" << studentNum << "?\n";
        std::cin >> student.name;

        std::cout << "What is the grade of student #" << studentNum << "?\n";
        std::cin >> student.grade;

        ++studentNum;
    }
}

bool compareStudents(const Student& a, const Student& b)
{
    return (a.grade > b.grade);
}

int main()
{
    int numStudents;
    std::cout << "How many students would you like to enter?\n";
    std::cin >> numStudents;
    std::vector<Student> students(numStudents);
    assignGrade(students);
    std::sort(students.begin(), students.end(), compareStudents);
    for (const Student& student : students)
    {
        std::cout << student.name << " got a grade of " << student.grade << '\n';
    }
    return 0;
}

