#include<stdio.h>
#include<stdlib.h>
#include"event_manager.h"
#include"module.h"

void (*module_func[6])() = {module_1, module_2, module_3, module_4, module_5 };

void module_1(int evnt){
   printf(" event %d is interested in module 1\n",evnt);
}
void module_2(int evnt){
   printf(" event %d is interested in module 2\n",evnt);
}
void module_3(int evnt){
   printf(" event %d is interested in module 3\n",evnt);
}
void module_4(int evnt){
   printf(" event %d is interested in module 4\n",evnt);
}
void module_5(int evnt){
   printf(" event %d is interested in module 5\n",evnt);
}

void init_module(int num_evnt){
    int evt_bitmap=0,evnt=0,id;
    callback cb;
    for(id=MODULE_1;id<=MODULE_MAX;id++){
        printf("Enter the events in which  module %d is interested in \n enter 0 when done\n",id);
        scanf("%d",&evnt);
        while(evnt>0 && evnt<=num_evnt){ 
             get_ebit(evt_bitmap, evnt);
             scanf("%d",&evnt);
         }
       
       register_event(id,evt_bitmap,module_func[id]);
       evt_bitmap=0;

    }

}



