#include <exit.hpp>

bool Exit(std::string params){
	if(params!=""){
		return false;
	}
	exit(0);
	return true;
}
