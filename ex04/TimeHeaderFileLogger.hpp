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
            std::string time_header = get_current_dir_name();
            str += " ";
            str += TimeHeaderFileLogger::get_current_time_header();
        }

    public:
        virtual void write(std::string &str) {
            if (str.empty() == false) {
                this->put_header_in_front_of_str(str);

                int ret = ::write(this->fd, str.c_str(), str.length()); // the global scope is important
                // to prevent confusion, since both functions have the same name.

                if (ret == -1) {
                    throw std::runtime_error("Cannot write to file!");
                }
            }
        }
};

#endif