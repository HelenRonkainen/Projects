#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <array>



// Take the type to hold and buffer size as argument
template
<typename T, size_t Size>
class RingBuffer
{
  std::array<T, Size> buffer; // Buffer that holds values (static size, for dynamic resizing should use std::vector)
  std::size_t read_pointer; // Where the next value is read
  std::size_t write_pointer; // Where the next value is written
  
public:
  
  RingBuffer() // Default constructor, initialize read and write pointer to 0
    : read_pointer(0), write_pointer(0)
  {
  };

  // Write value at write_pointer position and advance write_pointer (wrap around)
  void push(T value) {
    buffer[write_pointer] = value;
    write_pointer = (write_pointer + 1) % Size;
  };

  // Read value at read_pointer position and advance read_pointer (wrap around)
  T read() {
    auto value = buffer[read_pointer];
    read_pointer = (read_pointer + 1) % Size;
    return value;
  };

  size_t size() const {
    return Size;
  };

};

template
<typename T>
class MRingBuffer
{
  size_t read_pointer;
  size_t write_pointer;
  T* data;
  size_t count;
public:

  // memory_ptr is a pointer to allocated memory
  //  that has a size of at least sizeof(T) * count
  MRingBuffer(void* memory_ptr, size_t push)
    : data((T*)memory_ptr), count(push), read_pointer(0), write_pointer(0)
  {
  }

  void push(T value) {
    data[write_pointer] = value;
    write_pointer = (write_pointer + 1) % count;
  }

  T read() {
    auto value = data[read_pointer];
    read_pointer = (read_pointer + 1) % count;
    return value;
  }
};


#endif
