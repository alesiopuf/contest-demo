//
// Created by user on 3/13/2024.
//
#ifndef POO_LAB_2_4_MYLIST_H
#define POO_LAB_2_4_MYLIST_H

#include "participant.h"

typedef Participant ElemType;
typedef struct {
	ElemType elems[50];
	int len;
} MyList;

/**
 * Initializes a new empty list
 * @return created list
 */
MyList create();

/**
 * Destroys a list
 * @param l list to be destroyed
 */
void destroy(MyList* l);

/**
 * Finds the element in a list at a certain position
 * @param l list to be searched
 * @param poz position searched
 * @return element found
 */
ElemType get(MyList* l, int poz);

/**
 * Checks the length of the list
 * @param l list to be checked
 * @return how many elements are in the list
 */
int size(MyList* l);

/**
 * Adds a new element at the end of the list
 * @param l list to be added to
 * @param el element to be added
 */
void add(MyList* l, ElemType el);

/**
 * Updates an element of the list
 * @param l list to be added to
 * @param poz position searched
 * @param el element to be added
 */
void put(MyList* l, int poz, ElemType el);

/**
 * Deletes element at given position
 * @param l list to delete from
 * @param poz position to delete from
 */
void delete(MyList* l, int poz);

/**
 * Checks if list contains element
 * @param l list to be searched
 * @param el element to be searched
 * @return 1 if it contains, 0 otherwise
 */
int contains(MyList* l, ElemType el);

void testDestroyList();

#endif //POO_LAB_2_4_MYLIST_H