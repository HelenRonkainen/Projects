
#include <iostream>
#include <ctime>
#include <chrono>
#include "ringbuffer.h"
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>



constexpr size_t ELEMENT_COUNT = 16;
constexpr size_t MEM_LENGTH = sizeof(int)* ELEMENT_COUNT;


constexpr time_t Seconds(time_t hours) {

  return hours * 60 *60;
};

// Timezones
constexpr time_t CEST = Seconds(2);
constexpr time_t GMT3 = Seconds(3);
 
struct Timestamp{
uint32_t Write_idx;
uint32_t Read_idx;
uint64_t Spare;
uint64_t timestamp;

}timestamp;

void timecount();

int main(int argc, char** argv)
{

while(1){

 timecount();

}


return 0;
  
}

void timecount(int argc, char** argv){


time_t now =time(0);
 RingBuffer<std::time_t, 16> buffer;

for(int i = 0; i < argc; ++i) {


   buffer.push(std::time(nullptr));
}
std::time_t t =std::time(0);
time_t time_ptr;
time_ptr = time(NULL);
tm* localtime(const time_t* time_ptr);
    const time_t timestamp = buffer.read(); 
    const tm* timestamp_tm = gmtime(&timestamp); 
    



 for(int i = 0; i < argc; ++i) {


 
std::cout<<"register trace offline tool"<<std::endl;



    std::cout << "Timestamp (UTC):"<<timelocal << std::endl;
    std::cout << timestamp << std::endl;
    std::cout << std::asctime(timestamp_tm) << std::endl; 


    const time_t timestamp_CEST = timestamp + CEST; 
    const tm* tm_CEST = gmtime(&timestamp_CEST); 
    
    std::cout << "Timestamp (CEST):" << std::endl;
    std::cout << (timestamp_CEST) << std::endl; 
    std::cout << std::asctime(tm_CEST) << std::endl;

    const time_t timestamp_GMT3 = timestamp + GMT3; 
    const tm* tm_GMT3 = gmtime(&timestamp_GMT3); 
    
    std::cout << "Timestamp (GMT+03:00):" << std::endl;
    std::cout << (timestamp_GMT3) << std::endl; 
    std::cout << std::asctime(tm_GMT3) << std::endl; 
 
}

}



