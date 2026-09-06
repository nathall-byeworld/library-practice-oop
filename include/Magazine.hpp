#pragma once
#include <string>
#include "LibraryItem.hpp"

class Magazine : public LibraryItem {
    private:
        int id_;
        std::string title_;
        std::string author_;
        std::string company_;
    
    public:
        Magazine(int id, std::string title, std::string author, std::string company);
        std::string type() const override;
        std::string toString() const override;
        int getId() const override;
        std::string getTitle() const;
        std::string getAuthor() const;
        std::string getCompany() const;
};