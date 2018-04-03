#include "authenticate.h"
#include "ACL.h"
#include "client_side.h"
#include "AuthConfig.h"
#include "AuthScheme.h"
#include "AuthUser.h"
#include "HttpReply.h"
#include "HttpRequest.h"

/*
 *
 * Private Data
 *
 */

MemPool *AuthUserHashPointer::pool = NULL;

/**** PUBLIC FUNCTIONS (ALL GENERIC!)  ****/

int
authenticateActiveSchemeCount(void)
{
    int rv = 0;

    for (authConfig::iterator i = Config.authConfiguration.begin(); i != Config.authConfiguration.end(); ++i)
        if ((*i)->configured())
            ++rv;

    debug(29, 9) ("authenticateActiveSchemeCount: %d active.\n", rv);

