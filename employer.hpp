#ifndef EMPLOYER_HPP
#define EMPLOYER_HPP

#include <string>
#include <map>

enum class ShiftPeriod { None, Morning, Afternoon, Evening };

class Employee {
public:
    int id;
    std::string name;
    std::string position;
    std::map<int, ShiftPeriod> shifts; // key: day of the week, value: shift period

    Employee(int id, const std::string& name, const std::string& position)
        : id(id), name(name), position(position) {}
};

#endif // EMPLOYER_HPP
