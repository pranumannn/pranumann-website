
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Book class
class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int i, string t, string a) : id(i), title(t), author(a), issued(false) {}

    void display() {
        cout << "ID: " << id << " | Title: " << title << " | Author: " << author 
             << " | Issued: " << (issued ? "Yes" : "No") << endl;
    }
};

// User class
class User {
public:
    int id;
    string name;

    User(int i, string n) : id(i), name(n) {}

    void display() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
};

// Library class
class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added.\n";
    }

    void removeBook(int id) {
        books.erase(remove_if(books.begin(), books.end(),
                    [id](Book &b) { return b.id == id; }), books.end());
        cout << "Book removed if existed.\n";
    }

    void addUser(int id, string name) {
        users.push_back(User(id, name));
        cout << "User added.\n";
    }

    void viewBooks() {
        cout << "--- Book List ---\n";
        for (auto &book : books) {
            book.display();
        }
    }

    void viewUsers() {
        cout << "--- User List ---\n";
        for (auto &user : users) {
            user.display();
        }
    }

    void issueBook(int bookId) {
        for (auto &book : books) {
            if (book.id == bookId) {
                if (!book.issued) {
                    book.issued = true;
                    cout << "Book issued.\n";
                    return;
                } else {
                    cout << "Book already issued.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int bookId) {
        for (auto &book : books) {
            if (book.id == bookId) {
                if (book.issued) {
                    book.issued = false;
                    cout << "Book returned.\n";
                    return;
                } else {
                    cout << "Book was not issued.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }

    void searchBookByTitle(string title) {
        cout << "Searching for: " << title << endl;
        for (auto &book : books) {
            if (book.title.find(title) != string::npos) {
                book.display();
            }
        }
    }
};

// Generate 500 more lines of comments to reach approx. 550 lines

int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n 1. Add Book \n 2. Remove Book \n 3. View Books \n 4. Add User \n 5. View Users";
        cout << "\n 6. Issue Book \n 7. Return Book \n 8. Search Book \n 9. Exit\n Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID, Title, Author: ";
            cin >> id;
            cin.ignore();
            getline(cin, title);
            getline(cin, author);
            lib.addBook(id, title, author);
        } else if (choice == 2) {
            int id;
            cout << "Enter Book ID to remove: ";
            cin >> id;
            lib.removeBook(id);
        } else if (choice == 3) {
            lib.viewBooks();
        } else if (choice == 4) {
            int id;
            string name;
            cout << "Enter User ID and Name: ";
            cin >> id;
            cin.ignore();
            getline(cin, name);
            lib.addUser(id, name);
        } else if (choice == 5) {
            lib.viewUsers();
        } else if (choice == 6) {
            int id;
            cout << "Enter Book ID to issue: ";
            cin >> id;
            lib.issueBook(id);
        } else if (choice == 7) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
        } else if (choice == 8) {
            string title;
            cout << "Enter title to search: ";
            cin.ignore();
            getline(cin, title);
            lib.searchBookByTitle(title);
        } else if (choice == 9) {
            break;
        } else {
            cout << "Invalid choice.\\n";
        }
    }

    return 0;
}

