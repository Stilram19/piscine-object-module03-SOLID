#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

class Employee {
    protected:
        int DayHoursCount;
        int hourlyValue; // the cost of hour

    private:
        Employee();
        Employee(const Employee &);
        Employee &operator=(const Employee &);

    public:
        Employee(int DayHoursCount, int hourlyValue) : DayHoursCount(DayHoursCount), hourlyValue(hourlyValue) {}
        virtual ~Employee() {}

    public:
        virtual int executeWorkday() = 0; // shall return the number of worked hours
};

#endif