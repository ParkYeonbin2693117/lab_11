#include"dayOfYear.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
namespace ParkYeonBin2693117
{
    void readwriteDayOfYearDatafile(std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<dayOfYear> v;
    
        std::streambuf* origBuf{ std::cout.rdbuf() };
        std::cout.rdbuf(nullptr);

        dayOfYear d;
        while(fin >> d)
        {
            v.push_back(d);
        }
        std::cout.rdbuf(origBuf);
        for(const auto& vi : v)
            fout << vi;
    }
}
int main()
{
    using namespace ParkYeonBin2693117;
    dayOfYear d; 
    std::ifstream fin{"dayOfYearData.txt"};
    if(fin.fail())
    {
        std::cout << "Input file opening failed.\n";
        std::exit(1);
    }
    std::streambuf* origBuf{ std::cout.rdbuf()};
    std::cout.rdbuf(nullptr);
    fin >> d;
    std::cout.rdbuf(origBuf);
    std::ofstream fout{"out.txt"};
    if (fout.fail())
    {
        std::cout << "Output file opening failed.\n";
        std::exit(1);
    }

    readwriteDayOfYearDatafile(fin, fout);
    fin.close();
    fout.close();

    return 0;
}