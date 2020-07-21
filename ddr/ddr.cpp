#include "ddr.h"

using namespace std;

DDR::DDR() {
    this->size = 0;
    this->memory = NULL;

    this->begin_delay = DDR_BEGIN_DELAY;
    this->end_delay = DDR_END_DELAY;
    this->bandwidth = DDR_BANDWIDTH;
}

DDR::DDR(int size) {
    this->size = size;
    this->memory = (float *)std::malloc((size_t)size);

    this->begin_delay = DDR_BEGIN_DELAY;
    this->end_delay = DDR_END_DELAY;
    this->bandwidth = DDR_BANDWIDTH;
}

DDR::~DDR() {
    if(this->size > 0)
        free(this->memory);
}

int DDR::malloc(int size) {
    this->memory = (float *)std::malloc(size);
    if(this->memory == NULL)
        return DDR_ERROR;
    this->size = size;
    return DDR_SUCCESS;
}

int DDR::realloc(int size) {
    this->memory = (float *)std::realloc(this->memory, size);
    if(this->memory == NULL)
        return DDR_ERROR;
    this->size = size;
    return DDR_SUCCESS;
}

int DDR::write(float *src, int addr, int len) {
    if(this->size == 0)
        return DDR_ERROR;
    int real_addr = addr % this->size;
    if((this->size - real_addr) < (len * sizeof(float)))
        return DDR_ERROR;
    memcpy(this->memory + (real_addr / sizeof(float)), src, len * sizeof(float));
}

int DDR::read(float *dst, int addr, int len) {
    if(this->size == 0)
        return DDR_ERROR;
    int real_addr = addr % this->size;
    if((this->size - real_addr) < (len * sizeof(float)))
        return DDR_ERROR;
    memcpy(dst, this->memory + (real_addr / sizeof(float)), len * sizeof(float));
}
