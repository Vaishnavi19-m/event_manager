#include<stdio.h>
#include<stdlib.h>
#include"event_manager.h"
#include"module.h"

event_manager_t *new_reg = NULL;
event_manager_t *head = NULL;

void register_event (int id,int evnt_bit, void (*ptr)())
{
event_manager_t *new_reg = (event_manager_t*) malloc (sizeof(event_manager_t));
event_manager_t *temp = head;

	if(temp == NULL)
	{
            new_reg->e_bitmap = evnt_bit;
            new_reg->mod_id = id;
            new_reg->cb = cb;
            new_reg->next = NULL;
            head = new_reg;
	} else {
	      while(temp->next != NULL) {
	          temp = temp->next;
              }
	      new_reg->e_bitmap = evnt_bit;
              new_reg->mod_id = id;
              new_reg->cb = cb;
	      new_reg->next = NULL;
              temp->next = new_reg;
	}
	return;
}

void check_event(int inte_evnt)
{
  event_manager_t *temp=head;
  while(temp!=NULL){
     if (check_ebit(temp->e_bitmap, inte_evnt)){
        temp->cb(inte_evnt);
       } 
      temp=temp->next;
    }
}

void freeup(){
 event_manager_t *temp=head;
 while(temp!=NULL){
    head=temp->next;
    free(temp);  
    temp=head;
   }
   

}

