#include <func.hpp>

char* StringToCharArray(std::string s){
	char* r= (char*)malloc(s.size());
	for(int i=0; i<s.size();i++){
		r[i]=s[i];
	}
	return r;
}

std::string StringToHex(const std::string str)
{
    	std::string hexstr = std::string(str.size() << 1, '\0');
    	char c;

    	for (size_t i = 0, j = 0; i < str.size(); i++)
    	{
        	c = (str[i] & 0xF0) >> 4;
        	hexstr[j++] = c > 9 ? (c - 9) | 0x40 : c | 0x30;
        	c = str[i] & 0xF;
        	hexstr[j++] = c > 9 ? (c - 9) | 0x40 : c | 0x30;
    	}

	std::string r="";
	for(int i=0; i<hexstr.size();i++){
		if(isalpha(hexstr[i])){
			r+= tolower(hexstr[i]);
		}
		else{
			r+= hexstr[i];
		}	
	}
	return r;
}
