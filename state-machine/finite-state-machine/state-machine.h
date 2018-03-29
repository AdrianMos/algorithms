typedef char boolean;
#define TRUE 1
#define FALSE 0

typedef enum
{
    ok = 0,
    nok,
    abort
    //add more return codes if needed
} StateReturnCode;

// state machine function prototype
typedef StateReturnCode(*StateFunction)(void);


// all possible states
typedef enum
{
    stateRed = 0,
    stateYellow,
    stateGreen,
    stateMajorFailure,
    // add states here; must be synchronized with stateMachineFunctions[]
    stateNoOperation
} State;

#define NUM_STATES (stateNoOperation-stateRed)

typedef struct {
    State sourceState;
    StateReturnCode stateReturnCode;
    unsigned int postStateDelay;
    State destinationState;
} StateTransitionStruct;

