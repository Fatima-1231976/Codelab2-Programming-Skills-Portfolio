#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Book
{
public:
    string title, author, id;
    int pages;
    bool borrowed;

    Book(string t, string a, int p, string i, bool b)
    {
        title = t;
        author = a;
        pages = p;
        id = i;
        borrowed = b;
    }

    void display()
    {
        cout << "\nTitle: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
        cout << "ID: " << id << endl;
        cout << "Borrowed: " << (borrowed ? "Yes" : "No") << endl;
    }
};

int main()
{
    vector<Book> books;
    ifstream file("bookData.txt");

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string title, author, pagesStr, id, borrowedStr;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, pagesStr, ',');
        getline(ss, id, ',');
        getline(ss, borrowedStr);

        books.push_back(
            Book(title, author, stoi(pagesStr), id,
                 borrowedStr == "true"));
    }

    file.close();

    int choice;

    do
    {
        cout << "\n===== LIBRARY MENU =====" << endl;
        cout << "1. View All Books" << endl;
        cout << "2. View Individual Book" << endl;
        cout << "3. Borrow Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            for (auto &book : books)
                book.display();
        }
        else if (choice == 2)
        {
            string id;
            cout << "Enter Book ID: ";
            cin >> id;

            for (auto &book : books)
            {
                if (book.id == id)
                    book.display();
            }
        }
        else if (choice == 3)
        {
            string id;
            cout << "Enter Book ID: ";
            cin >> id;

            for (auto &book : books)
            {
                if (book.id == id)
                {
                    if (!book.borrowed)
                    {
                        book.borrowed = true;
                        cout << "Book borrowed successfully!" << endl;
                    }
                    else
                    {
                        cout << "Book already borrowed!" << endl;
                    }
                }
            }
        }
        else if (choice == 4)
        {
            string id;
            cout << "Enter Book ID: ";
            cin >> id;

            for (auto &book : books)
            {
                if (book.id == id)
                {
                    if (book.borrowed)
                    {
                        book.borrowed = false;
                        cout << "Book returned successfully!" << endl;
                    }
                    else
                    {
                        cout << "Book is already available!" << endl;
                    }
                }
            }
        }

    } while (choice != 5);

    return 0;
}