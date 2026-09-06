#include "Loan.hpp"

Loan::Loan(int itemId, int memberId) : 
    itemId_(itemId), memberId_(memberId) {
}
int Loan::getItemId() const {
    return itemId_;
}
int Loan::getMemberId() const {
    return memberId_;
}
std::string Loan::toString() const {
    return "Member Id: " + std::to_string(memberId_) + 
        " borrows Item Id: " + std::to_string(itemId_);
}