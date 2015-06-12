#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student
{
public:
Student() : m_name("Georgi"), m_age(19) {}
Student(string name, int age) : m_name(name), m_age(age) {}
string getName() {return m_name;}
private:
string m_name;
int m_age;
};

#endif // STUDENT_H_INCLUDED
