#include "GradeMap.h"

#include <algorithm>

char& GradeMap::operator[](std::string name)
{
	auto exists{ std::find_if(m_map.begin(), m_map.end(),
		[&](const auto& student)
		{
			return (name == student.name);
		}) 
	};

	if (exists != m_map.end())
	{
		return exists->grade;
	}

	m_map.push_back({ std::string {name} });

	return m_map.back().grade;
}