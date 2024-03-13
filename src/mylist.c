//
// Created by user on 3/13/2024.
//
#include "../header/mylist.h"

#include <assert.h>

/**
 * Initializes a new empty list
 * @return created list
 */
MyList create() {
	MyList rez;
	rez.len = 0;
	return rez;
}

/**
 * Destroys a list
 * @param l list to be destroyed
 */
void destroy(MyList* l) {
	l->len = 0;
}

/**
 * Checks the length of the list
 * @param l list to be checked
 * @return how many elements are in the list
 */
int size(MyList* l) {
    return l->len;
}

/**
 * Finds the element in a list at a certain position
 * @param l list to be searched
 * @param poz position searched
 * @return element found
 */
ElemType get(MyList* l, int poz) {
	return l->elems[poz];
}

/**
 * Adds a new element at the end of the list
 * @param l list to be added to
 * @param el element to be added
 */
void add(MyList* l, ElemType el) {
	l->elems[l->len] = el;
	l->len++;
}

/**
 * Updates an element of the list
 * @param l list to be added to
 * @param poz position searched
 * @param el element to be added
 */
void put(MyList* l, int poz, ElemType el) {
	l->elems[poz] = el;
}

/**
 * Deletes element at given position
 * @param l list to delete from
 * @param poz position to delete from
 */
void delete(MyList* l, int poz) {
    for (int i = poz; i < l->len - 1; i++)
        l->elems[i] = l->elems[i+1];
    l->len--;
}

/**
 * Checks if list contains element
 * @param l list to be searched
 * @param el element to be searched
 * @return 1 if it contains, 0 otherwise
 */
int contains(MyList* l, ElemType el) {
    for (int i = 0; i < size(l); i++)
        if (compareParticipant(el, get(l, i)) == 0)
            return 1;
    return 0;
}

void testDestroyList() {
    MyList l = create();
    destroy(&l);
    assert(size(&l)==0);
}
