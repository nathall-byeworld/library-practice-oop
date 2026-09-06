#pragma once
#include <string>

class Member {
    private:
        int id_;
        std::string name_;
    
    public:
        Member(int id, std::string name);
        std::string toString() const; 
        int getId() const;
        std::string getName() const;
};