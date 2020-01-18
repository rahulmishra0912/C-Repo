#include <iostream>
#include <ppl.h>

using namespace Concurrency;

#include <chrono> 
using namespace std;
using namespace std::chrono;

void AccumulateEvens()
{
    long long int nSum = 0;
    for (long long int n = 2; n < 5000000000; n += 2)
    {
        nSum += n;
    }
    wcout << "\nSum of evens:" << nSum << std::endl;
}

void AccumulateOdds()
{
    long long int nSum = 0;
    for (long long int n = 1; n < 5000000000; n += 2)
    {
        nSum += n;
    }
    wcout << "\nSum of odds:" << nSum << std::endl;
}

int main()
{
    auto start = high_resolution_clock::now();
    parallel_invoke(&AccumulateEvens, &AccumulateOdds);

    auto middle = high_resolution_clock::now();

    AccumulateEvens();
    AccumulateOdds();

    auto stop = high_resolution_clock::now();

    auto pduration = duration_cast<seconds>(middle-start);

    auto duration = duration_cast<seconds>(stop - middle);

    std::wcout << "\npduration: " << pduration.count() << "\n\n";
    std::wcout << "duration: " << duration.count() << "\n\n";


    return 0;
}
