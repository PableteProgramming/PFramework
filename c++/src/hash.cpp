#include <hash.hpp>
#include <func.hpp>

std::string md5(std::string s){
	char* sc= StringToCharArray(s);
	char* rc= Hashmd5(sc);
	std::string hash= std::string(rc);
	return StringToHex(hash);
}
