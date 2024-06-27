#include "manager.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

ShiftPeriod Manager::charToShiftPeriod(char c) {
    switch (c) {
    case 'S': return ShiftPeriod::Morning;
    case 'T': return ShiftPeriod::Afternoon;
    case 'C': return ShiftPeriod::Evening;
    default: return ShiftPeriod::None;
    }
}

void Manager::addEmployee(int id, const string& name, const string& position) {
    employees.emplace_back(id, name, position);
    cout << "Added employee: " << name << endl;
}

void Manager::editEmployee(int id, const string& name, const string& position) {
    for (auto& emp : employees) {
        if (emp.id == id) {
            if (!name.empty()) emp.name = name;
            if (!position.empty()) emp.position = position;
            cout << "Updated employee with id: " << id << endl;
            return;
        }
    }
    cout << "Employee with id: " << id << " not found" << endl;
}

void Manager::deleteEmployee(int id) {
    auto it = remove_if(employees.begin(), employees.end(), [id](const Employee& emp) { return emp.id == id; });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        cout << "Deleted employee with id: " << id << endl;
    }
    else {
        cout << "Employee with id: " << id << " not found" << endl;
    }
}

void Manager::setShift(int id, const string& shiftsStr) {
    for (auto& emp : employees) {
        if (emp.id == id) {
            stringstream ss(shiftsStr);
            string shiftEntry;
            while (getline(ss, shiftEntry, ',')) {
                if (shiftEntry.length() < 3) continue;
                int day = shiftEntry[0] - '0';
                char period = shiftEntry[2];
                ShiftPeriod shiftPeriod = charToShiftPeriod(period);
                emp.shifts[day] = shiftPeriod;
            }
            cout << "Set shift for employee with id: " << id << endl;
            return;
        }
    }
    cout << "Employee with id: " << id << " not found" << endl;
}

void Manager::listEmployees() const {
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Position: " << emp.position << endl;
    }
}

void Manager::workingHours() const {
    cout << "Employee working time\n";
    cout << "Name\t| T2\t| T3\t| T4\t| T5\t| T6\t| T7\n";
    cout << "---------------------------------------------\n";
    for (const auto& emp : employees) {
        cout << emp.name << "\n";
        cout << "Sáng\t\t| ";
        for (int day = 2; day <= 7; ++day) {
            if (emp.shifts.find(day) != emp.shifts.end() && emp.shifts.at(day) == ShiftPeriod::Morning) {
                cout << "Sáng\t| ";
            }
            else {
                cout << "X\t| ";
            }
        }
        cout << "\nChiều\t\t| ";
        for (int day = 2; day <= 7; ++day) {
            if (emp.shifts.find(day) != emp.shifts.end() && emp.shifts.at(day) == ShiftPeriod::Afternoon) {
                cout << "Chiều\t| ";
            }
            else {
                cout << "X\t| ";
            }
        }
        cout << "\nTối\t\t| ";
        for (int day = 2; day <= 7; ++day) {
            if (emp.shifts.find(day) != emp.shifts.end() && emp.shifts.at(day) == ShiftPeriod::Evening) {
                cout << "Tối\t| ";
            }
            else {
                cout << "X\t| ";
            }
        }
        cout << "\n---------------------------------------------\n";
    }
}
