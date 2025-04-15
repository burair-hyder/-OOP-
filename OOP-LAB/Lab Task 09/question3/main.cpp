#include <iostream>
#include "Book.h"

int main() {
    Book mybook("MY friend","123123","burair hyder");
        Book mybook1("MY friend","123123","burair hyder");
        Library l1;
        l1.addbook();
        l1.addbook();
        l1.searchbook();
    cout <<mybook.getAuthor()<<endl;
    cout <<mybook.getTitle()<<endl;
    cout <<mybook.getISBN()<<endl;
    return 0;
}
