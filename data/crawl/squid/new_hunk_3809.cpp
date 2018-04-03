 */

#include "squid.h"
#include "acl/TimeData.h"
#include "acl/Checklist.h"
#include "wordlist.h"

ACLTimeData::ACLTimeData () : weekbits (0), start (0), stop (0), next (NULL) {}
