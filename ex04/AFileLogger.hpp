#ifndef AFILE_LOGGER_HPP
# define AFILE_LOGGER_HPP

# include "ILogger.hpp"
# include <unistd.h> // there is no cunistd, it's a system header file
# include <fcntl.h>

class AFileLogger : public ILogger {
    protected:
        int         fd;

    private:
        AFileLogger();
        AFileLogger(const AFileLogger &);
        AFileLogger &operator=(const AFileLogger &);

    public:
        AFileLogger(const std::string &file_path) {
            this->fd = open(file_path.c_str(), O_WRONLY | O_APPEND);

            if (this->fd == -1) {
                throw std::runtime_error("Cannot open file!");
            }
        }
        virtual ~AFileLogger() {
            if (fd != -1) {
                close(fd);
            }
        }
};

#endif