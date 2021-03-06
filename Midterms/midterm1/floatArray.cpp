#include <iostream>

class FloatArray{

private:
    float *array;

public:
    FloatArray(int arraySize){
        array = new float[arraySize];
    }

    ~FloatArray(){
        delete []array;
    }

    void add(int index, float number){
        array[index] = number;
    }

    float getNumber(int index){
        float element = array[index];

        return element;
    }

    float getHigestValue(){

        float highest = array[0];
        int arraySize = sizeof(array)+1;

        for(int i=0; i<arraySize; ++i)
            if(array[i] > highest)
                highest = array[i];

        return highest;

    }

    float getLowestValue(){

        float lowest = array[0];
        int arraySize = sizeof(array)+1;

        for(int i=0; i<arraySize; ++i)
            if(array[i] < lowest)
                lowest = array[i];

        return lowest;

    }

};



int main(int argc, char *argv[]) {

    FloatArray list = FloatArray(5);

    list.add(0,42.5);
    list.add(1,98.7);
    list.add(2,32.1);
    list.add(3,21.9);
    list.add(4,12.5);

    for(int i=0; i<5; ++i)
        std::cout << "Element " << (i+1) <<": " << list.getNumber(i) << std::endl;

    std::cout << "Highest Value:" << list.getHigestValue() << std::endl;
    std::cout << "Lowest ValueL " << list.getLowestValue() << std::endl;




    return 0;
}