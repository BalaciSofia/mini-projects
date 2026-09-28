#pragma once
#include "repo/repo.h"
#include "repo/undo_redo.h"

class Controller_admin {
private:
    Repository &repo;
    undo_redo undo_redo;
public:
    Controller_admin(Repository &repo);
    void Add_Dog(int age,std::string name,std::string breed,std::string photograph);
    void Remove_Dog(std::string name);
    void Update_name(std::string name,std::string new_name);
    void Update_age(std::string name,int age);
    void Update_photograph(std::string name,std::string new_photograph);
    int Search_name(std::string name);
    std::vector<Dog>& get_dogs_controller();
    void undo();
    void redo();
};

class Controller_adminError : public std::exception {
private:
    std::string message;
public:
    Controller_adminError(const std::string& message) : message{message} {}
    const char* what() {
        return message.c_str();
    }
};
