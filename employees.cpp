#include <iostream>
#include <vector>

using namespace std;

class Employee{
protected:
    string surname;
    int age;
    string position;
    int salary;

public:
    Employee(string SN, int A, string P, int S) : surname(SN), age(A), position(P), salary(S) {}
    virtual void show_info(){
        cout<<surname<<", "<<age<<", "<<position<<", "<<salary;
    }
    int get_salary(){
        return salary;
    }
    int get_age(){
        return age;
    }
};

class Manager: public Employee{
private:
    int n_workers;
public:
    Manager(string SN, int A, string P, int S, int W) : Employee(SN, A, P, S), n_workers(W) {}
    void show_info(){
        Employee::show_info();
        cout<<", "<<n_workers<<endl;
    }
};

class Engineer: public Employee{
protected:
    string specialization;
public:
    Engineer(string SN, int A, string P, int S, string SP) : Employee(SN, A, P, S), specialization(SP) {}
    virtual void show_info(){
        Employee::show_info();
        cout<<", "<<specialization<<endl;
    }
};

class Programmer : public Engineer{
protected:
    string language;

public:
    Programmer(string SN, int A, string P, int S, string SP, string L) : Engineer(SN, A, P, S, SP), language(L) {}
    void show_info(){
        Engineer::show_info();
        cout<<", "<<language<<endl;
    }
};

int main(){
    //Write a program that stores information about 5 given employees and calculates:
    //Average salary of all employees.
    //Average age of all employees.
    //Information about the employee who has the highest salary

    string k1, k2, inz, pr4, pr5;
    int a1, a2, a3, a4, a5;
    string p1, p2, p3, p4, p5;
    int s1, s2, s3, s4, s5;
    int w1, w2;
    string spec3, spec4, spec5;
    string lang4, lang5;
    cin>>k1>>a1>>p1>>s1>>w1;
    cin>>k2>>a2>>p2>>s2>>w2;
    cin>>inz>>a3>>p3>>s3>>spec3;
    cin>>pr4>>a4>>p4>>s4>>spec4>>lang4;
    cin>>pr5>>a5>>p5>>s5>>spec5>>lang5;

    vector<Employee*> employees;

    employees.push_back(new Manager(k1, a1, p1, s1, w1));
    employees.push_back(new Manager(k2, a2, p2, s2, w2));
    employees.push_back(new Engineer(inz, a3, p3, s3, spec3));
    employees.push_back(new Programmer(pr4, a4, p4, s4, spec4, lang4));
    employees.push_back(new Programmer(pr5, a5, p5, s5, spec5, lang5));

    int avg_salary=0, avg_age=0, max_salary = 0;
    Employee *MaxSalaryEmployee = nullptr;

    for(const auto &employee : employees){
        employee->show_info();
        avg_salary += employee->get_salary();
        avg_age += employee->get_age();
        if(employee->get_salary() > max_salary){
            MaxSalaryEmployee = employee;
            max_salary = employee->get_salary();
        }
    }
    avg_salary = avg_salary/5;
    avg_age = avg_age/5;

    cout<<"statistics:"<<endl;
    cout<<"Average salary: "<<avg_salary<<endl;
    cout<<"Average age: "<<avg_age<<endl;
    cout<<"The employee with the highest salary:"<<endl;
    MaxSalaryEmployee->show_info();

    for(const auto &employee : employees){
        delete employee;
    }

    return 0;
}
