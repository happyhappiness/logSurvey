#include "squid.h"
#include "ACL.h"
#include "ACLChecklist.h"
#include "HttpRequest.h"

const char *AclMatchedName = NULL;

void *
ACL::operator new (size_t byteCount)
{
    fatal ("unusable ACL::new");
    return (void *)1;
}

void
ACL::operator delete (void *address)
{
    fatal ("unusable ACL::delete");
}

acl *
