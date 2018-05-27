#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
#include "bloomfilter.h"
#include "HashFun.h"
#define BLOOMMAXSIZE 100;

void BloomFilterInit(BloomFilter* bf)
{
    if(bf==NULL)
    {
        return;
    }
    BitMapInit(&bf->bm);
    bf->bloom_hash[0]=HashFun_131;
    bf->bloom_hash[1]=HashFun_65599;
}
void BloomFilterDestroy(BloomFilter* bf)
{
    if(bf==NULL)
    {
        return;
    }
    bf->bloom_hash[0]=NULL;
    bf->bloom_hash[1]=NULL;
    BitMapDestroy(&bf->bm);
}
void BloomFilterInsert(BloomFilter* bf,char* str)
{
    if(bf==NULL||str==NULL)
    {
        return;
    }
    size_t i=0;
    for(i=0;i<BloomHashCount;i++)
    {
        uint64_t hash=bf->bloom_hash[i](str) % BitMapSize;
        BitMapSet(&bf->bm,hash);
    }
}

int BloomFilterIsExit(BloomFilter* bf, char* str)
{
    if(bf==NULL||str==NULL)
    {
        return 0;
    }
    size_t i=0;
    for(i=0;i<BloomHashCount;i++)
    {
        size_t hash=bf->bloom_hash[i](str) % BitMapSize;
        int ret=BitMapTest(&bf->bm,hash);
        if(ret==0)
        {
            return 0;
        }
    }
    return 1;
}
///////////////////////////////////
//测试代码
///////////////////////////////////
#define TEST_HEADER printf("\n===============%s================\n",__FUNCTION__)
void TestInit()
{
    TEST_HEADER;
    BloomFilter bf;
    BloomFilterInit(&bf);
    BloomFilterDestroy(&bf);
}
void TestInsertAndIsExit()
{  
    TEST_HEADER;
    BloomFilter bf;
    BloomFilterInit(&bf);
    char* str="haha";
    BloomFilterInsert(&bf,str);  
    int ret = BloomFilterIsExit(&bf,str);  
    printf("ret expect 1,actual %d\n",ret);  
}  
int main()
{
    TestInit();
    TestInsertAndIsExit();
    return 0;
}
