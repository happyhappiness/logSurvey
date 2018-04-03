#include "enums.h"
/* some parameters stil need this */
#include "wordlist.h"
#include "anyp/ProtocolType.h"
#include "Debug.h"
#include "HttpHeader.h"
#include "HttpStatusCode.h"
#include "lookup_t.h"


class HttpRequestMethod;
#if USE_DELAY_POOLS
class ClientInfo;
#endif


class FwdState;


class HttpRequest;
class HttpReply;

/* TODO: move to StrList.h */
SQUIDCEXTERN void strListAdd(String * str, const char *item, char del);
SQUIDCEXTERN int strListIsMember(const String * str, const char *item, char del);
SQUIDCEXTERN int strListIsSubstr(const String * list, const char *s, char del);
SQUIDCEXTERN int strListGetItem(const String * str, char del, const char **item, int *ilen, const char **pos);

extern const char *getStringPrefix(const char *str, const char *end);



/* store report about current header usage and other stats */
void httpHeaderStoreReport(StoreEntry * e);
