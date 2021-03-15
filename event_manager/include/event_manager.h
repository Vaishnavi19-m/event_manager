#include<stdio.h>
#include<stdlib.h>

#define check_ebit(num , bit) ((num) & (1>>(bit-1)))
#define get_ebit(num,bit) ((num) |= 1<<(bit-1))


typedef void (*callback) ();


void register_event(int id, int e_bit, void (*ptr)());
void check_event(int inte_evnt);
void freeup();

typedef struct event_m
{
    int e_bitmap;
    int mod_id;
    void (*cb)();
    struct event_m *next;
}event_manager_t;
