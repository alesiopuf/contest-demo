//
// Created by user on 3/13/2024.
//
#include "../header/service.h"

#include <assert.h>

/**
 * Adds a participant to a list
 * @param l list to be added to
 * @param p participant to be added
 * @return 0 if successful, 1 otherwise
 */
int addParticipant(MyList* l, Participant p) {
    if (validateParticipant(p) != 0)
        return 1;
    if (contains(l, p) == 1)
        return 1;
    add(l, p);
    return 0;
}

/**
 * Updates an existing participant
 * @param l list to be modified
 * @param p participant to be changed
 * @param newParticipant new fields
 * @return 0 if successful, 1 otherwise
 */
int updateParticipant(MyList* l, Participant p, Participant newParticipant) {
    if (validateParticipant(newParticipant) != 0)
        return 1;
    for (int i = 0; i < size(l); i++)
        if (compareParticipant(get(l, i), p) == 0) {
            put(l, i, newParticipant);
            return 0;
        }
    return 1;
}

/**
 * Deletes a existing participant
 * @param l list to be deleted from
 * @param p participant to be deleted
 * @return 0 if successful, 1 otherwise
 */
int deleteParticipant(MyList* l, Participant p) {
    for (int i = 0; i < size(l); i++)
        if (compareParticipant(get(l, i), p) == 0) {
            delete(l, i);
            return 0;
        }
    return 1;
}

void testAddParticipant() {
    MyList l = create();
    assert(size(&l) == 0);
    int error;

    error = addParticipant(&l, constructParticipant("", "", 10));
    assert(error != 0);
    assert(size(&l) == 0);

    error = addParticipant(&l, constructParticipant("alesio", "", -10));
    assert(error != 0);
    assert(size(&l) == 0);

    error = addParticipant(&l, constructParticipant("puf", "alesio", 10));
    assert(error == 0);
    assert(size(&l) == 1);

    error = addParticipant(&l, constructParticipant("puf", "alesio", 10));
    assert(error == 1);
    assert(size(&l) == 1);
}

void testUpdateParticipant() {
    MyList l = create();
    assert(size(&l) == 0);
    int error;

    error = addParticipant(&l, constructParticipant("puf", "alesio", 10));
    assert(error == 0);
    assert(size(&l) == 1);

    error = updateParticipant(&l, constructParticipant("puf", "alesio", 10),
                              constructParticipant("puf", "alesio-andrei", 10));
    assert(error == 0);
    assert(size(&l) == 1);

    error = updateParticipant(&l, constructParticipant("puf", "alesio", 10),
                              constructParticipant("alesio", "alesio-andrei", -10));
    assert(error == 1);
    assert(size(&l) == 1);

    error = updateParticipant(&l, constructParticipant("puf", "alesio", 20),
                              constructParticipant("puf", "alesio-andrei", 10));
    assert(error == 1);
    assert(size(&l) == 1);
}

void testDeleteParticipant() {
    MyList l = create();
    assert(size(&l) == 0);
    int error;

    error = addParticipant(&l, constructParticipant("puf", "alesio", 10));
    assert(error == 0);
    assert(size(&l) == 1);

    error = addParticipant(&l, constructParticipant("voda", "alesio", 10));
    assert(error == 0);
    assert(size(&l) == 2);

    error = deleteParticipant(&l, constructParticipant("puf", "alesio", 10));
    assert(error == 0);
    assert(size(&l) == 1);

    error = deleteParticipant(&l, constructParticipant("puf", "alesio", 10));
    assert(error == 1);
    assert(size(&l) == 1);
}