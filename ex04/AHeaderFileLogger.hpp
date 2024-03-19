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
};

#endif