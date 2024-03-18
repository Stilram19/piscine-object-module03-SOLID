#ifndef SALARIED_EMPLOYEE_HPP
# define SALARIED_EMPLOYEE_HPP

# include <iostream>
# include "employee.hpp"

class SalariedEmployee : public Employee {
    protected:
        int absenceHours; // number of hours in which the employee was absent

    private:
        SalariedEmployee();
        SalariedEmployee(const SalariedEmployee &);
        SalariedEmployee &operator=(const SalariedEmployee &);

    public:
        SalariedEmployee(int hourlyValue) : Employee(hourlyValue), absenceHours(0) {}
        virtual ~SalariedEmployee() {}

    public:
        virtual void register_absence() = 0;
};

class ContractEmployee : public SalariedEmployee {
    private:
        ContractEmployee();
        ContractEmployee(const ContractEmployee &);
        ContractEmployee &operator=(const ContractEmployee &);

    public:
        // registers an absence hour
        virtual void register_absence() {
            this->absenceHours++;
        }

        // returns the hours that the employee finished working during the day.
        virtual int executeWorkday() {
            int finishedDayHours = Employee::maxDayHours - this->absenceHours;

            // checking if the employee didn't work all day long
            if (this->absenceHours >= Employee::maxDayHours) {
                this->absenceHours -= Employee::maxDayHours;
                return (0);
            }

            this->absenceHours = 0;

            // otherwise the employee did work at least one hour during the day
            return (finishedDayHours);
        }
};

// this abstract class is created to adhere to the ISP, adding features only useful
// for the apprentice class and not all the other SalariedEmployee classes
class StudentSalariedEmployee : public SalariedEmployee {
    protected:
        int schoolHours; // hours spent in school

    private:
        StudentSalariedEmployee();
        StudentSalariedEmployee(const StudentSalariedEmployee &);
        StudentSalariedEmployee &operator=(const StudentSalariedEmployee &);

    public:
        StudentSalariedEmployee(int hourlyValue) : SalariedEmployee(hourlyValue), schoolHours(0) {}
        virtual ~StudentSalariedEmployee() {}

    public:
        virtual void register_school_hour() = 0;
};

class Apprentice : public StudentSalariedEmployee {
    private:
        Apprentice();
        Apprentice(const Apprentice &);
        Apprentice &operator=(const Apprentice &);

    public:
        // registers an absence hour
        virtual void register_absence() {
            this->absenceHours++;
        }

        // registers an absence hour spent at school
        virtual void register_school_hour() {
            this->absenceHours++;
            this->schoolHours++;
        }

        // returns the hours that the employee finished working during the day.
        virtual int executeWorkday() {
            int finishedDayHours = this->schoolHours / 2;

            // checking if the employee was at school all day long
            if (this->schoolHours > Employee::maxDayHours) {
                finishedDayHours = Employee::maxDayHours;
                this->schoolHours -= Employee::maxDayHours;
                this->absenceHours -= Employee::maxDayHours;
                return (finishedDayHours);
            }

            this->schoolHours = 0;

            // check if the employee didn't work during the day
            if (this->absenceHours >= Employee::maxDayHours) {
                this->absenceHours -= Employee::maxDayHours;
                return (finishedDayHours);
            }

            // otherwise the employee did work at least one Hour during the day

            finishedDayHours += (Employee::maxDayHours - this->absenceHours);

            this->absenceHours = 0;

            return (finishedDayHours);
        }
};

#endif