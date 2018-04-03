 */

#include "CacheManager.h"
#include "squid.h"

static CacheManager *cm=0;

CacheManager::CacheManager()
{
}

void
CacheManager::registerAction(char const * action, char const * desc, OBJH * handler, int pw_req_flag, int atomic)
{
    return;
}

void
CacheManager::registerAction(CacheManagerAction *anAction)
{
    return;
}

CacheManagerAction *
CacheManager::findAction(char const * action)
{
    return 0;
}

void
CacheManager::Start(int fd, HttpRequest * request, StoreEntry * entry)
{
    return;
}

CacheManager*
CacheManager::GetInstance(void)
{
    if (!cm)
        cm=new CacheManager();
    return cm;
}

