#ifndef GRADEMAP_H
#define GRADEMAP_H
#include <string>
#include <vector>

struct StudentGrade
{
	std::string name{};
	char grade{};
};

class GradeMap
{
public:
	char& operator[](std::string name);

private:
	std::vector<StudentGrade> m_map{};
};
#endif
