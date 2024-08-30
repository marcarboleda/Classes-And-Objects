#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    // Constructor to initialize a Book object
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Function to get the title of the book
    string getTitle() const {
        return title;
    }

    // Function to display the details of the book
    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

class Library {
private:
    vector<Book*> books; // Vector to store pointers to Book objects

public:
    // Constructor to initialize the Library object
    Library() {}

    // Function to add a new book to the library
    void addBook() {
        string title, author;
        int year;

        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter author: ";
        getline(cin, author);

        cout << "Enter year: ";
        cin >> year;

        // Dynamically allocate a new Book object and add it to the vector
        books.push_back(new Book(title, author, year));
        cout << "\nBook added successfully!" << endl;
    }

    // Function to display all books in the library
    void displayBooks() const {
        cout << "\nBook List:" << endl;
        cout << "Title            Author           Year" << endl;
        for (const auto& book : books) {
            cout << book->title << "     " << book->author << "    " << book->year << endl;
        }
    }

    // Function to search for a book by its title
    void searchBookByTitle(const string& title) const {
        bool found = false;
        for (const auto& book : books) {
            if (book->getTitle() == title) {
                cout << "\nBook found!" << endl;
                book->displayBookDetails(); // Display book details
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nBook not found!" << endl; // Output if the book is not found
        }
    }

    // Function to ask the user to input the title of the book for the search
    void searchBook() {
        string title;
        cout << "\nEnter the title of the book to search: ";
        cin.ignore();
        getline(cin, title);
        searchBookByTitle(title);
    }

    // Destructor to free allocated memory
    ~Library() {
        for (auto& book : books) {
            delete book; // Delete each dynamically allocated Book object
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nMenu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Process the user's choice
        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}