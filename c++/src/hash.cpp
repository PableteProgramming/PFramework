#include <hash.hpp>
#include <func.hpp>

std::string md5(std::string s){
	char* sc= StringToCharArray(s);
	char* rc= Hashmd5(sc);
	std::string hash= std::string(rc);
	return hash;
}

std::string sha1(std::string s){
	char* sc= StringToCharArray(s);
	char* rc= Hashsha1(sc);
	std::string hash= std::string(rc);
	return hash;
}

std::string sha256(std::string s){
	char* sc= StringToCharArray(s);
	char* rc= Hashsha256(sc);
	std::string hash= std::string(rc);
	return hash;
}

std::string sha512(std::string s){
	char* sc= StringToCharArray(s);
	char* rc= Hashsha512(sc);
	std::string hash= std::string(rc);
	return hash;
}
