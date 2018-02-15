/* Melanie Chow
   CS152, Winter 2018
   HW5
*/
#include "sal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  fprintf(stdout,"\n");
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

void evidence_remove_first(sal *list, char *sought_val)
{
  remove_first(list,sought_val);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");

}

void evidence_remove_all(sal *list, char *sought_val)
{
  remove_all(list,sought_val);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");
}


void evidence_act_on_strings(sal *list, void(*f)(char*))
{
  act_on_strings(list,f);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");

}

void first_char_replace(char* str)
{
  str[0]='#';
}

void evidence_filter(sal *list, int(*test)(char*))
{
  filter(list, test);
  list_show(stdout,list,'|');
  fprintf(stdout,"\n");
}

int less_than_3 (char* str)
{
  if (strlen(str) < 3){
    return 1;
  }
  return 0;
}

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

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing insert_after ***\n");

  fprintf(stdout,"Expecting [Alphabet:|Aa|Bb|Cc|Dd|Ee|Ff]\n");
  evidence_insert_after(test1, "Ee", "Ff");

  fprintf(stdout,"Expecting [Greetings:|Biyah|Hiya]\n");
  evidence_insert_after(test3, "Greetings:", "Biyah");

  fprintf(stdout,"Expecting [] (Empty SAL)\n");
  evidence_insert_after(test2, "", "WaZOO!");

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing insert_before ***\n");

  fprintf(stdout,"Expecting [This the|Alphabet:|Aa|Bb|Cc|Dd|Ee|Ff]\n");
  evidence_insert_before(test1, "Alphabet:", "This the");

  fprintf(stdout,"Expecting [This the|Alphabet:|Aa|Bb|Cc|Cc|Dd|Ee|Ff]\n");
  evidence_insert_before(test1, "Cc", "Cc");

  fprintf(stdout,"Expecting [] (Empty SAL)\n");
  evidence_insert_before(test2, "", "WaZOO!");

  fprintf(stdout,"Expecting [Greetings:|Biyah|Hiya] (no change)\n");
  evidence_insert_before (test3, "", "WaZOO!");


  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing insert_at_index ***\n");

  fprintf(stdout,"Expecting [This the|Cc|Alphabet:|Aa|Bb|Cc|Cc|Dd|Ee|Ff]\n");
  evidence_insert_at_index(test1, 1, "Cc");

  fprintf(stdout,"Expecting [Warm|Greetings:|Biyah|Hiya]\n");
  evidence_insert_at_index(test3,0,"Warm");

  fprintf(stdout,"Expecting [] (Empty SAL)\n");
  evidence_insert_at_index(test2, 0, "WaZOO!");

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing remove_first ***\n");

  fprintf(stdout,"Expecting [Cc|Alphabet:|Aa|Bb|Cc|Cc|Dd|Ee|Ff]\n");
  evidence_remove_first(test1, "This the");

  fprintf(stdout,"Expecting [Cc|Aa|Bb|Cc|Cc|Dd|Ee|Ff]\n");
  evidence_remove_first(test1, "Alphabet:");

  fprintf(stdout,"Expecting [] (Empty SAL)\n");
  evidence_remove_first(test2, "Werp");

  fprintf(stdout,"Expecting [Warm|Greetings:|Biyah|Hiya]\n");
  evidence_remove_first(test3, "Werp");

  fprintf(stdout,"Expecting [Warm|Biyah|Hiya]\n");
  evidence_remove_first(test3, "Greetings:");

  fprintf(stdout,"Expecting [Warm|Hiya]\n");
  evidence_remove_first(test3, "Biyah");

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing remove_all ***\n");

  fprintf(stdout,"Expecting [Aa|Bb|Dd|Ee|Ff]\n");
  evidence_remove_all(test1, "Cc");

  fprintf(stdout,"Expecting [Warm|Hiya]\n");
  evidence_remove_all(test3, "Biyah");

  fprintf(stdout,"Expecting [] (Empty SAL)\n");
  evidence_remove_all(test2, "waZOO!");

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing act_on_strings ***\n");

  void(*actTest)(char*)=&first_char_replace;

  fprintf(stdout,"Expecting [#a|#b|#d|#e|#f]\n");
  evidence_act_on_strings(test1, actTest);

  fprintf(stdout,"Expecting [] (Empty SAL)\n");
  evidence_act_on_strings(test2, actTest);

  ///////////////////////////////////////////////////////////////////////
/*
  fprintf(stdout, "*** Testing filter ***\n");
  int(*filTest)(char*)=&less_than_3;

  fprintf(stdout,"Expecting [#a|#b|#d|#e|#f]\n");
  evidence_filter(test1,filTest);

  fprintf(stdout,"Expecting [null|null]\n");
  evidence_filter(test3,filTest);

  fprintf(stdout,"Expecting [] (Empty SAL)\n");
  evidence_filter(test2,filTest);
*/
  free_list(test1);
  free_list(test2);
  free_list(test3);

  return 0;
}
