// adhesive.h
#include <map>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <functional>
#include <regex>
using namespace std;
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
namespace adhesive {
//template <typename t>
class a {
    public:
        std::string call(std::string func,std::string lang) //lang should maybe be enum?
        {
            std::smatch matches;
            std::string res = exec(("./adhesive call " + func + " " + lang).c_str());
            std::regex_search(res,matches,std::regex("_ADHESIVERETURN:\\(\\[\\{(.+)\\}\\]\\)"));
            return matches[1];
        }
        void bind(std::string value,std::function<std::string()> f )
        {
            bindlist[value] = f;
        }
        void handle(int argc,char** argv)
        {
            if(argc > 1)
            {
                if(std::string(argv[1]) == "___adhescall" )
                {
                std::string fcall = argv[2];
                std::cout<<"_ADHESIVERETURN:({["<<bindlist[fcall]()<<"]})"; //find better method to output
                exit(0);
                }
            }
        }
    private:
        std::map<std::string, std::function<std::string()> > bindlist;
};

};