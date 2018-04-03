#include "CacheManager.h"
#include "squid.h"

CacheManager::CacheManager()
{
}

void
CacheManager::registerAction(char const * action, char const * desc, OBJH * handler, int pw_req_flag, int atomic)
{
	fatal("Not implemented");
}

void
CacheManager::registerAction(CacheManagerAction *anAction)
{
	fatal("Not implemented");
}

CacheManagerAction *
CacheManager::findAction(char const * action)
{
	fatal("Not implemented");
	return 0; //notreached
}

void
CacheManager::Start(int fd, HttpRequest * request, StoreEntry * entry)
{
	fatal("Not implemented");
}

CacheManager*
CacheManager::GetInstance()
{
	fatal("Not implemented");
	return 0; //notreached
}

