#include <echo.hpp>

bool echo(std::string s){
	if (s!=""){
		std::cout<<s<<std::endl;
		return true;
	}
	return false;
}
