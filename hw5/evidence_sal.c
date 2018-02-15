/* Melanie Chow
   CS152, Winter 2018
   HW5
*/
#include "sal.h"
#include <stdio.h>
#include <stdlib.h>

void evidence_list_new()
{
    sal *test=list_new();
    list_show(stdout,test,'|');
    fprintf(stdout,"\n");
    free(test);
}

void evidence_list_show(FILE *f, sal *list, char sep)
{
  list_show(f,list,sep);
  fprintf(stdout,"\n");
}


void evidence_add_to_front(sal *list, char *val)
{
  add_to_front(list,val);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");
}

void evidence_find_first(sal *list, char *val)
{
  int retVal = find_first(list, val);
  fprintf(stdout, "%d", retVal);
}


void evidence_get_first(sal *list)
{
  fprintf(stdout,"%s\n",get_first(list));
}

void evidence_get_last(sal *list)
{
  fprintf(stdout,"%s\n",get_last(list));
}

void evidence_get_at_index(sal *list, size_t index)
{
  fprintf(stdout,"%s\n",get_at_index(list,index));
}

void evidence_insert_after(sal *list, char *sought_val, char *new_val)
{
  insert_after(list, sought_val,new_val);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");
}

void evidence_insert_before(sal *list, char *sought_val, char *new_val)
{
  insert_before(list, sought_val,new_val);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");
}

void evidence_insert_at_index(sal *list, size_t index, char *new_val)
{
  insert_at_index(list, index, new_val);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");
}

/*
sal *evidence_remove_first(sal *list, char *sought_val);

sal *evidence_remove_all(sal *list, char *sought_val);
*/

void evidence_act_on_strings(sal *list, void(*f)(char*))
{
  act_on_strings(list,f);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");

}
/*
void evidence_filter(sal *list, int(*test)(char*))
{
  _filter(list, test);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");
}
*/

int main()
{

  /*------------TESTS-----------------------------------------------------*/

  //TEST 1 -- arraylist of "Aa", "Bb", "Cc", "Dd", "Ee" (inital size of 5)
  sal *test1 = list_new();
  add_to_front(test1,"Ee");
  add_to_front(test1,"Dd");
  add_to_front(test1,"Cc");
  add_to_front(test1,"Bb");
  add_to_front(test1,"Aa");


  //TEST 2 -- empty arraylist
  sal *test2 = list_new();

  //TEST 3 -- one item in arraylist
  sal *test3 = list_new();
  add_to_front(test3,"Hiya");
  /* ---------------------------------------------------------------------*/

  fprintf(stdout, "*** Testing list_new ***\n");
  fprintf(stdout,"Empty Array List - Expecting [] \n");
  evidence_list_new();

  ///////////////////////////////////////////////////////////////////////

  fprintf(stdout, "*** Testing list_show ***\n");
  fprintf(stdout, "Expecting [Aa|Bb|Cc|Dd|Ee]\n");
  evidence_list_show(stdout,test1,'|');

  fprintf(stdout,"Expecting []\n");
  evidence_list_show(stdout,test2,'-');

  fprintf(stdout,"Expecting [Hiya]\n");
  evidence_list_show(stdout,test3,':');
  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing add_to_front ***\n");

  fprintf(stdout, "Expecting [Alphabet:|Aa|Bb|Cc|Dd|Ee]\n");
  evidence_add_to_front(test1, "Alphabet:");
  fprintf(stdout, "Expecting [Greetings:|Hiya]\n");
  evidence_add_to_front(test3, "Greetings:");

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing find_first ***\n");
  fprintf(stdout, "Expecting 2\n");
  evidence_find_first(test1, "Bb");
  fprintf(stdout, "Expecting -1 \n");
  evidence_find_first(test2, "Hat");
  fprintf(stdout, "Expecting 0 \n");
  evidence_find_first(test3, "Greetings:");


  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing get_first ***\n");

  fprintf(stdout,"Expecting Alphabet: \n");
  evidence_get_first(test1);

  fprintf(stdout,"Expecting null\n");
  evidence_get_first(test2);

  fprintf(stdout,"Expecting Greetings: \n");
  evidence_get_first(test3);

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing get_last ***\n");

  fprintf(stdout,"Expecting Ee\n");
  evidence_get_last(test1);

  fprintf(stdout,"Expecting null\n");
  evidence_get_last(test2);

  fprintf(stdout,"Expecting Hiya\n");
  evidence_get_last(test3);

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing get_at_index ***\n");

  fprintf(stdout,"Expecting null\n");
  evidence_get_at_index(test1, 6);

  fprintf(stdout,"Expecting Cc\n");
  evidence_get_at_index(test1, 3);

  fprintf(stdout,"Expecting null\n");
  evidence_get_at_index(test2, 0);

  fprintf(stdout,"Expecting Greetings:\n");
  evidence_get_at_index(test3, 0);
/*
  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing insert_after ***\n");
  evidence_insert_after(sal *list, char *sought_val, char *new_val);

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing insert_before ***\n");
  evidence_insert_before(sal *list, char *sought_val, char *new_val);

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing insert_at_index ***\n");
  evidence_insert_at_index(sal *list, size_t index, char *new_val);

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing remove_first ***\n");
  evidence_remove_first(sal *list, char *sought_val);

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing remove_all ***\n");
  evidence_remove_all(sal *list, char *sought_val);

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing act_on_strings ***\n");
  evidence_act_on_strings(sal *list, void(*f)(char*));

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing filter ***\n");
  evidence_filter(sal *list, int(*test)(char*));
*/

return 0;
}
