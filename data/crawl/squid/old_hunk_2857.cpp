 *
 */

#include "squid.h"
#include "log/File.h"
#include "SquidTime.h"

#if USE_REFERER_LOG
static Logfile *refererlog = NULL;
#endif

void
refererOpenLog(void)
{
#if USE_REFERER_LOG
    assert(NULL == refererlog);

    if (!Config.Log.referer || (0 == strcmp(Config.Log.referer, "none"))) {
        debugs(40, 1, "Referer logging is disabled.");
        return;
    }

    refererlog = logfileOpen(Config.Log.referer, 0, 1);
#endif
}

void
refererRotateLog(void)
{
#if USE_REFERER_LOG

    if (NULL == refererlog)
        return;

    logfileRotate(refererlog);

#endif
}

void
logReferer(const char *client, const char *referer, const char *uri)
{
#if USE_REFERER_LOG

    if (NULL == refererlog)
        return;

    logfilePrintf(refererlog, "%9d.%03d %s %s %s\n",
                  (int) current_time.tv_sec,
                  (int) current_time.tv_usec / 1000,
                  client,
                  referer,
                  uri ? uri : "-");

#endif
}

void
refererCloseLog(void)
{
#if USE_REFERER_LOG

    if (NULL == refererlog)
        return;

    logfileClose(refererlog);

    refererlog = NULL;

#endif
}
