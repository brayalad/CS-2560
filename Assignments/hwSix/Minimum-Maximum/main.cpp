//Minimum/Maximum Templates
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

int main(int argc, char *argv[]) {

    cout << "\nMinimum/Maximum Templates\n" << endl;

    int i1 = 7;
    int i2 = 3;

    unsigned int ui1 = 37;
    unsigned int ui2 = 42;

    signed int si1 = -56;
    signed int si2 = 729;

    short int shi1 = 373;
    short int shi2 = 421;

    unsigned short int ushi1 = 73;
    unsigned short int ushi2 = 21;

    signed short int sshi1 = 12;
    signed short int sshi2 = 456;

    long int li1 = 4930237;
    long int li2 = 86436239;

    unsigned long int uli1 = 930237;
    unsigned long int uli2 = 10493093;

    signed long int sli1 = 73328;
    signed long int sli2 = -32829;

    double d1 = 7.2849937;
    double d2 = 3.99373982;

    long double ld1 = 99382807.284934397367337;
    long double ld2 = 39893833.99373342345982;

    float f1 = 1.56;
    float f2 = 92.3;

    bool b1 = true;
    bool b2 = false;

    char c1 = 'b';
    char c2 = 'A';
    unsigned char uc1 = 'e';
    unsigned char uc2 = 'n';

    signed char sc1 = 'T';
    signed char sc2 = 'v';


    string s1 = "Bryan";
    string s2 = "Ayala";

    string choice;
    while(choice!="no") {

        cout << "\nRun driver code?(yes/no)" << endl;
        getline(cin,choice);

        if(choice=="yes") {

            cout << "\nInteger 1: " << i1 << endl;
            cout << "Integer 2: " << i2 << endl;
            cout << "Integer Minimum: " << minimum(i1, i2) << endl;
            cout << "Integer Maximum: " << maximum(i1, i2) << endl;

            cout << "\nUnsigned Integer 1: " << ui1 << endl;
            cout << "Unsigned Integer 2: " << ui2 << endl;
            cout << "Unsigned Integer Minimum: " << minimum(ui1, ui2) << endl;
            cout << "Unsigned Integer Maximum: " << maximum(ui1, ui2) << endl;

            cout << "\nSigned Integer 1: " << si1 << endl;
            cout << "Signed Integer 2: " << si2 << endl;
            cout << "Signed Integer Minimum: " << minimum(si1, si2) << endl;
            cout << "Signed Integer Maximum: " << maximum(si1, si2) << endl;

            cout << "\nShort Integer 1: " << shi1 << endl;
            cout << "Short Integer 2: " << shi2 << endl;
            cout << "Short Integer Minimum: " << minimum(shi1, shi2) << endl;
            cout << "Short Integer Maximum: " << maximum(shi1, shi2) << endl;

            cout << "\nUnsigned Short Integer 1: " << ushi1 << endl;
            cout << "Unsigned Short Integer 2: " << ushi2 << endl;
            cout << "Unsigned Short Integer Minimum: " << minimum(ushi1, ushi2) << endl;
            cout << "Unsigned Short Integer Maximum: " << maximum(ushi1, ushi2) << endl;

            cout << "\nSigned Short Integer 1: " << sshi1 << endl;
            cout << "Signed Short Integer 2: " << sshi2 << endl;
            cout << "Signed Short Integer Minimum: " << minimum(sshi1, sshi2) << endl;
            cout << "Signed Short Integer Maximum: " << maximum(sshi1, sshi2) << endl;

            cout << "\nLong Integer 1: " << li1 << endl;
            cout << "Long Integer 2: " << li2 << endl;
            cout << "Long Integer Minimum: " << minimum(li1, li2) << endl;
            cout << "Long Integer Maximum: " << maximum(li1, li2) << endl;

            cout << "\nUnsigned Long Integer 1: " << uli1 << endl;
            cout << "Unsigned Long Integer 2: " << uli2 << endl;
            cout << "Unsigned Long Integer Minimum: " << minimum(uli1, uli2) << endl;
            cout << "Unsigned Long Integer Maximum: " << maximum(uli1, uli2) << endl;

            cout << "\nSigned Long Integer 1: " << sli1 << endl;
            cout << "Signed Long Integer 2: " << sli2 << endl;
            cout << "Signed Long Integer Minimum: " << minimum(sli1, sli2) << endl;
            cout << "Signed Long Integer Maximum: " << maximum(sli1, sli2) << endl;


            cout << "\nDouble 1: " << d1 << endl;
            cout << "Double 2: " << d2 << endl;
            cout << "Double Minimum: " << minimum(d1, d2) << endl;
            cout << "Double Maximum: " << maximum(d1, d2) << endl;

            cout << "\nLong Double 1: " << ld1 << endl;
            cout << "Long Double 2: " << ld2 << endl;
            cout << "Long Double Minimum: " << minimum(ld1, ld2) << endl;
            cout << "Long Double Maximum: " << maximum(ld1, ld2) << endl;

            cout << "\nFloat 1: " << f1 << endl;
            cout << "Float 2: " << f2 << endl;
            cout << "Float Minimum: " << minimum(f1, f2) << endl;
            cout << "Float Maximum: " << maximum(f1, f2) << endl;

            cout << "\nBoolean 1: " << b1 << endl;
            cout << "Boolean 2: " << b2 << endl;
            cout << "Boolean Minimum: " << minimum(b1, b2) << endl;
            cout << "Boolean Maximum: " << maximum(b1, b2) << endl;

            cout << "\nCharacter 1: " << c1 << endl;
            cout << "Character 2: " << c2 << endl;
            cout << "Character Minimum: " << minimum(c1, c2) << endl;
            cout << "Character Maximum: " << maximum(c1, c2) << endl;

            cout << "\nUnsigned Character 1: " << uc1 << endl;
            cout << "Unsigned Character 2: " << uc2 << endl;
            cout << "Unsigned Character Minimum: " << minimum(uc1, uc2) << endl;
            cout << "Unsigned Character Maximum: " << maximum(uc1, uc2) << endl;

            cout << "\nSigned Character 1: " << sc1 << endl;
            cout << "Signed Character 2: " << sc2 << endl;
            cout << "Signed Character Minimum: " << minimum(sc1, sc2) << endl;
            cout << "Signed Character Maximum: " << maximum(sc1, sc2) << endl;

            cout << "\nString 1: " << s1 << endl;
            cout << "String 2: " << s2 << endl;
            cout << "String Minimum: " << minimum(s1, s2) << endl;
            cout << "String Maximum: " << maximum(s1, s2) << endl;

        }
        else if(choice=="no"){
            cout << "\nThank you for using this program!" << endl;
        }
        else{
            cout << "\nInvalid Input.\nPlease Try Again." << endl;
        }
    }


    return 0;
}