/* Melanie Chow
   Winter 2018, CS152
   HW 5
*/

#include "sal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

sal *list_new()
{
  sal *ret_list=malloc(sizeof (sal));
  ret_list->values = NULL;
  ret_list->num_items = 0;
  return ret_list;
}

void list_free(sal *list)
{
  size_t len=list->num_items;
  char **arr=list->values;
  for (int i =0; i<len ; i++){
    free(arr[i]);
  }
  free(list);
}

void list_show(FILE *f, sal *list, char sep)
{
  //empty array
  if (list->num_items == 0){
    fprintf(f,"[]");
  }
  else {
    putchar('[');
    char **arr = list->values;
    size_t len=list->num_items;
    for (int i=0; i<len-1; i++){
      fprintf(f, "%s%c", arr[i], sep);
    }
    fprintf(f,"%s", arr[len-1]);
    putchar(']');
  }
}

sal *add_to_front(sal *list, char *val)
{
    //create variables
    size_t len = list->num_items;
    char **oldValues=list->values;
    size_t newsize=len+1;
    char **newValues = malloc(sizeof(char*) * newsize);

    //add to front (0th position)
    newValues[0]=strdup(val);

    //copy remainig values and free old array
    for (int i=0; i < len ; i++){
        newValues[i+1]=strdup(oldValues[i]);
    }
    //free old array
    for (int i =0; i<len ; i++){
      free(oldValues[i]);
    }
    free(oldValues);

    //assign new array & size
    list->values=newValues;
    list->num_items=newsize;

    return list;
}


/* Return the index of the first occurrence of the node containing the string, or -1. */
int find_first(sal *list, char *val)
{
  size_t len=list->num_items;
  char **arr = list->values;
  for (int i=0; i<len; i++){
    if (strcmp (arr[i], val) == 0){
      return i;
    }
  }
  return -1;
}

char *get_first(sal *list)
{
  //if list is empty
  if (list->num_items < 1){
    return NULL;
  }
  //return first string in array list
  return list->values[0];
}

char *get_last(sal *list)
{
  //if list is empty
  if (list->num_items < 1){
    return NULL;
  }
  size_t len=list->num_items;
  return list->values[len - 1];
}

char *get_at_index(sal *list, size_t index)
{
  //if given index does not exist
  if (index >= list->num_items){
    return NULL;
  }
  return list->values[index];
}

/* Insert a pointer to a duplicate of new_val after the first
 * occurrence of the sought_val, if sought_val occurs in the list;
 * otherwise return NULL.
 */
sal *insert_after(sal *list, char *sought_val, char *new_val)
{
  //get index of sought_val
  int index=find_first(list,sought_val);
  if (index==-1){
    return NULL;
  }

  //create new variables
  size_t len = list->num_items;
  char** oldValues=list->values;
  size_t newsize=len+1;
  char **newValues = malloc(sizeof(char*) * newsize);

  //copy contents into new array up to index of sought-val
  for (int i=0; i<=index; i++){
    newValues[i]=strdup(oldValues[i]);
  }
  //add value after index
  newValues[index+1]=strdup(new_val);
  //add the rest of the values after index
  for (int i=index+1; i < len ; i++){
    newValues[i+1]=strdup(oldValues[i]);
  }

  //assign new array & size
  list->values=newValues;
  list->num_items=newsize;

  //free old array
  for (int i =0; i<len ; i++){
    free(oldValues[i]);
  }
  free(oldValues);

  return list;
}


sal *insert_before(sal *list, char *sought_val, char *new_val)
{
  //get index of sought_val
  int index=find_first(list,sought_val);
  if (index==-1){
    return NULL;
  }

  //create new variables
  size_t len = list->num_items;
  char** oldValues=list->values;
  size_t newsize=len+1;
  char **newValues = malloc(sizeof(char*) * newsize);

  //copy contents into new array until index of sought-value;
  for (int i=0; i<index; i++){
    newValues[i]=strdup(oldValues[i]);
  }
  //add value before index
  newValues[index]=strdup(new_val);
  //add the rest of the values after index
  for (int i=index; i < len ; i++){
    newValues[i+1]=strdup(oldValues[i]);
  }

  //assign new array & size
  list->values=newValues;
  list->num_items=newsize;

  //free old array
  for (int i =0; i<len ; i++){
    free(oldValues[i]);
  }
  free(oldValues);

  return list;
}


sal *insert_at_index(sal *list, size_t index, char *new_val)
{
  size_t len = list->num_items;
  char** oldValues=list->values;
  //if index not in list
  if (index>=len){
    return NULL;
  }

  size_t newsize=len+1;
  char **newValues = malloc(sizeof(char*) * newsize);

  //copy contents into new array up to index of sought-val
  for (int i=0; i<index; i++){
    newValues[i]=strdup(oldValues[i]);
  }
  //add value after index
  newValues[index]=strdup(new_val);
  //add the rest of the values after index
  for (int i=index; i < len ; i++){
    newValues[i+1]=strdup(oldValues[i]);
  }

  //assign new array & size
  list->values=newValues;
  list->num_items=newsize;

  //free old array
  for (int i =0; i<len ; i++){
    free(oldValues[i]);
  }
  free(oldValues);

  return list;
}

/* Remove the first pointer containing an occurrence of sought_val,
 * if one exists, freeing its string.  If there is no such occurrence,
 * return NULL.
 */
sal *remove_first(sal *list, char *sought_val)
{
  //get index of sought_val
  int index=find_first(list,sought_val);
  if (index==-1){
    return NULL;
  }

  //create new variables
  size_t len = list->num_items;
  char** oldValues=list->values;
  size_t newsize=len-1;
  char **newValues = malloc(sizeof(char*) * newsize);

  //copy contents into new array until index of sought-value;
  for (int i=0; i<index; i++){
    newValues[i]=strdup(oldValues[i]);
  }

  //overwrite position and copy remaining values
  for (int i=index; i < len -1; i++){
    newValues[i]=strdup(oldValues[i+1]);
  }

  //free old array
  for (int i =0; i<len ; i++){
    free(oldValues[i]);
  }
  free(oldValues);

  //assign new array & size
  list->values=newValues;
  list->num_items=newsize;

  return list;
}

/* Remove occurrences of sought_val, freeing the strings. If there is
 * no such occurrence, return NULL.
 */
sal *remove_all(sal *list, char *sought_val)
{
  //Check if sought_val is present
  while (find_first(list,sought_val) != -1){
    remove_first(list,sought_val);
  }
  return list;
}

sal *act_on_strings(sal *list, void(*f)(char*))
{
  size_t len=list->num_items;
  char **arr = list->values;
  for (int i=0;i<len; i++){
    f(arr[i]);
  }
  return list;
}

/* Remove from the list and free every string that does not pass the test.
 * Do not allocate a new array list.
 */

sal *filter(sal *list, int(*test)(char*))
{
  size_t len=list->num_items;
  char **arr = list->values;
  for (int i=0; i<len; i++){
    if (test(arr[i]) == 0){
      free(arr[i]);
      arr[i]=NULL;
    }
  }
  return list;
}
