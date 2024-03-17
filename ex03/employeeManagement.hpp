#ifndef EMPLOYEE_MANAGEMENT_HPP
# define EMPLOYEE_AMANGEMENT_HPP

# include <iostream>
# include <vector>
# include "employee.hpp"

class EmployeeManager {
    private:
        std::vector<Employee *> employees;

    private:
        bool has_employee(Employee *employee) const {
            for (std::vector<Employee *>::const_iterator it = this->employees.begin(); it != this->employees.end(); it++) {
                if ((*it) == employee) {
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
            this->employees.push_back(employee);
        }

        void removeEmployee(Employee *employee) {
            for (std::vector<Employee *>::const_iterator it = this->employees.begin(); it != this->employees.end(); it++) {
                if ((*it) == employee) {
                    this->employees.erase(it);
                    return ;
                }
            }
        }

        void executeWorkday() {
            for (std::vector<Employee *>::const_iterator it = this->employees.begin(); it != this->employees.end(); it++) {
                (*it)->executeWorkday();
            }
        }

        void calculatePayroll() {
            
        }

};

#endif