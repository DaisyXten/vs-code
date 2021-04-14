// g++ -std=c++11 SIGFPE.cc
#include<vector>
#include<iostream>
using namespace std;

int main(){
    std::vector<float> scale_weights_data {1.00000001e-07, 0, 0, 134.952164, 0, 128.594986, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 141.60141, 0, 0, 0, 139.639862, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84.1278839, 0, 0, 0, 0, 0, 0, 0, 0, 0, 168.736862, 0, 5.95562336e+35, 0, 0, 0,};
    float scale_in_data = 1124.46948;
    auto count = scale_weights_data.size();
    std::vector<float> scale_bias_data(count);
    for (int i = 0; i < count; i++){
        scale_bias_data[i] = scale_in_data * scale_weights_data[i];       
        std::cout<<"scale_bias_data["<<i<<"]:"<< scale_bias_data[i]<<std::endl;
    }
//  std::cout<<scale_weights_data[47]<<std::endl;
    return 0;
}
