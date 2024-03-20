#ifndef TIME_HEADER_FILE_LOGGER_HPP
# define TIME_HEADER_FILE_LOGGER_HPP

# include "AHeaderFileLogger.hpp"
# include <ctime>

class TimeHeaderFileLogger : public AHeaderFileLogger {
    private:
        TimeHeaderFileLogger();
        TimeHeaderFileLogger(const TimeHeaderFileLogger &);
        TimeHeaderFileLogger &operator=(const TimeHeaderFileLogger &);

    public:
        TimeHeaderFileLogger(const std::string &file_path) : AHeaderFileLogger(file_path) {}
        ~TimeHeaderFileLogger() {}

    private:
        static std::string get_current_time_header() {
            std::time_t current_time = std::time(NULL);

            std::string timeString = std::ctime(&current_time);

            return (timeString);
        }

        // appends the header cin front of the string
        virtual void put_header_in_front_of_str(std::string &str) {
            str += " ";
            str += TimeHeaderFileLogger::get_current_time_header();
        }
};

#endif