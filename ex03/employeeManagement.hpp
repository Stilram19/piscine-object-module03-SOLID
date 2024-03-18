#ifndef EMPLOYEE_MANAGEMENT_HPP
# define EMPLOYEE_AMANGEMENT_HPP

# include <iostream>
# include <map>
# include "employee.hpp"

# define MONTH_DAYS 30

class EmployeeManager {
    private:
        std::map<Employee *, int> employees;

    private:
        bool has_employee(Employee *employee) const {
            for (std::map<Employee *, int>::const_iterator it = this->employees.begin(); it != this->employees.end(); it++) {
                if (it->first == employee) {
                    return (true);
                }
            }
            return (false);
        }

    public:
        void addEmployee(Employee *employee) {
            if (this->has_employee(employee)) {
                std::cout << "Employee can't be added: already exists!" << std::endl;
                return ;
            }
            this->employees[employee] = 0;
        }

        void removeEmployee(Employee *employee) {
            for (std::map<Employee *, int>::const_iterator it = this->employees.begin(); it != this->employees.end(); it++) {
                if (it->first == employee) {
                    this->employees.erase(it->first);
                    return ;
                }
            }
        }

        void executeWorkday() {
            for (std::map<Employee *, int>::iterator it = this->employees.begin(); it != this->employees.end(); it++) {
                it->second += it->first->executeWorkday();
            }
        }

        void calculatePayroll() {
            int worker_number = 0;

            for (std::map<Employee *, int>::iterator it = this->employees.begin(); it != this->employees.end(); it++) {
                int number_of_hours = it->second;
                int hourlyValue = it->first->get_hourly_value();

                std::cout << "Paying worker " << worker_number++;
                std::cout << " for the last month, Amount: ";

                if (number_of_hours <= MONTH_DAYS) {
                    std::cout << number_of_hours * hourlyValue << std::endl;
                    it->second = 0;
                    continue ;
                }

                it->second -= MONTH_DAYS;
                number_of_hours = MONTH_DAYS;

                std::cout << number_of_hours * hourlyValue << std::endl;
            }
        }

};

#endif