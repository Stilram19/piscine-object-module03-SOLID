#ifndef FILE_LOGGER_HPP
# define FILE_LOGGER_HPP

# include "INonHeaderLogger.hpp"
# include <unistd.h> // there is no cunistd, it's a system header file
# include <fcntl.h>

// This is a low level module depending on the INonHeaderLogger abstraction

class FileLogger : public INonHeaderLogger {
    protected:
        int         fd;

    private:
        FileLogger();
        FileLogger(const FileLogger &);
        FileLogger &operator=(const FileLogger &);

    public:
        FileLogger(const std::string &file_path) {
            this->fd = open(file_path.c_str(), O_CREAT | O_WRONLY, 777);

            if (this->fd == -1) {
                throw std::runtime_error("Cannot open file!");
            }
        }
        virtual ~FileLogger() {
            if (fd != -1) {
                close(fd);
            }
        }

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