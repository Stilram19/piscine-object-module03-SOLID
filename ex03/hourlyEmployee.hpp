#ifndef HOURLY_EMPLOYEE_HPP
# define HOURLY_EMPLOYEE_HPP

# include <iostream>
# include "employee.hpp"

# define CAPACITY 100 // maximum hours that can be assigned to worker at a time

class HourlyEmployee : public Employee {
    protected:
        int hoursCount; // count of finished hours
        int assignedHours; // hours to be done

    private:
        HourlyEmployee();
        HourlyEmployee(const HourlyEmployee &);
        HourlyEmployee &operator=(const HourlyEmployee &);

    public:
        HourlyEmployee(int hourlyValue) : Employee(hourlyValue), hoursCount(0), assignedHours(0) {}
        virtual ~HourlyEmployee() {}

    public:
        virtual void register_hour() = 0;
        virtual void mobilise() = 0;
};

class TempWorker : public HourlyEmployee {
    private:
        TempWorker();
        TempWorker(const TempWorker &);
        TempWorker &operator=(const TempWorker &);

    public:
        // registers a finished hour
        virtual void register_hour() {
            if (this->assignedHours != 0) {
                this->assignedHours--;
                this->hoursCount++;
            }
        }

        // get assigned hours of work
        virtual void mobilise(int newAssignedHours) {
            size_t totalAssignedHours = this->assignedHours + newAssignedHours;

            if (totalAssignedHours > CAPACITY) {
                std::cout << "Temporary worker is busy! Try later!" << std::endl;
                return ;
            }
            this->assignedHours += newAssignedHours;
        }

        // returns the hours that the worker finished working.
        virtual int executeWorkday() {
            int finishedDayHours = this->hoursCount;

            // checking if the temporary worker has worked more
            // hours than the maxDayHours
            if (finishedDayHours > Employee::maxDayHours) {
                finishedDayHours = Employee::maxDayHours;
            }

            this->hoursCount -= finishedDayHours;

            return (finishedDayHours);
        }
};

#endif