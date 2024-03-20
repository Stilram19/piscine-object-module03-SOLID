#ifndef AHEADER_FILE_LOGGER_HPP
# define AHEADER_FILE_LOGGER_HPP

# include "AFileLogger.hpp"

class AHeaderFileLogger : public AFileLogger {
    private:
        AHeaderFileLogger();
        AHeaderFileLogger(const AHeaderFileLogger &);
        AHeaderFileLogger &operator=(const AHeaderFileLogger &);

    public:
        AHeaderFileLogger(const std::string &file_path) : AFileLogger(file_path) {}
        ~AHeaderFileLogger() {}

    protected:
        // appends the header in front of the input string
        virtual void put_header_in_front_of_str(std::string &str) = 0;

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