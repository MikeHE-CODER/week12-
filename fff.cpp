#include <iostream>
#include <string>

using namespace std;

// 基类：动物
class Animal
{
public:
    Animal(const string &name) : name(name)
    {
        cout << "Animal constructor called for " << name << endl;
    }

    // 拷贝构造函数
    Animal(const Animal &other) : name(other.name)
    {
        cout << "Animal copy constructor called for " << other.name << endl;
    }

    // 虚析构函数
    virtual ~Animal()
    {
        cout << "Animal destructor called for " << name << endl;
    }

    // 虚函数，展示多态性
    virtual void Speak() const
    {
        cout << name << " is an animal and doesn't know how to speak." << endl;
    }

protected:
    string name;
};

// 派生类：狗
class Dog : public Animal
{
public:
    Dog(const string &name, const string &breed) : Animal(name), breed(breed)
    {
        cout << "Dog constructor called for " << name << endl;
    }

    // 拷贝构造函数
    Dog(const Dog &other) : Animal(other), breed(other.breed)
    {
        cout << "Dog copy constructor called for " << other.name << endl;
    }

    // 覆盖基类的虚函数，展示多态性
    void Speak() const override
    {
        cout << name << " barks. Breed: " << breed << endl;
    }

    // 虚析构函数（继承自基类）
    ~Dog()
    {
        cout << "Dog destructor called for " << name << endl;
    }

private:
    string breed; // 狗的品种
};

int main()
{
    // 基类指针指向派生类对象，展示多态性
    Animal *animalPtr = new Dog("Buddy", "Golden Retriever");
    Dog originalDog("Max", "Beagle");
    Dog copiedDog = originalDog; // 调用拷贝构造函数
    copiedDog.Speak();

    return 0;
}
