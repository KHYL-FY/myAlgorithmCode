#include <iostream>

using namespace std;

class Student
{

public:
    Student(string _name, int _score);

    static float average();

    static float total_score;

    static int count;

private:
    string name;

    float score;
};
float Student::total_score = 0;
int Student::count = 0;
/**********************************************/
Student::Student(string _name, int _score) : name(_name), score(_score)
{
    total_score += score;
    count++;
}
float Student::average()
{
    float a = total_score / count;
    return a;
}
/**********************************************/

int main()
{

    string name;

    float score;

    cout << "input name,socre:";

    cin >> name >> score;

    Student stu1(name, score);

    cout << "input name,socre:";

    cin >> name >> score;

    Student stu2(name, score);

    cout << "input name,socre:";

    cin >> name >> score;

    Student stu3(name, score);

    cout << "total_socre:" << Student::total_score << ",average:" << Student::average() << endl;

    return 0;
}