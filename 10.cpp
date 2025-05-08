
// lab10.cpp
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <algorithm>

class User {
private:
    std::string name;
    int id;
    int accessLevel;

public:
    User(std::string n, int i, int a) : name(n), id(i), accessLevel(a) {}
    virtual ~User() {}

    std::string getName() const { return name; }
    int getId() const { return id; }
    int getAccessLevel() const { return accessLevel; }

    void setName(std::string n) {
        if (n.empty()) throw std::invalid_argument("Name cannot be empty");
        name = n;
    }

    void setId(int i) { id = i; }
    void setAccessLevel(int a) {
        if (a < 0) throw std::invalid_argument("Access level must be non-negative");
        accessLevel = a;
    }

    virtual void displayInfo() const {
        std::cout << "User: " << name << ", ID: " << id << ", Access Level: " << accessLevel << std::endl;
    }
};

class Student : public User {
private:
    std::string group;

public:
    Student(std::string n, int i, int a, std::string g) : User(n, i, a), group(g) {}
    void displayInfo() const override {
        User::displayInfo();
        std::cout << "Group: " << group << std::endl;
    }
};

class Teacher : public User {
private:
    std::string department;

public:
    Teacher(std::string n, int i, int a, std::string d) : User(n, i, a), department(d) {}
    void displayInfo() const override {
        User::displayInfo();
        std::cout << "Department: " << department << std::endl;
    }
};

class Administrator : public User {
private:
    std::string position;

public:
    Administrator(std::string n, int i, int a, std::string p) : User(n, i, a), position(p) {}
    void displayInfo() const override {
        User::displayInfo();
        std::cout << "Position: " << position << std::endl;
    }
};

class Resource {
private:
    std::string name;
    int requiredAccessLevel;

public:
    Resource(std::string n, int a) : name(n), requiredAccessLevel(a) {}
    bool checkAccess(const User& user) const {
        return user.getAccessLevel() >= requiredAccessLevel;
    }
    void displayInfo() const {
        std::cout << "Resource: " << name << ", Required Access Level: " << requiredAccessLevel << std::endl;
    }
};

template<typename U, typename R>
class AccessControlSystem {
private:
    std::vector<std::shared_ptr<U>> users;
    std::vector<R> resources;

public:
    void addUser(std::shared_ptr<U> user) {
        users.push_back(user);
    }

    void addResource(const R& resource) {
        resources.push_back(resource);
    }

    void checkAllAccess() const {
        for (const auto& user : users) {
            for (const auto& resource : resources) {
                std::cout << user->getName() << " access to " << resource.checkAccess(*user) << std::endl;
            }
        }
    }
};

int main() {
    AccessControlSystem<User, Resource> system;
    system.addUser(std::make_shared<Student>("Alice", 1, 1, "PI-21"));
    system.addUser(std::make_shared<Teacher>("Bob", 2, 2, "Math"));
    system.addUser(std::make_shared<Administrator>("Carol", 3, 3, "Security"));

    system.addResource(Resource("Library", 1));
    system.addResource(Resource("Lab", 2));
    system.addResource(Resource("Server Room", 3));

    for (const auto& user : {"Alice", "Bob", "Carol"}) {
        std::cout << "Checking access for " << user << "..." << std::endl;
    }

    return 0;
}
