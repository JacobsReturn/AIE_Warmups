#include <iostream>
#include <chrono>
#include <ctime> 
#include <functional>

int DoSomeLongRunningThing()
{
    int counter = 0;
    for (int i = 0; i < 9000; i++)
    {
        std::cout << " " << std::endl;
        counter += 1;
    }
    return counter;
}

// Yeah im lazy.
class benchmark
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    public:
        void begin();
        double finish();

        double easy(std::function<void()> callback);
};

// An easier version >:) credit Thomas.
double benchmark::easy(std::function<void()> callback)
{
    this->begin();
    callback();

    return this->finish();
}

void benchmark::begin()
{
    start = std::chrono::high_resolution_clock::now();
}

double benchmark::finish()
{
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    return elapsed.count();
}
//

int main(int argc, char** argv)
{
    // For todays exercise, we want to record how much time it takes to "do some work"
    // you will need to:
    // - get a start time
    // - get an end time
    // - subtract the difference and print the result in miliseconds.
    // Once you've done that... how might you make your code easily re-usable.
    // --

    benchmark performance = benchmark();

    performance.begin();

    std::cout << "Hello World" << std::endl;

    std::cout << "Took: " << performance.finish() << std::endl;
    // --
    // TODO: output to console - number of miliseconds it took to print "Hello World" above

    std::cout << "Took: " << performance.easy(DoSomeLongRunningThing) << std::endl;

    // TODO: output to console - number of miliseconds it took to took to call the above method
}