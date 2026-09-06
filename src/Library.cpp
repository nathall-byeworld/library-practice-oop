#include "Library.hpp"
#include <stdexcept>
#include <string>

int Library::addBook(std::string title, std::string author) {
    items_.push_back(
        std::make_unique<Book>(nextItemId_, title, author)
    );  
    return nextItemId_++;
}
int Library::addMagazine(std::string title, std::string author, std::string company) {
    items_.push_back(
        std::make_unique<Magazine>(nextItemId_, title, author, company)
    );  
    return nextItemId_++;
}
int Library::addMember(std::string name_) {
    members_.emplace_back(nextMemberId_, name_);
    return nextMemberId_++;
}
std::string Library::toString() const {
    std::string str = "Library has items: [";
    for(const auto& item : items_){
        str += item->toString();
        str += " | ";
    }
    str += "] and members: [";
    for(const Member& member : members_){
        str += member.toString();
        str += " | ";
    }
    str += "]";
    return str;
}
bool Library::isItemBorrowed(int itemId) const {
    for (const Loan& loan : loans_){
        if (loan.getItemId() == itemId){
            return true;
        }
    }
    return false;
}
void Library::borrowItem(int itemId, int memberId) {
    bool itemIdExists = false;
    bool memberIdExists = false;

    for (const auto& item : items_){
        if (item->getId() == itemId){
            itemIdExists = true;
        }
    }
    for(const Member& member : members_){
        if (member.getId() == memberId){
            memberIdExists = true;
        }
    }
    if(!itemIdExists){
        throw std::runtime_error("Item Id does not exist");
    }
    if(!memberIdExists){
        throw std::runtime_error("Member Id does not exist");
    }
    
    bool itemIdBorrowed = isItemBorrowed(itemId);
    if(itemIdBorrowed == true){
        throw std::runtime_error("Item already borrowed");
    }

    loans_.emplace_back(itemId, memberId);
}
std::size_t Library::getItemCount() const {
    return items_.size();
}
std::size_t Library::getMemberCount() const {
    return members_.size();
}
std::size_t Library::getLoanCount() const {
    return loans_.size();
}
void Library::returnItem(int itemId) {
    bool itemIdExists = false;

    for (auto it = loans_.begin(); it != loans_.end(); it++){
        if (it->getItemId() == itemId){
            loans_.erase(it);
            itemIdExists = true;
            return;
        }
    }
    
    throw std::runtime_error("Tried to return item, item not found");
}
LibraryItem& Library::findItem(int itemId) {
    bool itemIdExists = false;

    for (auto it = items_.begin(); it != items_.end(); it++){
        if ((*it)->getId() == itemId){
            itemIdExists = true;
            return *(*it);
        }
    }
    
    throw std::runtime_error("Tried to find item, item not found");
}