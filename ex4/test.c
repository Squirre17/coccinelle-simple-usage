#include "test.h"

int main(int argc, char const *argv[])
{
    int time_ns = 1, tick_ps = 2;
    return (time_ns * 1000 + tick_ps - 1) / tick_ps;
    return 0;
}
