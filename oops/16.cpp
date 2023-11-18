#include<iostream>
using namespace std;

class first {
protected:
    int book_no;
    string book_name;
public:
    void getdata() {
        cout << "Enter book number: ";
        cin >> book_no;
        cout << "Enter book name: ";
        cin >> book_name;
    }
    void putdata() {
        cout << "Book number: " << book_no << endl;
        cout << "Book name: " << book_name << endl;
    }
};
class second {
protected:
    string author_name;
    string publisher;
public:
    void getdata() {
        cout << "Enter author name: ";
        cin >> author_name;
        cout << "Enter publisher: ";
        cin >> publisher;
    }
    void showdata() {
        cout << "Author name: " << author_name << endl;
        cout << "Publisher: " << publisher << endl;
    }
};
class third : public first, public second {
private:
    int no_of_pages;
    int year_of_publication;
public:
    void getdata() {
        first::getdata();
        second::getdata();
        cout << "Enter number of pages: ";
        cin >> no_of_pages;
        cout << "Enter year of publication: ";
        cin >> year_of_publication;
    }
    void showdata() {
        first::putdata();
        second::showdata();
        cout << "Number of pages: " << no_of_pages << endl;
        cout << "Year of publication: " << year_of_publication << endl;
    }
};
int main() {
    third obj[3];
    for (int i = 0; i < 3; i++) {
        obj[i].getdata();
    }
    return 0;
}