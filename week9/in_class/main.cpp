#include <iostream>
#include <string>

using namespace std;

class person {
private:
    string name;
    string address;
    int age;
public:
    person( string name = "", string address = "", int age = 0 ): name(name), address(address), age(age) {}
    string getName() {return name;}
    virtual int getAge() {return age;}

};

class student : public person {
private:
    int lnum;
    string major;
public:
    student( string name = "", string address = "", int age = 0, int lnum = 0, string major = "" ):
        person(name,address,age), lnum(lnum), major(major) {}
    int getLnum() {return lnum;}
};


int main() {

    student alpha("alpha", "mars", 26, 00237467);
    cout << alpha.getName() << " " << alpha.getAge() << " " << alpha.getLnum();

    return 0;
}
