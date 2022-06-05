#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

int main(int argc, char** argv)
{
    namespace po = boost::program_options;
    po::options_description desc("Allowed Options", 0);

    desc.add_options()
    ("debug", "Type your name to be greeted!")
    ("key", po::value<std::string>(), "A key to encrypt a message")
    ("message", po::value<std::string>(), "A message to encrypt");
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    if (vm.count("debug"))
    {
        fmt::print("Debug mode on!\n");
    }

    if (vm.count("key"))
    {
        std::string key = vm["key"].as<std::string>();
        fmt::print("Entered the key: {}\n", key);
    }

    if (vm.count("message"))
    {
        auto message = vm["message"].as<std::string>() ;
        fmt::print("Entered the message: {}\n", message);
    }
}
