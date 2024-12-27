#include <iostream>
using namespace std;

class Info
{
protected:
    static int rooms[10];
    static int count;
    string name = "unknown unknown ";
    int age = 0, ssn = 0, no_nights = 0, num = 0;
    const int price = 200;

    void displayRooms() {
        for (int i = 0; i < 10; i++) {
            cout << "Room " << i + 1;
            if (rooms[i] == 0)
                cout << "     Available" << endl;
            else
                cout << "     Not Available" << endl;
        }
    }

public:
    void add();
    void remove();
};

int Info::rooms[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int Info::count = 0;

void Info::remove()
{
    if (count == 0) {
        cout << "No guests to remove!" << endl;
        return;
    }
    int num = 0;
    do {
        cout << "Select the room number to remove (1-10): ";
        cin >> num;
    } while (num < 1 || num > 10 || rooms[num - 1] == 0);

    count--;
    rooms[num - 1] = 0;
    displayRooms();
    cout << "Total guests in the hotel: " << count << endl;
}

void Info::add()
{
    if (count == 10) {
        cout << "All rooms are occupied!" << endl;
        return;
    }
    cout << "Enter name: ";
    cin >> name; 
    cout << "Enter age: ";
    cin >> age; 
    cout << "Enter SSN: ";
    cin >> ssn; 
    cout << "Enter number of nights: ";
    cin >> no_nights; 

    displayRooms();

    do {
        cout << "Select an available room number (1-10): ";
        cin >> num;
    } while (num < 1 || num > 10 || rooms[num - 1] != 0);

    rooms[num - 1] = 1;
    count++;
}

class Admin : public Info
{
private:
    int operat;

public:
    Admin()
    {
        do {
            cout << "(1) Add guest" << endl;
            cout << "(2) Remove guest" << endl;
            cout << "Choose an option: ";
            cin >> operat;

            if (operat == 1)
                add();
            else if (operat == 2)
                remove();
            else
                cout << "Invalid option! Try again." << endl;

        } while (operat != 1 && operat != 2);
    }
    friend class Guest;
};

class Guest
{
private:
    double rate = 0;

public:
    void display(Admin& t)
    {
        cout << "Your name: " << t.name << endl;
        cout << "Your SSN: " << t.ssn << endl;
        cout << "Your age: " << t.age << endl;
        cout << "Your room number: " << t.num << endl;
        cout << "Total price: $" << t.price * t.no_nights << endl;
    }

    void rateHotel()
    {
        do {
            cout << "Please rate the hotel (1-5): ";
            cin >> rate;
        } while (rate < 1 || rate > 5);
        cout << "Thanks for your feedback!" << endl;
    }
};

int main()
{
    int choice;
    string username, password;
    char displayInfo;

    do {
        do {
            cout << "Welcome!" << endl;
            cout << "Are you an admin or do you want to close the program?" << endl;
            cout << "(1) Admin" << endl << "(2) Close" << endl;
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if (choice == 2)
            break;

        if (choice == 1) {
            do {
                cout << "Hi Admin!" << endl;
                cout << "Please enter your username: ";
                cin >> username;
                cout << "Please enter your password: ";
                cin >> password;
            } while (username != "user1" || password != "111");

            Admin admin;
            Guest guest;

            cout << "Do you want to display guest information? (Y/N): ";
            cin >> displayInfo;
            if (displayInfo == 'Y' || displayInfo == 'y') {
                guest.display(admin);
                guest.rateHotel();
            }
        }
    } while (choice != 2);

    return 0;
}