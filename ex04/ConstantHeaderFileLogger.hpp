#ifndef CONSTANT_HEADER_FILE_LOGGER_HPP
# define CONSTANT_HEADER_FILE_LOGGER_HPP

# include "AHeaderFileLogger.hpp"

class ConstantHeaderFileLogger : public AHeaderFileLogger {
    private:
        std::string constant_header;

    private:
        ConstantHeaderFileLogger();
        ConstantHeaderFileLogger(const ConstantHeaderFileLogger &);
        ConstantHeaderFileLogger &operator=(const ConstantHeaderFileLogger &);

    public:
        ConstantHeaderFileLogger(const std::string &file_path, const std::string &constant_header) : \
            AHeaderFileLogger(file_path), constant_header(constant_header) {}
        ~ConstantHeaderFileLogger() {}

    private:
        // appends the header cin front of the string
        virtual void put_header_in_front_of_str(std::string &str) {
            str += " ";
            str += this->constant_header;
        }
};

#endif