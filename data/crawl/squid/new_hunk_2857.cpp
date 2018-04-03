 *
 */

#include "config.h"
#include "AccessLogEntry.h"
#include "HttpRequest.h"
#include "log/File.h"
#include "log/Formats.h"
#include "SquidTime.h"

void
Log::Format::SquidReferer(AccessLogEntry *al, Logfile *logfile)
{
    const char *referer = al->request->header.getStr(HDR_REFERER);

    // do not log unless there is something to be displayed
    if (!referer || *referer == '\0')
        return;

    char clientip[MAX_IPSTRLEN];

    logfilePrintf(logfile, "%9ld.%03d %s %s %s\n",
                  (long int) current_time.tv_sec,
                  (int) current_time.tv_usec / 1000,
                  al->cache.caddr.NtoA(clientip, MAX_IPSTRLEN),
                  referer,
                  al->url ? al->url : "-");
}
