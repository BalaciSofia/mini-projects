
#include "controller_admin.h"
#include <iostream>
#include <utility>
#include "domain/domain.h"

Controller_admin::Controller_admin(Repository &repo) : repo(repo) {}


void Controller_admin::Add_Dog(int age,std::string name,std::string breed,std::string photograph) {
    /*
     *adds a dog to the repo
     *param age:age of the dog
     *param name:name of the dog
     *param breed:breed of the dog
     *param photograph:photograph of yhe dog
     */
    Dog dog=Dog(breed,name,age,photograph);
    auto cmd = std::make_unique<AddCommand>(repo, dog);
    undo_redo.executeCommand(std::move(cmd));
}


void  Controller_admin::Remove_Dog(std::string name) {
    /*
     *removes a dog from the repo
     *pram name: name of the dog to be removed
     */
    int index = this->repo.search_dog_name(name);
    if (index == -1)
        throw Controller_adminError("Dog not found");
    auto cmd = std::make_unique<RemoveCommand>(repo,this->repo.get_dogs()[index]);
    undo_redo.executeCommand(std::move(cmd));
}
void Controller_admin:: Update_name(std::string name,std::string new_name) {
    /*
     *updates a dogs name
     */
    int index=this->repo.search_dog_name(name);
    if (index==-1)
        throw Controller_adminError("Dog not found");
    Dog d=Dog(this->repo.get_dogs()[index].get_breed(),new_name,this->repo.get_dogs()[index].get_age(),this->repo.get_dogs()[index].get_photograph());
    DogValidator validator;
    validator.validate(d);
    auto cmd = std::make_unique<UpdateNameCommand>(repo, this->repo.get_dogs()[index],name, new_name);
    undo_redo.executeCommand(std::move(cmd));
}
void Controller_admin:: Update_age(std::string name,int age) {
    /*
     *updates a dogs age
     */
    int index=this->repo.search_dog_name(name);
    if (index==-1)
        throw Controller_adminError("Dog not found");
    auto cmd = std::make_unique<UpdateAgeCommand>(repo, this->repo.get_dogs()[index],age);
    undo_redo.executeCommand(std::move(cmd));
}
void Controller_admin:: Update_photograph(std::string name,std::string new_photograph) {
    /*
     *updates a dogs photograph
     */
    int index=this->repo.search_dog_name(name);
    if (index==-1)
        throw Controller_adminError("Dog not found");
    auto cmd = std::make_unique<UpdatePhotographCommand>(repo, this->repo.get_dogs()[index],new_photograph);
    undo_redo.executeCommand(std::move(cmd));
}

std::vector<Dog>& Controller_admin::get_dogs_controller() {
    return this->repo.get_dogs();
}

int Controller_admin::Search_name(std::string name) {
    return this->repo.search_dog_name(name);
}
void Controller_admin::undo() {
    this->undo_redo.undo();
}

void Controller_admin::redo() {
    this->undo_redo.redo();
}

