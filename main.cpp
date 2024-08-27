#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }

    void displayBook() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Issued: " << (isIssued ? "Yes" : "No") << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    Library() {
        
        books.push_back(Book(101, "The Catcher in the Rye", "J.D. Salinger"));
        books.push_back(Book(102, "To Kill a Mockingbird", "Harper Lee"));
        books.push_back(Book(103, "1984", "George Orwell"));
        books.push_back(Book(104, "Pride and Prejudice", "Jane Austen"));
        books.push_back(Book(105, "The Great Gatsby", "F. Scott Fitzgerald"));
    }

    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!" << endl;
    }

    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }

        for (auto &book : books) {
            book.displayBook();
            cout << "------------------------" << endl;
        }
    }

    void searchBookById() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        for (auto &book : books) {
            if (book.id == id) {
                book.displayBook();
                return;
            }
        }

        cout << "Book not found!" << endl;
    }

    void deleteBookById() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }

        cout << "Book not found!" << endl;
    }
};

int main() {
    cout << "Welcome to the Library Management System" << endl;
    cout << "Created by Saurabh" << endl;
    cout << "---------------------------------------" << endl;

    Library library;
    int choice;

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book by ID" << endl;
        cout << "4. Delete Book by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayAllBooks();
                break;
            case 3:
                library.searchBookById();
                break;
            case 4:
                library.deleteBookById();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}
