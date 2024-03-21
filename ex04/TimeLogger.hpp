#ifndef TIME_LOGGER_HPP
# define TIME_LOGGER_HPP

# include "AHeaderLogger.hpp"
# include <ctime>

// (*) this is a high level module in the context where the abstraction is INonHeaderLogger
// which is hiding the low level modules implementation (FileHeader, StreamHeader)
// (*) this is a low level module in the context where the abstraction is ILogger
// which is hiding this low level module's concrete implementation.

class TimeLogger : public AHeaderLogger {
    private:
        TimeLogger();
        TimeLogger(const TimeLogger &);
        TimeLogger &operator=(const TimeLogger &);

    public:
        TimeLogger(INonHeaderLogger&nonHeaderLogger) : AHeaderLogger(nonHeaderLogger) {}
        ~TimeLogger() {}

    private:
        static std::string get_current_time_header() {
            std::time_t current_time = std::time(NULL);

            std::string timeString = std::ctime(&current_time);

            return (timeString);
        }

        // appends the header cin front of the string
        virtual void put_header_in_front_of_str(std::string &str) {
            str += " ";
            str += TimeLogger::get_current_time_header();
        }
};

#endif