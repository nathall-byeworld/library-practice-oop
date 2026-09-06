#pragma once
#include <string>

class LibraryItem {
    public:
        virtual int getId() const = 0; 
        virtual std::string type() const = 0; 
        virtual std::string toString() const = 0;
        virtual ~LibraryItem() = default;
};