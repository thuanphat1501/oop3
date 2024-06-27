#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <string>
#include "manager.hpp"

using namespace std;
class System {
private:
    Manager manager;

    bool login(const string& account, const string& password) {
        if (account == "Admin" && password == "Admin") {
            cout << "Manager login successful!" << endl;
            managerMenu();
            return true;
        }
        else if (account == "Staff" && password == "Staff") {
            cout << "Employee login successful!" << endl;
            employeeMenu();
            return true;
        }
        else {
            cout << "Login failed. Invalid account or password." << endl;
            return false;
        }
    }

    void managerMenu() {
        int choice;
        do {
            cout << "\nManager Menu:\n";
            cout << "1. Add Employee\n";
            cout << "2. Edit Employee\n";
            cout << "3. Delete Employee\n";
            cout << "4. Set Shift\n";
            cout << "5. List Employees\n";
            cout << "6. View Working Hours\n";
            cout << "7. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            int id;
            string name, position, shifts;
            int reload;
            switch (choice) {
            case 1:
                do {
                    cout << "Enter ID: ";
                    cin >> id;
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter position: ";
                    cin >> position;
                    manager.addEmployee(id, name, position);

                    cout << "Add Employee successfully! \n"
                        << "1. Return.\n"
                        << "0. Exit.\n"
                        << "Enter your choice:";
                    cin >> reload;
                } while (reload == 1);
                break;
            case 2:
                do {
                    cout << "Enter ID: ";
                    cin >> id;
                    cout << "Enter new name (leave blank to skip): ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter new position (leave blank to skip): ";
                    getline(cin, position);
                    manager.editEmployee(id, name, position);

                    cout << "Edit Information  successfully! \n"
                        << "1. Return.\n"
                        << "0. Exit.\n"
                        << "Enter your choice:";
                    cin >> reload;
                } while (reload == 1);
                break;
            case 3:
                do {
                    cout << "Enter ID: ";
                    cin >> id;
                    manager.deleteEmployee(id);

                    cout << "Delete Employee successfully! \n"
                        << "1. Return.\n"
                        << "0. Exit.\n"
                        << "Enter your choice:";
                    cin >> reload;
                } while (reload == 1);
                break;
            case 4:
                do {
                    cout << "Enter ID: ";
                    cin >> id;
                    cout << "Enter shifts (e.g., 2-S, 2-C, 3-C): ";
                    cin.ignore();
                    getline(cin, shifts);
                    manager.setShift(id, shifts);

                    cout << "Set Shift successfully! \n"
                        << "1. Return.\n"
                        << "0. Exit.\n"
                        << "Enter your choice:";
                    cin >> reload;
                } while (reload == 1);
                break;
            case 5:
                manager.listEmployees();
                break;
            case 6:
                manager.workingHours();
                break;
            case 7:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
            }
        } while (choice != 7);
    }

    void employeeMenu() {
        int choice;
        do {
            cout << "\nEmployee Menu:\n";
            cout << "1. View Working Hours\n";
            cout << "2. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                manager.workingHours();
                break;
            case 2:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
            }
        } while (choice != 2);
    }

public:
    void run() {
        string account, password;
        cout << "Enter account: ";
        cin >> account;
        cout << "Enter password: ";
        cin >> password;
        login(account, password);
    }
};

#endif // SYSTEM_HPP
