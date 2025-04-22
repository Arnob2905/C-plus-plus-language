#include <iostream>
#include <string>
#include <regex>
using namespace std;

class LibraryItem 
{
private:
    string title, author, dueDate;  

public:
    string getTitle() const 
    {
        return title; 
        
    }
    string getAuthor() const 
    {
        return author; 
        
    }
    string getDueDate() const 
    {
        return dueDate; 
        
    }

    void setTitle(string newTitle) 
    {
        title = newTitle; 
        
    }
    void setAuthor(string newAuthor) 
    {
        author = newAuthor; 
        
    }
    void setDueDate(string newDueDate) 
    {
        dueDate = newDueDate; 
        
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() 
    {
        
    }
};

class Book : public LibraryItem     
{
private:
    string isbn;

public:
    Book(string title, string author, string dueDate, string isbn) 
    {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        if (!regex_match(isbn, regex("\\d{3}-\\d{10}"))) 
        {
            throw invalid_argument("Invalid ISBN format. Use XXX-XXXXXXXXXX format.");
        }
        this->isbn = isbn;
    }

    void checkOut() override 
    {
        cout << "Book '" << getTitle() << "' checked out.\n";
    }

    void returnItem() override 
    {
        cout << "Book '" << getTitle() << "' returned.\n";
    }

    void displayDetails() const override 
    {
        cout << "Book Title: " << getTitle() << ", Author: " << getAuthor()
             << ", Due Date: " << getDueDate() << ", ISBN: " << isbn << endl;
    }
};

class DVD : public LibraryItem 
{
private:
    int duration;   

public:
    DVD(string title, string author, string dueDate, int duration) 
    {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        if (duration <= 0) throw invalid_argument("Duration must be positive.");
        this->duration = duration;
    }

    void checkOut() override 
    {
        cout << "DVD '" << getTitle() << "' checked out.\n";
    }

    void returnItem() override 
    {
        cout << "DVD '" << getTitle() << "' returned.\n";
    }

    void displayDetails() const override 
    {
        cout << "DVD Title: " << getTitle() << ", Director: " << getAuthor()
             << ", Due Date: " << getDueDate() << ", Duration: " << duration << " min\n";
    }
};

class Magazine : public LibraryItem 
{
private:
    int issueNumber;

public:
    Magazine(string title, string author, string dueDate, int issue) 
    {
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        if (issue <= 0) throw invalid_argument("Issue number must be positive.");
        issueNumber = issue;
    }

    void checkOut() override 
    {
        cout << "Magazine '" << getTitle() << "' checked out.\n";
    }

    void returnItem() override 
    {
        cout << "Magazine '" << getTitle() << "' returned.\n";
    }

    void displayDetails() const override 
    {
        cout << "Magazine Title: " << getTitle() << ", Editor: " << getAuthor()
             << ", Due Date: " << getDueDate() << ", Issue #: " << issueNumber << endl;
    }
};

const int MAX_ITEMS = 10;
LibraryItem* libraryItems[MAX_ITEMS]; 
int itemCount = 0;

void displayMenu() 
{
    cout <<endl<< "--- Library Management System ---"<<endl;
    cout << "1. Add Book"<<endl;
    cout << "2. Add DVD"<<endl;
    cout << "3. Add Magazine"<<endl;
    cout << "4. Display All Items"<<endl;
    cout << "5. Check Out Item"<<endl;
    cout << "6. Return Item"<<endl;
    cout << "7. Search Item by Title"<<endl;
    cout << "8. Exit"<<endl;
    cout << "Choose an option: ";
}

void searchByTitle(const string& searchTitle) 
{
    bool found = false;
    for (int i = 0; i < itemCount; i++) 
    {
        if (libraryItems[i]->getTitle() == searchTitle) 
        {
            libraryItems[i]->displayDetails();
            found = true;
        }
    }
    if (!found) cout << "Item with title '" << searchTitle << "' not found.\n";
}

int main()
{
    int choice;
    do 
    {
        displayMenu();
        cin >> choice;

        try 
        {
            if (choice == 1 && itemCount < MAX_ITEMS) 
            {
                string title, author, dueDate, isbn;
                cout << "Enter Title: ";
                cin >> ws; getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Due Date: ";
                getline(cin, dueDate);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                libraryItems[itemCount++] = new Book(title, author, dueDate, isbn);
            } 
            else if (choice == 2 && itemCount < MAX_ITEMS) 
            {
                string title, author, dueDate;
                int duration;
                cout << "Enter Title: ";
                cin >> ws; getline(cin, title);
                cout << "Enter Director: ";
                getline(cin, author);
                cout << "Enter Due Date: ";
                getline(cin, dueDate);
                cout << "Enter Duration (min): ";
                cin >> duration;
                libraryItems[itemCount++] = new DVD(title, author, dueDate, duration);
            }
            else if (choice == 3 && itemCount < MAX_ITEMS) 
            {
                string title, author, dueDate;
                int issue;
                cout << "Enter Title, ";
                cin >> ws; getline(cin, title);
                cout << "Editor, ";
                getline(cin, author);
                cout << "Due Date, ";
                getline(cin, dueDate);
                cout << "Issue Number: ";
                cin >> issue;
                libraryItems[itemCount++] = new Magazine(title, author, dueDate, issue);
            } 
            else if (choice == 4) 
            {
                for (int i = 0; i < itemCount; i++) 
                {
                    libraryItems[i]->displayDetails();
                }
            } 
            else if (choice == 5 || choice == 6) 
            {
                int idx;
                cout << "Enter item index (0 to " << itemCount - 1 << "): ";
                cin >> idx;
                if (idx >= 0 && idx < itemCount) 
                {
                    if (choice == 5) libraryItems[idx]->checkOut();
                    else libraryItems[idx]->returnItem();
                } 
                else 
                {
                    throw out_of_range("Invalid item index.");
                }
            } 
            else if (choice == 7) 
            {
                string searchTitle;
                cout << "Enter title to search: ";
                cin >> ws; getline(cin, searchTitle);
                searchByTitle(searchTitle);
            } 
            else if (choice == 8) 
            {
                cout << "Exiting...\n";
            } 
            else 
            {
                cout << "Invalid choice.\n";
            }
        } 
        catch (exception &e) 
        {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 8);

    for (int i = 0; i < itemCount; i++) 
    {
        delete libraryItems[i];
    }

    return 0;
}