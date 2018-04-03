    return a->i - b->i;
}

class SplayCheck
{
  public:
    static void BeginWalk();
    static int LastValue;
    static bool ExpectedFail;
    static void WalkVoid(void *const &, void *);
    static void WalkNode(intnode *const &, void *);
    static void WalkNodeRef(intnode const &, void *);
    static void CheckNode(intnode const &);
};

int SplayCheck::LastValue (0);
bool SplayCheck::ExpectedFail (false);

void
SplayCheck::BeginWalk()
{
    LastValue = 0;
}

void
SplayCheck::WalkVoid(void *const &node, void *state)
{
    intnode *A = (intnode *)node;
    CheckNode(*A);
}

void
SplayCheck::CheckNode(intnode const &A)
{
    if (LastValue > A.i) {
	/* failure */
	if (!ExpectedFail)
	    exit (1);
    } else
	/* success */
	if (ExpectedFail)
	    exit (1);
    LastValue = A.i;
}

void
SplayCheck::WalkNode (intnode *const &a, void *state)
{
    CheckNode (*a);
}

void
SplayCheck::WalkNodeRef (intnode const &a, void *state)
{
    CheckNode (a);
}

void
