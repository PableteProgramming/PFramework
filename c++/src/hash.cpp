#include <hash.hpp>

char* StringToCharArray(std::string s){
	char* r= (char*)malloc(s.size());
	for(int i=0; i<s.size();i++){
		r[i]=s[i];
	}
	return r;
}

std::string md5(std::string s){
	char* sc= StringToCharArray(s);
	char* rc= Hashmd5(sc);
	return std::string(rc);	
}
