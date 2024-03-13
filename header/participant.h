//
// Created by user on 3/12/2024.
//

#ifndef POO_LAB_2_4_PARTICIPANT_H
#define POO_LAB_2_4_PARTICIPANT_H

typedef struct {
    char nume[100];
    char prenume[100];
    float scor;
} Participant;

/**
 * Initializes a participant
 * @param nume surname of participant
 * @param prenume name of participant
 * @param scor score of participant
 * @return A now participant struct with fields having the parameter values
 */
Participant constructParticipant(char* nume, char* prenume, float scor);

/**
 * Destorys a participant
 * @param participant The participant to be destoryed
 */
void destructParticipant(Participant* participant);

/**
 * Compares two participants
 * @param p1 first part
 * @param p2 second part
 * @return 0 if they have same content, and 1,2,3 otherwise, depending on the invalid field
 */
int compareParticipant(Participant p1, Participant p2);

/**
 * Validates an already created participant
 * @param participant Participant to be validated
 * @return 0 if the participant is valid, and 1,2,3 otherwise, depending on the invalid field
 */
int validateParticipant(Participant participant);

void testDestructParticipant();

#endif //POO_LAB_2_4_PARTICIPANT_H
