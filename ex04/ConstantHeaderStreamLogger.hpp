#ifndef CONSTANT_HEADER_STREAM_LOGGER_HPP
# define CONSTANT_HEADER_STREAM_LOGGER_HPP

# include "AHeaderStreamLogger.hpp"

class ConstantHeaderStreamLogger : public AHeaderStreamLogger {
    private:
        std::string constant_header;

    private:
        ConstantHeaderStreamLogger();
        ConstantHeaderStreamLogger(const ConstantHeaderStreamLogger &);
        ConstantHeaderStreamLogger &operator=(const ConstantHeaderStreamLogger &);

    public:
        ConstantHeaderStreamLogger(std::ostream &os, const std::string &constant_header) : \
            AHeaderStreamLogger(os), constant_header(constant_header) {}
        ~ConstantHeaderStreamLogger() {}

    private:
        // appends the header cin front of the string
        virtual void put_header_in_front_of_str(std::string &str) {
            str += " ";
            str += this->constant_header;
        }
};

#endif