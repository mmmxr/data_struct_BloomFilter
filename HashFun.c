#include <stdio.h>
#include <stdint.h>
uint64_t HashFun_131(char* msg) //哈希函数
{
    if(msg == NULL) {
        return 0;
    }
    char* str = msg;
    uint64_t hash = 0;

    while(*str) {
        hash = hash*131 + *str;
        str++;
    }
    return hash;
}

uint64_t HashFun_65599(char* msg)//哈希函数
{
    if(msg == NULL) {
        return 0;

    }
    char* str = msg;
    uint64_t hash = 0;

    while(*str) {
        hash = hash*65599 + *str;
        str++;

    }
    return hash;

}
