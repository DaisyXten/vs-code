// g++ -lpthread
#include<iostream>
#include<thread>
#include<sstream>
using namespace std;


class fn_object_class{
    void operator()(){
//        stringstream ss = std::to_string(std::hash<std::thread::id>()(std::this_thread::get_id()));
//        std::cout<<ss<<std::endl;
    }
};

int main(){
    std::thread thread_1(fn_object_class());
    thread_1.join();
}
