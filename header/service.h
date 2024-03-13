//
// Created by user on 3/13/2024.
//
#ifndef POO_LAB_2_4_SERVICE_H
#define POO_LAB_2_4_SERVICE_H

#include "mylist.h"
#include "participant.h"

/**
 * Adds a participant to a list
 * @param l list to be added to
 * @param p participant to be added
 * @return 0 if successful, 1 otherwise
 */
int addParticipant(MyList* l, Participant p);

/**
 * Updates an existing participant
 * @param l list to be modified
 * @param p participant to be changed
 * @param newParticipant new fields
 * @return 0 if successful, 1 otherwise
 */
int updateParticipant(MyList* l, Participant p, Participant newParticipant);

/**
 * Deletes a existing participant
 * @param l list to be deleted from
 * @param p participant to be deleted
 * @return 0 if successful, 1 otherwise
 */
int deleteParticipant(MyList* l, Participant p);

void testAddParticipant();
void testUpdateParticipant();
void testDeleteParticipant();

#endif //POO_LAB_2_4_SERVICE_H
