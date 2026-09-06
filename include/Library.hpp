#pragma once
#include "Book.hpp"
#include "Magazine.hpp"
#include "Member.hpp"
#include "Loan.hpp"
#include <vector>
#include <string>
#include <memory>

class Library {
    private:
        std::vector <std::unique_ptr<LibraryItem>> items_;
        std::vector <Member> members_;
        std::vector <Loan> loans_;
        int nextItemId_ = 1;
        int nextMemberId_ = 1;
    
    public:
        int addBook(std::string title_, std::string author_);
        int addMagazine(std::string title_, std::string author_, std::string company_);
        int addMember(std::string name_);
        void borrowItem(int itemId, int memberId);
        std::string toString() const; 
        std::size_t getItemCount() const;
        std::size_t getMemberCount() const;
        std::size_t getLoanCount() const;
        bool isItemBorrowed(int itemId) const;
        void returnItem(int itemId);
        LibraryItem& findItem(int itemId);
};