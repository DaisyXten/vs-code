
#include <iostream>
#include <string>
#include <map>

using namespace std;

class SeqInFile
{
public:
    static int Access(std::string name)
    {
        static map<std::string, int> s_map;
        return s_map[name]++;
    }

private:
    static map<std::string, int> s_map;
};

//map<std::string, int> s_map;

int main(){
    std::cout<<"file1: "<<SeqInFile::Access("file1")<<std::endl;
    std::cout<<"file2: "<<SeqInFile::Access("file2")<<std::endl;
    std::cout<<"file1: "<<SeqInFile::Access("file1")<<std::endl;
    std::cout<<"file2: "<<SeqInFile::Access("file2")<<std::endl;
    std::cout<<"file1: "<<SeqInFile::Access("file1")<<std::endl;
    std::cout<<"file1: "<<SeqInFile::Access("file1")<<std::endl;
    std::cout<<"file1: "<<SeqInFile::Access("file1")<<std::endl;
    
    return 0;    
}

