#include <stdio.h>
#include <assert.h>
#include "state-machine.h"

StateReturnCode TrafficLightRed(void);
StateReturnCode TrafficLightYellow(void);
StateReturnCode TrafficLightGreen(void);
StateReturnCode MajorFailure(void);
StateReturnCode NoOperation(void);
void executeStateMachine(void);
State activeState;

// array of pointers, pointing to the state machine functions
StateFunction stateMachineFunctions[] = {
    TrafficLightRed,
    TrafficLightYellow,
    TrafficLightGreen,
    MajorFailure,
    NoOperation,
    // must be synchronized with State enum (definde in .h)
    // every state must have a function declared here in the same order as the enum
};

// state transitions are defined here
//   the transitions depend on the return code of the active state
//   (as an extra feature, a post-state delay can be defined)
StateTransitionStruct transitionsTable[] = {
    { stateRed,	         ok,  1, stateYellow }, // if the return code of "stateRed" is "ok", next state is "stateYellow"
    { stateYellow,       ok,  2, stateGreen },
    { stateGreen,        ok,  2, stateRed },
    // error situations
    { stateRed,          nok, 0, stateMajorFailure },
    { stateYellow,       nok, 0, stateMajorFailure },
    { stateGreen,        nok, 0, stateMajorFailure },
    { stateMajorFailure, ok,  0, stateNoOperation },
    { stateNoOperation,  ok,  0, stateNoOperation },
};

#define NUM_TRANSITIONS (sizeof(transitionsTable) / sizeof(StateTransitionStruct))


void main()
{
    activeState = stateGreen;

    for (int i = 0; i < 12; i++)
    {
        executeStateMachine();
    }

    getchar();
}

StateReturnCode TrafficLightRed(void)
{
	printf("RED\n");
	return ok;
}

StateReturnCode TrafficLightYellow(void)
{
    printf("YELLOW\n");

    // We simulate a failure the second thime when this function is called
    static counter = 0;
    counter++;
    if (counter == 2)
        return nok; 

    return ok;
}

StateReturnCode TrafficLightGreen(void)
{
	printf("GREEN\n");
	return ok;
}

StateReturnCode MajorFailure(void)
{
	printf("MajorFailure: BLINKING YELLOW\n");
	return ok;
}

StateReturnCode NoOperation(void)
{
	printf("NO OPERATION\n");
	return ok;
}

// O(n) function; can be reduced to O(1) by using a matrix
// e.g. transitionsTable[stateRed][ok] = ...
boolean FindNextState(State *state, StateReturnCode returnCode, unsigned int *postDelay)
{
	for (int i = 0; i < NUM_TRANSITIONS; i++)
	{
		if ((transitionsTable[i].sourceState == *state)
			&& (transitionsTable[i].stateReturnCode == returnCode))
		{
			StateTransitionStruct *transition = &transitionsTable[i];

			*state = transition->destinationState;
			*postDelay = transition->postStateDelay;
			return TRUE;
		}
	}
	return FALSE;
}

void executeStateMachine()
{
	StateReturnCode stateReturnCode = ok;
	static unsigned int timer = 0;
    boolean status;

	if (timer > 0) 
	{
		timer--;
		printf(" timer %d\n", timer);
	}

    boolean isTimeToExecute = (timer == 0);
	if (isTimeToExecute)
	{
		assert(activeState >= 0);
		assert(activeState <= NUM_STATES);

		stateReturnCode = (stateMachineFunctions[activeState])();

        status = FindNextState(&activeState, stateReturnCode, &timer);
		if (status == FALSE)
		{ 
            assert(0); //unknown transition; should not get here; 
		}
	}
}




