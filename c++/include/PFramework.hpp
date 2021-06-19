#include <echo.hpp>
#include <ls.hpp>
#include <hash.hpp>
#include <vector>
#include <func.hpp>
#include <clear.hpp>
#include <exit.hpp>

typedef bool (*funcPtr)(std::string);

std::vector<std::string> Split(std::string,char);
const std::string helpDir= "help";

const std::vector<std::pair<std::pair<std::string,funcPtr>,std::string>> scripts= {
	std::make_pair(std::make_pair("echo",&echo),"echo.txt"),
	std::make_pair(std::make_pair("ls",&ls),"ls.txt"),
	std::make_pair(std::make_pair("clear",&clear),"clear.txt"),
	std::make_pair(std::make_pair("exit",&Exit),"exit.txt")
};
