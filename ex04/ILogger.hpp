#ifndef ILOGGER_HPP
# define ILOGGER_HPP

# include <iostream>

class ILogger {
    public:
        virtual void write(std::string &str) = 0;
        virtual ~ILogger() {}
};

#endif