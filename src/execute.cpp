#include "../include/execute.h"
// Taken from Stack Overflow: https://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c-using-posix

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != NULL)
            result += buffer.data();
    }
    return result;
}