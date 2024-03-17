#ifndef HOURLY_EMPLOYEE_HPP
# define HOURLY_EMPLOYEE_HPP

# include "employee.hpp"

class HourlyEmployee : Employee {
    private:
        HourlyEmployee();
        HourlyEmployee(const HourlyEmployee &);
        HourlyEmployee &operator=(const HourlyEmployee &);

    public:
        HourlyEmployee(int DayHoursCount, int hourlyValue) : Employee(DayHoursCount, hourlyValue) {}
        ~HourlyEmployee() {}
};

class TempWorker : HourlyEmployee {

};

#endif