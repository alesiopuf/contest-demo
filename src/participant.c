//
// Created by user on 3/13/2024.
//
#include "../header/participant.h"

#include <string.h>
#include <assert.h>

/**
 * Initializes a participant
 * @param nume surname of participant
 * @param prenume name of participant
 * @param scor score of participant
 * @return A now participant struct with fields having the parameter values
 */
Participant constructParticipant(char* nume, char* prenume, float scor) {
    Participant participant;
    strcpy(participant.nume, nume);
    strcpy(participant.prenume, prenume);
    participant.scor = scor;
    return participant;
}

/**
 * Destorys a participant
 * @param participant The participant to be destoryed
 */
void destructParticipant(Participant* participant) {
    participant->nume[0] = '\0';
    participant->prenume[0] = '\0';
    participant->scor = -1;
}

/**
 * Compares two participants
 * @param p1 first part
 * @param p2 second part
 * @return 0 if they have same content
 */
int compareParticipant(Participant p1, Participant p2) {
    if (strcmp(p1.nume,p2.nume) != 0 || strcmp(p1.prenume,p2.prenume) != 0 || p1.scor != p2.scor)
        return 1;
    return 0;
}

/**
 * Validates an already created participant
 * @param participant Participant to be validated
 * @return 0 if the participant is valid, and 1,2,3 otherwise, depending on the invalid field
 */
int validateParticipant(Participant participant) {
    if (strlen(participant.nume) == 0)
        return 1;
    if (strlen(participant.prenume) == 0)
        return 2;
    if (participant.scor < 0)
        return 3;
    return 0;
}

void testDestructParticipant() {
    Participant participant = constructParticipant("puf", "a", 10);
    destructParticipant(&participant);
    assert(strlen(participant.nume)==0);
    assert(strlen(participant.prenume)==0);
    assert(participant.scor==-1);
}
