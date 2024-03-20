#ifndef TIME_HEADER_STREAM_LOGGER_HPP
# define TIME_HEADER_STREAM_LOGGER_HPP

# include "AHeaderStreamLogger.hpp"
# include <ctime>

class TimeHeaderStreamLogger : public AHeaderStreamLogger {
    private:
        TimeHeaderStreamLogger();
        TimeHeaderStreamLogger(const TimeHeaderStreamLogger &);
        TimeHeaderStreamLogger &operator=(const TimeHeaderStreamLogger &);

    public:
        TimeHeaderStreamLogger(std::ostream &os) : AHeaderStreamLogger(os) {}
        ~TimeHeaderStreamLogger() {}

    private:
        static std::string get_current_time_header() {
            std::time_t current_time = std::time(NULL);

            std::string timeString = std::ctime(&current_time);

            return (timeString);
        }

        // appends the header cin front of the string
        virtual void put_header_in_front_of_str(std::string &str) {
            str += " ";
            str += TimeHeaderStreamLogger::get_current_time_header();
        }
};

#endif