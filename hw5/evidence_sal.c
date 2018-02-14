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
    //free(test);
}

void evidence_list_show(FILE *f, sal *list, char sep)
{
  list_show(f,list,sep);
  fprintf(stdout,"\n");
}


/*
sal *evidence_add_to_front(sal *list, char *val);

int evidence_find_first(sal *list, char *val);
*/

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

/*
sal *evidence_insert_after(sal *list, char *sought_val, char *new_val);

sal *evidence_insert_before(sal *list, char *sought_val, char *new_val);

sal *evidence_insert_at_index(sal *list, size_t index, char *new_val);

sal *evidence_remove_first(sal *list, char *sought_val);

sal *evidence_remove_all(sal *list, char *sought_val);

sal *evidence_act_on_strings(sal *list, void(*f)(char*));

sal *evidence_filter(sal *list, int(*test)(char*));
*/

int main()
{

  /*------------TESTS-----------------------------------------------------*/

  //TEST 1 -- arraylist of "Aa", "Bb", "Cc", "Dd", "Ee" (inital size of 5)
  sal *test1 = malloc(sizeof (sal));
  char *arr1[]={"Aa", "Bb", "Cc", "Dd", "Ee"};
  test1->values = arr1;
  test1->num_items = 5;

  //TEST 2 -- empty arraylist
  sal *test2 = list_new();

  //TEST 3 -- one item in arraylist
  sal *test3 = malloc(sizeof (sal));
  char *arr2[]={"Hiya"};
  test3->values=arr2;
  test3->num_items=1;
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
/*
  fprintf(stdout, "*** Testing add_to_front ***\n");
  evidence_add_to_front(sal *list, char *val);

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing find_first ***\n");
  evidence_find_first(sal *list, char *val);
*/

  ///////////////////////////////////////////////////////////////////////
  fprintf(stdout, "*** Testing get_first ***\n");

  fprintf(stdout,"Expecting Aa\n");
  evidence_get_first(test1);

  fprintf(stdout,"Expecting null\n");
  evidence_get_first(test2);

  fprintf(stdout,"Expecting Hiya\n");
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
  evidence_get_at_index(test1, 5);

  fprintf(stdout,"Expecting Cc\n");
  evidence_get_at_index(test1, 2);

  fprintf(stdout,"Expecting null\n");
  evidence_get_at_index(test2, 0);

  fprintf(stdout,"Expecting Hiya\n");
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
