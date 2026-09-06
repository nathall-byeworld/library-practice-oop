#pragma once
#include <string>

class Loan {
    private:
        int itemId_;
        int memberId_;
    
    public:
        Loan(int itemId, int memberId);
        std::string toString() const; 
        int getItemId() const;
        int getMemberId() const;
};