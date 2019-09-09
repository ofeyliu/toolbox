// shiyanlou_lock.cpp
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <ostream>
#include <map>

static std::mutex map_lock;
static std::map<std::ostream *, std::unique_ptr<std::mutex>> stream_locks;

// TODO START
std::ostream& shiyanlou_lock(std::ostream& os) {
    
    std::lock_guard<std::mutex> lk(map_lock);
    if(stream_locks.find(&os) == stream_locks.end())
    {
        stream_locks.insert(std::make_pair(&os,std::make_unique<std::mutex>()));
    }
    stream_locks[&os].get()->lock();
    return os;


}

std::ostream& shiyanlou_unlock(std::ostream& os) {

    std::lock_guard<std::mutex> lk(map_lock);
    stream_locks[&os].get()->unlock();
    return os;







}
// TODO END

void locked_outputs(size_t i) {
    std::string str {"Shiyanlou - Contest: Learn by Doing - Log System"};
    std::cout << shiyanlou_lock << "Thread " << i << " | 1.1.1.1 - [2018/05/08 00:00:01] \"GET /assets/logo.png HTTP/1.1\" 200" << std::endl << shiyanlou_unlock;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << shiyanlou_lock << "Thread " << i << " | 1.1.1.2 - [2018/05/08 00:00:02] \"GET /assets/logo.png HTTP/1.1\" 200" << std::endl << shiyanlou_unlock;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << shiyanlou_lock << "Thread " << i << " | 1.1.1.3 - [2018/05/08 00:00:03] \"GET /assets/logo.png HTTP/1.1\" 200" << std::endl << shiyanlou_unlock;
    std::cout << shiyanlou_lock << "Thread " << i << "---------------------" << std::endl << shiyanlou_unlock;
}

int main() {
    std::cout << "Locked output stream" << std::endl;
    std::thread thread1(locked_outputs, 1);
    std::thread thread2(locked_outputs, 2);
    thread1.join();
    thread2.join();
}
