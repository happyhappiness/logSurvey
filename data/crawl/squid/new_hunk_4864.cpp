#include "ACLTimeData.h"
#include "authenticate.h"
#include "ACLChecklist.h"
#include "wordlist.h"

ACLTimeData::ACLTimeData () : weekbits (0), start (0), stop (0), next (NULL) {}

