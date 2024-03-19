#ifndef ILOGGER_HPP
# define ILOGGER_HPP

# include <iostream>

class ILogger {
    public:
        virtual void write(std::string &str) = 0;
};

// two types of loggers: writing to a file, writing to a stream
// two types of loggers: using a header, not using a header

#endif