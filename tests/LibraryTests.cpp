#include "Library.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>

int main() {
    Library library;

    int bookId = library.addBook("Harry Potter", "J.K. Rowling");
    int magazineId =
        library.addMagazine("Science Monthly", "Alex Smith", "Science Inc.");

    assert(bookId == 1);
    assert(magazineId == 2);
    assert(library.getItemCount() == 2);

    const LibraryItem& item = library.findItem(bookId);
    assert(item.type() == "Book");

    library.addMember("Nathan");
    assert(library.getMemberCount() == 1);

    library.borrowItem(bookId, 1);
    assert(library.getLoanCount() == 1);
    assert(library.isItemBorrowed(bookId));

    bool exceptionThrown = false;

    try {
        library.borrowItem(bookId, 1);
    } catch (const std::runtime_error&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    library.returnItem(bookId);

    assert(library.getLoanCount() == 0);
    assert(!library.isItemBorrowed(bookId));

    try {
        library.returnItem(bookId);
    } catch (const std::runtime_error& error) {
        std::cout << error.what() << " error\n";
    }

    library.borrowItem(bookId, 1);
    assert(library.isItemBorrowed(bookId));

    std::cout << "All tests passed\n";
}