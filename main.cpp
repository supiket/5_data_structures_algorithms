#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

string message, dictionary[1000];
long long int result[1001];
int dictSize = 0;
const long long int primeMod = 1000000007;

int main(int argc, char* argv[]) {
    ifstream infile(argv[1]);
    infile >> message;
    infile >> dictSize;
    for(int i = 1; i <= dictSize; i++){
        infile >> dictionary[i];
    }
    memset(result, 0, sizeof(result));
    result[0] = 1;
    for(int i = 1; i <= message.size(); i++){
        for(int j = 1; j <= dictSize; j++){
            if(i >= dictionary[j].size()){
                if(dictionary[j] == message.substr(i - dictionary[j].size(), dictionary[j].size()))
                    result[i] = (result[i] % primeMod + result[i - dictionary[j].size()] % primeMod) % primeMod;
            }
        }
    }
    cout << message << endl << dictSize << endl;

    ofstream outfile(argv[2]);
    outfile << result[message.size()] << endl;
    return 0;
}