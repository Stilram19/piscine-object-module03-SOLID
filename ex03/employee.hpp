#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

class Employee {
    protected:
        int                 hourlyValue; // the cost of hour
        static const int    maxDayHours = 7;

    private:
        Employee();
        Employee(const Employee &);
        Employee &operator=(const Employee &);

    public:
        Employee(int hourlyValue) : hourlyValue(hourlyValue) {}
        virtual ~Employee() {}

    public:
        virtual int executeWorkday() = 0; // shall return the number of finished hours of the day
};

#endif