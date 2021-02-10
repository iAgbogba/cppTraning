#include <iostream>
#include <thread>
#include <iomanip>
#include <chrono>

using namespace std;

inline void print_time()
{
    auto now = std::chrono::system_clock::now();
    auto stime = std::chrono::system_clock::to_time_t(now);
    auto ltime = std::localtime(&stime);
    std::cout << std::put_time(ltime, "%c") << std::endl;
}

class FuncObj
{
    public:
    void operator()(int& i)
    {
        using namespace std::chrono;
        while (i >= 0)
        {
            std::cout <<"FuncObj currentValue: " << i << "\n" ;
            --i;
            std::this_thread::sleep_for(milliseconds(20));
        }
    }
};

void lambdaThread()
{
    std::thread t([](uint8_t i)
    {
        std::cout <<"lambdaThread: " << i * 2 << "\n" ;
    }, 2);
    
    t.join();
}
 
int main()
{
    std::cout << std::thread::hardware_concurrency() << " concurrent threads are supported.\n";
    
    int i {100};
    std::thread t1(FuncObj(), std::ref(i));
    std::cout << " main i= : " << i <<"\n";
    lambdaThread();
    std::cout << " main intermediate i= : " << i <<"\n";
    t1.join();
    std::cout << " main last i= : " << i <<"\n";
    return 0;
}
