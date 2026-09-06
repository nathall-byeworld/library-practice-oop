#include "Magazine.hpp"
#include <string>
#include <stdexcept>

Magazine::Magazine(int id, std::string title, std::string author, std::string company) : 
    id_(id), title_(title), author_(author), company_(company) {
    
    if(id_ <= 0){
        throw std::invalid_argument("Magazine Id needs to be positive");
    }
    if(title_.empty()){
        throw std::invalid_argument("Magazine title cannot be empty");
    }
    if(author_.empty()){
        throw std::invalid_argument("Magazine author cannot be empty");
    }
    if(company_.empty()){
        throw std::invalid_argument("Magazine company cannot be empty");
    }
}
int Magazine::getId() const {
    return id_;
}
std::string Magazine::getTitle() const {
    return title_;
}
std::string Magazine::getAuthor() const {
    return author_;
}
std::string Magazine::getCompany() const {
    return company_;
}
std::string Magazine::toString() const {
    return "Magazine title: " + title_ + "; id: " + 
        std::to_string(id_) + "; author: " + author_ + "; company: " + company_;
}
std::string Magazine::type() const {
    return "Magazine";
}