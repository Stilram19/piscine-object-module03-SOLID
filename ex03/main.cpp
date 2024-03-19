# include "employeeManagement.hpp"
# include "salariedEmployee.hpp"
# include "hourlyEmployee.hpp"

void test1() {
    EmployeeManager manager;
    HourlyEmployee *temp_worker = new TempWorker(20);
    SalariedEmployee *contract_employee = new ContractEmployee(20);
    StudentSalariedEmployee *apprentice = new Apprentice(20);

    manager.addEmployee(temp_worker);
    manager.addEmployee(contract_employee);
    manager.addEmployee(apprentice);

    manager.executeWorkday();
    manager.calculatePayroll();

    temp_worker->mobilise(90);
    temp_worker->register_hour();
    temp_worker->register_hour();
    temp_worker->register_hour();
    temp_worker->register_hour();
    temp_worker->register_hour();

    temp_worker->register_hour();

    manager.executeWorkday();
    manager.executeWorkday();
    manager.executeWorkday();
    manager.executeWorkday();


    std::cout << "*********" << std::endl;

    manager.calculatePayroll();

    delete temp_worker;
    delete contract_employee;
    delete apprentice;
}

int main() {
    test1();
    return (0);
}
