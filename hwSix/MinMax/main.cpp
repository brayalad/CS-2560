#include <iostream>

using namespace std;

template <typename T>
T const& maximum(T const& data1, T const& data2){
    return(data1 > data2)? data1:data2;
}

template <typename T>
T const& minimum(T const& data1, T const& data2){
    return(data1 < data2)? data1:data2;
}

int main() {

    cout << maximum(5,3) << endl;
    cout << minimum(5.2,2.5) << endl;


    return 0;
}