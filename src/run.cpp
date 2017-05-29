#include "../include/run.h"
std::vector<std::string> processCmdLineArgs(int argc,char** argv)
{
    std::vector<std::string> _return;
    //verify (ARGS_GREATER_THAN_TWO,argc);
    for(int argv_i = 1; argv_i < argc; argv_i++)
    {
        
        if(argv_i == 1)
        {
            //determines if we are binding or calling
            if(std::string(argv[1]) == "call")
            {
                _return.push_back("call");
            }
            else if(std::string(argv[1]) == "bind")
            {
                _return.push_back("bind");
            }
            //else err_and_terminate(INVALID_ARG);
            else exit(1);
        }
        /*
        else {
            std::string arg = argv[argv_i];
            //run through possible options:
            if(arg == "-f")
            {
                _return[1] = argv[argv_i+1]; //filename
                argv_i++; //skip filename
            }
            //else err_and_terminate(INVALID_ARG);
        }
        */
        else _return.push_back(argv[argv_i]);
    }
    return _return;
}

void run(int argc,char** argv) 
{
    std::vector<std::string> data = processCmdLineArgs(argc,argv);
    if(data[0] == "call")
    {
        std::string func = data[1];
        std::string lang = data[2];
        std::string out;
        if(lang == "cpp")
        {
            std::string target = "./test ";
            std::string arg = "___adhescall " + func;
            out = exec((target+arg).c_str());
        }
        else if (lang == "python")
        {
            std::string target = "python test.py ";
            std::string arg = "___adhescall " + func;
            out = exec((target+arg).c_str());
        }
        std::cout << out;
    }
}