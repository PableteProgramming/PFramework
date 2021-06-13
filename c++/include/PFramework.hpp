#include <echo.hpp>
#include <ls.hpp>
#include <hash.hpp>
#include <vector>

typedef bool (*funcPtr)(std::string);

std::vector<std::string> Split(std::string,char);

std::vector<std::pair<std::pair<std::string,funcPtr>,std::string>> scripts= {
	{std::make_pair(std::make_pair("echo",&echo),"echo.txt")},
	{std::make_pair(std::make_pair("ls",&ls),"ls.txt")}
};
