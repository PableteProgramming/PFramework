#include <ls.hpp>
#include <PFramework.hpp>

bool ls(std::string p){
	if(p==""){
		return false;
	}
	
	std::vector<std::string> params= Split(p,' ');

	if(params.size()>1){
		return false;
	}
	
	std::string dir= params[0];
	
	struct dirent* d;
        DIR* dr;
        dr = opendir(dir.c_str());
        std::string r;
        if (dr != NULL)
        {
            for (d = readdir(dr); d != NULL; d = readdir(dr))
            {
                if (std::string(d->d_name) != "." && std::string(d->d_name) != "..")
                {
			std::cout<<d->d_name<<std::endl;
                }
            }
            closedir(dr);
        }
        else {
            std::cout<<dir<<" is not a valid directory !"<<std::endl;;
        }

	return true;
}
