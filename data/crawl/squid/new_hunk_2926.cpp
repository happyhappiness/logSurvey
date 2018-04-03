 */

#include "CacheManager.h"
#include "mgr/Registration.h"
#include "squid.h"

Mgr::Action::Pointer
CacheManager::createNamedAction(char const* action)
{
    fatal ("Not implemented");
    return NULL;
}

void
CacheManager::Start(int fd, HttpRequest * request, StoreEntry * entry)
{
    return;
}

CacheManager*
CacheManager::GetInstance(void)
{
    static CacheManager *instance = 0;
    if (!instance)
        instance = new CacheManager();
    return instance;
}

void
Mgr::RegisterAction(char const*, char const*, OBJH, int, int)
{
}

void
Mgr::RegisterAction(char const * action, char const * desc,
    Mgr::ClassActionCreationHandler *handler,
    int pw_req_flag, int atomic)
{
}
