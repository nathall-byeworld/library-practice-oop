#include "Book.hpp"
#include <string>
#include <stdexcept>

Book::Book(int id, std::string title, std::string author) : 
    id_(id), title_(title), author_(author) {
    
    if(id_ <= 0){
        throw std::invalid_argument("Book Id needs to be positive");
    }
    if(title_.empty()){
        throw std::invalid_argument("Book title cannot be empty");
    }
    if(author_.empty()){
        throw std::invalid_argument("Book author cannot be empty");
    }
}
int Book::getId() const {
    return id_;
}
std::string Book::getTitle() const {
    return title_;
}
std::string Book::getAuthor() const {
    return author_;
}
std::string Book::toString() const {
    return "Book title: " + title_ + "; id: " + 
        std::to_string(id_) + "; author: " + author_;
}
std::string Book::type() const {
    return "Book";
}