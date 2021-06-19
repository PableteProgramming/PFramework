#include <clear.hpp>

bool clear(std::string params){
	if(params!=""){
		return false;
	}
	system("clear");
	return true;
}
