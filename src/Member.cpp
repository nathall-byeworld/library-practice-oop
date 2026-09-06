#include "Member.hpp"
#include "Book.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

Member::Member(int id, std::string name) : 
    id_(id), name_(name) {
    if(id_ <= 0){
        throw std::invalid_argument("Member Id needs to be positive");
    }
    if(name_.empty()){
        throw std::invalid_argument("Member name cannot be empty");
    }
}
int Member::getId() const {
    return id_;
}
std::string Member::getName() const {
    return name_;
}
std::string Member::toString() const {
    return "Member name: " + name_ + "; id: " + 
        std::to_string(id_);
}