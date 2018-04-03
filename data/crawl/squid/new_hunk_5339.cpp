    *list = NULL;
}

wordlist *
ACL::dumpGeneric () const
{
    debug(28, 3) ("ACL::dumpGeneric: %s type %s\n", name, typeString());
    return dump();
}

/*
 * This function traverses all ACL elements referenced
 * by an access list (presumably 'http_access').   If 
 * it finds a PURGE method ACL, then it returns TRUE,
 * otherwise FALSE.
 */
/* XXX: refactor this more sensibly. perhaps have the parser detect it ? */
int
aclPurgeMethodInUse(acl_access * a)
{
    return a->containsPURGE();
}

#include "ACLStrategised.h"
bool
acl_access::containsPURGE() const
{
