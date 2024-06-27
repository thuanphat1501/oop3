#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "employer.hpp"
#include <vector>
#include <string>
#include <map>

class Manager {
private:
    std::vector<Employee> employees;
    ShiftPeriod charToShiftPeriod(char c);

public:
    void addEmployee(int id, const std::string& name, const std::string& position);
    void editEmployee(int id, const std::string& name, const std::string& position);
    void deleteEmployee(int id);
    void setShift(int id, const std::string& shiftsStr);
    void listEmployees() const;
    void workingHours() const;
};

#endif // MANAGER_HPP
