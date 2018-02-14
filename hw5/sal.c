/* Melanie Chow
   Winter 2018, CS152
   HW 5
*/

#include "sal.h"
#include <stdio.h>
#include <strings.h>
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
  for (int i =0; i<len ; i++){

  }
}

void list_show(FILE *f, sal *list, char sep)
{
  //empty array
  if (list->num_items < 1){
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

sal *add_to_front(sal *list, char *val);

/* Return the index of the first occurrence of the node containing the string, or -1. */
int find_first(sal *list, char *val);

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
sal *insert_after(sal *list, char *sought_val, char *new_val);

/* Insert a pointer to a duplicate of new_val before the first
 * occurrence of the sought_val, if sought_val occurs in the list;
 * otherwise return NULL.
 */
sal *insert_before(sal *list, char *sought_val, char *new_val);

/* Insert a pointer to a duplicate of new_val in the given position.
 * Return NULL if the list has no such position.
 */
sal *insert_at_index(sal *list, size_t index, char *new_val);

/* Remove the first pointer containing an occurrence of sought_val,
 * if one exists, freeing its string.  If there is no such occurrence,
 * return NULL.
 */
sal *remove_first(sal *list, char *sought_val);

/* Remove occurrences of sought_val, freeing the strings. If there is
 * no such occurrence, return NULL.
 */
sal *remove_all(sal *list, char *sought_val);

/* Perform the given action on every item in the list.
 * Act on the strings in place; this should not build a new list.
 */
sal *act_on_strings(sal *list, void(*f)(char*));

/* Remove from the list and free every string that does not pass the test.
 * Do not allocate a new array list.
 */
sal *filter(sal *list, int(*test)(char*));
