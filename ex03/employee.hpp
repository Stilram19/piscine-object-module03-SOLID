#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

# define MAX_HOURLY_VALUE 300

# include <iostream>

class Employee {
    protected:
        int                 hourlyValue; // the cost of hour
        static const int    maxDayHours = 7;

    private:
        Employee();
        Employee(const Employee &);
        Employee &operator=(const Employee &);

    public:
        Employee(int hourlyValue) : hourlyValue(hourlyValue) {
            if (hourlyValue > MAX_HOURLY_VALUE) {
                throw std::runtime_error("The given houly value is just too much!");
            }
        }
        virtual ~Employee() {}

    public:
        virtual int executeWorkday() = 0; // shall return the number of finished hours of the day

    public:
        int get_hourly_value() {
            return (this->hourlyValue);
        }
};

#endif