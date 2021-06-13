#include <PFramework.hpp>

int main(){
	std::cout<<"md5 hash of lul: "<<md5("lul")<<std::endl;
	while (true){
		std::string message;
		std::cout<<"PFramework > ";
		std::getline(std::cin,message);
		if (message!=""){
			std::vector<std::string> r=  Split(message,' ');
			std::string cmd=r[0];
			for (int i=0; i< scripts.size();i++){
				if(scripts[i].first.first==cmd){
					std::string params="";
					for(int j=1 ;j<r.size();j++){
						params+= r[j]+" ";
					}
					scripts[i].first.second(params);
					break;
				}
			}
		}
	}
	echo("Hi");
	return 0;
}

std::vector<std::string> Split(std::string s,char del){
	std::vector<std::string> r;
	r.clear();
	std::string temp="";
	for(int i=0; i<s.size();i++){
		if(s[i]!=del){
			temp+=s[i];
		}
		else{
			r.push_back(temp);
			temp="";
		}
	}
	if (temp!=""){
		r.push_back(temp);
	}
	return r;
}
