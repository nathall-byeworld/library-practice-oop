#include "Library.hpp"
#include <iostream>
#include <stdexcept>

int main(){
    try {
        Library library;
        library.addBook("Harry Potter", "JJJameson");
        library.addMember("nathall");
        
        std::cout << library.toString() << "\n\n";

        library.addBook("Furry indo", "BangJo");
        library.addMember("Bang joko");
        std::cout << library.toString() << "\n\n";

        library.addMagazine("Ini magazine", "Mathan Mallan", "Magzori");
        std::cout << library.toString() << "\n\n";

        std::cout << "\nMulai borrow\n";
        library.borrowItem(1, 1);
        std::cout << "Loan count: " << library.getLoanCount() << "\n\n";
        
        std::cout << "Try returning 1\n";
        library.returnItem(1);
        std::cout << "Loan count: " << library.getLoanCount() << "\n\n";

        library.borrowItem(1, 1);
        std::cout << "Loan count: " << library.getLoanCount() << "\n\n";

        LibraryItem& item = library.findItem(2);
        std::cout << "this item: " << item.toString() << "\n\n";
        
    } catch (const std::invalid_argument& error){
        std::cout << "Invalid argument: " << error.what() << '\n';
    } catch (const std::runtime_error& error){
        std::cout << "Runtime error: " << error.what() << '\n';
    }

    //     Member uhm2(2, "");
    // try {
    //     // Member uhm(2, "");
    // } catch (const std::invalid_argument& error){
    //     std::cout << error.what() << '\n';
    // }
}