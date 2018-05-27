#pragma once
#include <stdint.h>
#include "bitmap.h"
#define BloomType uint64_t
#define BloomHashCount 2

typedef uint64_t (*HashFun)(char*);

typedef struct BloomFilter{  
    BitMap bm;  
    HashFun bloom_hash[BloomHashCount];  
}BloomFilter; 
 
void BloomFilterInit(BloomFilter* bf);  
void BloomFilterDestroy(BloomFilter* bf);  
void BloomFilterInsert(BloomFilter* bf, char* str);  
int BloomFilterIsExit(BloomFilter* bf, char* str); 
