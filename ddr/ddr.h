#ifndef DDR_h
#define DDR_h

#include <stdlib.h>
#include <memory.h>

#define DDR_SUCCESS 0
#define DDR_ERROR 1

// DDR4 2400
#define DDR_BEGIN_DELAY 0
#define DDR_END_DELAY 0
#define DDR_BANDWIDTH 19.2 * 1024 * 1024 * 1024 // 19.2 GB/s

using namespace std;

class DDR {
public:
    DDR();
    DDR(int size);
    ~DDR();

    int malloc(int size);
    int realloc(int size);
    int write(float *src, int addr, int len);
    int read(float *dst, int addr, int len);

private:
    float begin_delay;
    float end_delay;
    float bandwidth;

    int size;
    float *memory;
};

#endif
