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
        virtual void mobilise(int newAssignedHours) = 0;
};

class TempWorker : public HourlyEmployee {
    private:
        TempWorker();
        TempWorker(const TempWorker &);
        TempWorker &operator=(const TempWorker &);

    public:
        TempWorker(int hourlyValue) : HourlyEmployee(hourlyValue) {}
        virtual ~TempWorker() {}

    public:
        // registers a finished hour
        virtual void register_hour() {
            if (this->assignedHours == 0) {
                std::cout << "Worker has no assigned hours of work" << std::endl;
                return ;
            }
            this->assignedHours--;
            this->hoursCount++;
        }

        // get assigned hours of work
        virtual void mobilise(int newAssignedHours) {
            size_t totalAssignedHours = this->assignedHours + newAssignedHours;

            if (totalAssignedHours > CAPACITY) {
                std::cout << "Assigned amount of hours is too much! Try with less!" << std::endl;
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