// 23_다형성3.cpp
#include <iostream>
using namespace std;

#if 0
class Dog
{
};
class Cat
{
};

#include <vector>

int main()
{
    vector<Dog *> dogs;
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);

    // dogs.push_back(new Cat); // ERROR
    vector<Cat *> cats;
    cats.push_back(new Cat);
    cats.push_back(new Cat);
    cats.push_back(new Cat);
}
#endif

class Animal
{
};

class Dog : public Animal
{
};
class Cat : public Animal
{
};

#include <vector>

int main()
{
    // 활용 2. 동종을 보관하는 컨테이너
    vector<Animal *> animals;
    animals.push_back(new Dog);
    animals.push_back(new Dog);
    animals.push_back(new Dog);

    animals.push_back(new Cat);
    animals.push_back(new Cat);
    animals.push_back(new Cat);
}