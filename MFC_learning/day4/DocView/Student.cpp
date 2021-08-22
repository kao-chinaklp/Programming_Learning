#include "pch.h"
#include "Student.h"

Student::Student(int id = 0, CString name = TEXT(""), int age = 0, int score = 0)
{
	m_id = id;
	m_name = name;
	m_age = age;
	m_score = score;
}
