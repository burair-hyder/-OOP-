#include <iostream>
using namespace std;

class Media {
protected:
    string mediaTitle, releaseDate, mediaID, mediaPublisher;

public:
    Media(string title, string date, string id, string publisher)
        : mediaTitle(title), releaseDate(date), mediaID(id), mediaPublisher(publisher) {}

    virtual void displayInfo() const {
        cout << "Title: " << mediaTitle << "\nRelease Date: " << releaseDate
             << "\nUnique ID: " << mediaID << "\nPublisher: " << mediaPublisher << endl;
    }

    void checkOut() {
        cout << mediaTitle << " has been checked out.\n";
    }

    void returnItem() {
        cout << mediaTitle << " has been returned.\n";
    }
};

class Book : public Media {
private:
    string authorName, bookISBN;
    int totalPages;

public:
    Book(string title, string date, string id, string publisher, string author, string isbn, int pages)
        : Media(title, date, id, publisher), authorName(author), bookISBN(isbn), totalPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << authorName << "\nISBN: " << bookISBN << "\nTotal Pages: " << totalPages << endl;
    }
};

class DVD : public Media {
private:
    string movieDirector;
    double movieDuration;
    string ageRating;

public:
    DVD(string title, string date, string id, string publisher, string director, double duration, string rating)
        : Media(title, date, id, publisher), movieDirector(director), movieDuration(duration), ageRating(rating) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << movieDirector << "\nDuration: " << movieDuration << " hours\nRating: " << ageRating << endl;
    }
};

class CD : public Media {
private:
    string musicArtist;
    int trackCount;
    string musicGenre;

public:
    CD(string title, string date, string id, string publisher, string artist, int tracks, string genre)
        : Media(title, date, id, publisher), musicArtist(artist), trackCount(tracks), musicGenre(genre) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << musicArtist << "\nNumber of Tracks: " << trackCount << "\nGenre: " << musicGenre << endl;
    }
};

int main() {
    Book book1("C++ Programming", "2023", "B001", "TechPub", "Bjarne Stroustrup", "123-456-789", 450);
    DVD dvd1("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 2.5, "PG-13");
    CD cd1("Greatest Hits", "2020", "C001", "Sony Music", "The Beatles", 15, "Rock");

    cout << "\n--- Book Info ---\n";
    book1.displayInfo();

    cout << "\n--- DVD Info ---\n";
    dvd1.displayInfo();

    cout << "\n--- CD Info ---\n";
    cd1.displayInfo();

    return 0;
}
