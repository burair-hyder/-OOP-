#include <iostream>
#include <string>
#include <exception>
using namespace std;

class FileException : public exception {
protected:
    string message;
public:
    FileException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileNotFoundException : public FileException {
public:
    FileNotFoundException() : FileException("FileNotFoundException - File not found!") {}
};

class PermissionDeniedException : public FileException {
public:
    PermissionDeniedException() : FileException("PermissionDeniedException - Access denied!") {}
};

void readFile(const string& filename) {
    if (filename == "missing.txt") {
        throw FileNotFoundException();
    } else if (filename == "secret.txt") {
        throw PermissionDeniedException();
    } else {
        cout << "Reading '" << filename << "': Success!" << endl;
    }
}

int main() {
    string filename = "secret.txt";
    cout << "Reading '" << filename << "': ";
    try {
        readFile(filename);
    }
    catch (PermissionDeniedException& e) {
        cout << e.what() << endl;
    }
    catch (FileNotFoundException& e) {
        cout << e.what() << endl;
    }
    catch (FileException& e) {  // catch base class
        cout << e.what() << endl;
    }
    return 0;
}
