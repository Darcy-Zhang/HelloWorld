/*
 * @Author       : Darcy
 * @Date         : 2021-04-04 22:18:31
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-05 13:16:57
 * @FilePath     : \HelloWorld\Cpp\TXExersice\03\T1.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>
#include <string>

using namespace std;

class Book {
  public:
    Book(string bname = "MyBook", string bauthor = "Darcy",
         double bprice = 20.0, unsigned int bnumber = 100);
    void setname(string name);
    void display(void);
    void borrow(void);
    void restore(void);

  private:
    string bookName;
    string author;
    double price;
    unsigned int number;
};

Book::Book(string bname, string bauthor, double bprice, unsigned int bnumber) {
    bookName = bname;
    author = bauthor;
    price = bprice;
    number = bnumber;
}

void Book::setname(string name) {
    bookName = name;
    return;
}

void Book::display() {
    cout << "BookName: " << bookName << '\t' << "Author: " << author << '\t'
         << "Price: " << price << '\t' << "Number: " << number << endl;
    return;
}

void Book::borrow() {
    if (number > 0) {
        --number;
        cout << bookName << " has been borrowed successfully!" << endl;
        cout << "BookName: " << bookName << '\t' << "Author: " << author << '\t'
             << "Price: " << price << '\t' << "Number: " << number << endl;
    } else {
        cout << "There are no " << bookName << " in the library" << endl;
        cout << "BookName: " << bookName << '\t' << "Author: " << author << '\t'
             << "Price: " << price << '\t' << "Number: " << number << endl;
    }
    return;
}

void Book::restore() {
    ++number;
    cout << "BookName: " << bookName << '\t' << "Author: " << author << '\t'
         << "Price: " << price << '\t' << "Number: " << number << endl;
    return;
}

int main() {
    Book book;
    book.setname("C++程序设计");
    int temp;
    cout << "click b to borrow, r to restore, s to display and e to "
            "exit(b/r/s/e)";
    while ((temp = getchar()) != 'e') {
        if (temp == 'b')
            book.borrow();
        else if (temp == 'r')
            book.restore();
        else if (temp == 's')
            book.display();
        else
            cout << "click b to borrow, r to restore, s to display and e to "
                    "exit(b/r/s/e)";
    }
    return 0;
}
