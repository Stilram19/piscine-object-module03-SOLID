# include <vector>
# include "ILogger.hpp"

// ******* The new design of this exercise, was proposed by my friend Oussama Khiar *******.

// this test, depends only on abstraction (the ILogger interface)
// it can be put in a seprate high level module.

void high_level_test(const std::vector<ILogger *> &loggers) {
    for (std::vector<ILogger *>::const_iterator logger = loggers.begin(); logger != loggers.end(); logger++) {
        std::string str("Hello, World!");
        (*logger)->write(str);
    }
}

# include "StreamLogger.hpp"
# include "FileLogger.hpp"
# include "ConstLogger.hpp"
# include "TimeLogger.hpp"
# include <fstream>

// the subject & main functions do not respecting DIP, they cannot because it's a test
// that requires testing all the concrete implementations of the abstraction

void subject_test() {
    std::ofstream s1("file2.txt");
    std::ofstream s2("file4.txt");
    std::ofstream s3("file6.txt");

    FileLogger logger1("file1.txt");
    StreamLogger logger2(s1);

    FileLogger nonHeaderLogger1("file3.txt");
    FileLogger nonHeaderLogger2("file5.txt");
    StreamLogger nonHeaderLogger3(s2);
    StreamLogger nonHeaderLogger4(s3);

    ConstLogger logger3(nonHeaderLogger1, "FILECONST");
    ConstLogger logger4(nonHeaderLogger3, "STREAMCONST");
    TimeLogger logger5(nonHeaderLogger2);
    TimeLogger logger6(nonHeaderLogger4);

    std::vector<ILogger *> loggers;

    loggers.push_back(&logger1);
    loggers.push_back(&logger2);
    loggers.push_back(&logger3);
    loggers.push_back(&logger4);
    loggers.push_back(&logger5);
    loggers.push_back(&logger6);

    // calling the high level test
    high_level_test(loggers);

    // closing the ofstreams
    s1.close();
    s2.close();
    s3.close();
}

int main() {
    try {
        subject_test();
    }
    catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}
