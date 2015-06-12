#include <iostream>
#include<stdexcept>
using namespace std;
#include"Vector.h"
#include"student.h"
int main()
{
    try{
    Student st1("Ivan", 20);
    Student st2("Petur", 20);
    Vector<Student> students;
    students.push_back(st1);
    students.push_back(st2);
    cout<<students[0].getName()<<endl;
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(13);
    v1.push_back(37);
    v1.push_back(73);
    v1.push_back(121);
    v1.push_back(181);
    v1.push_back(253);
    cout<<"old capacity: "<<v1.capacity()<<endl;
    v1.reserve(10);
    cout<<"capacity after reserve: "<<v1.capacity()<<endl;
    v1.shring_to_fit();
    cout<<"capacity after shring_to_fit: "<<v1.capacity()<<endl;
    cout << v1.back() << endl; //253
    v1.pop_back();
    cout << v1.back() << endl; //181
    cout << v1[4] << endl; //121
    v1.push_back(777);
//Извежда 1 13 37 73 121 181 777
   cout<<"old size:"<<v1.size()<<endl;
   v1.resize(10);
   cout<<"size after resize: "<<v1.size()<<endl;
   cout<<"vector after resize:"<<endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    Vector<string> v2;
    v2.push_back("Aut viam");
    v2.push_back("inveniam");
    v2.push_back("aut faciam");
//Извежда Aut viam inveniam aut faciam
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    Vector<string> v3;
    v3.push_back("Aut");
    v3.push_back("vincere");
    v3.push_back("mori");
    v3.insert(2, "aut");
//Извежда Aut vincere aut mori
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << endl;
    //v2=v3;
    v2.swap(v3);
    v2.erase(0);
//Извежда vincere aut mori
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    while(!v2.empty()) {cout<<v2[0]<<endl;v2.erase(0);}}
    catch(const std::invalid_argument & ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}
