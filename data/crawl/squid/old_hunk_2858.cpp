 *
 */

#include "squid.h"
#include "log/File.h"
#include "SquidTime.h"

#if USE_USERAGENT_LOG
static Logfile *useragentlog = NULL;
#endif

void
useragentOpenLog(void)
{
#if USE_USERAGENT_LOG
    assert(NULL == useragentlog);

    if (!Config.Log.useragent || (0 == strcmp(Config.Log.useragent, "none"))) {
        debugs(40, 1, "User-Agent logging is disabled.");
        return;
    }

    useragentlog = logfileOpen(Config.Log.useragent, 0, 1);
#endif
}

void
useragentRotateLog(void)
{
#if USE_USERAGENT_LOG

    if (NULL == useragentlog)
        return;

    logfileRotate(useragentlog);

#endif
}

void
logUserAgent(const char *client, const char *agent)
{
#if USE_USERAGENT_LOG
    static time_t last_time = 0;
    static char time_str[128];
    const char *s;

    if (NULL == useragentlog)
        return;

    if (squid_curtime != last_time) {
        s = mkhttpdlogtime(&squid_curtime);
        strcpy(time_str, s);
        last_time = squid_curtime;
    }

    logfilePrintf(useragentlog, "%s [%s] \"%s\"\n",
                  client,
                  time_str,
                  agent);
#endif
}

void
useragentLogClose(void)
{
#if USE_USERAGENT_LOG

    if (NULL == useragentlog)
        return;

    logfileClose(useragentlog);

    useragentlog = NULL;

#endif
}
