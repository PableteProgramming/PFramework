#include <hash.hpp>

std::string md5(std::string s){
	GoString message= Hashmd5(GoString(s.c_str()));
	char* r= (char*)malloc(message.n+1);
	memcpy(r,message.p,message.n);
	r[message.n]= '\0';
	return std::string(r);
}
