#ifndef NON_HEADER_FILE_LOGGER_HPP
# define NON_HEADER_FILE_LOGGER_HPP

# include "AFileLogger.hpp"

class NonHeaderFileLogger : public AFileLogger {
    private:
        NonHeaderFileLogger();
        NonHeaderFileLogger(const NonHeaderFileLogger &);
        NonHeaderFileLogger &operator=(const NonHeaderFileLogger &);

    public:
        NonHeaderFileLogger(const std::string &file_path) : AFileLogger(file_path) {}
        ~NonHeaderFileLogger() {}

    public:
        virtual void write(std::string &str) {
            if (str.empty() == false) {
                int ret = ::write(this->fd, str.c_str(), str.length()); // the global scope is important
                // to prevent confusion, since both functions have the same name.

                if (ret == -1) {
                    throw std::runtime_error("Cannot write to file!");
                }
            }
        }
};

#endif