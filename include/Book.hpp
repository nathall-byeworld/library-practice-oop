#pragma once
#include <string>
#include "LibraryItem.hpp"

class Book : public LibraryItem {
    private:
        int id_;
        std::string title_;
        std::string author_;
    
    public:
        Book(int id, std::string title, std::string author);
        std::string type() const override;
        std::string toString() const override;
        int getId() const override;
        std::string getTitle() const;
        std::string getAuthor() const;
};