 *
 */

#include "config.h"
#include "AccessLogEntry.h"
#include "HttpRequest.h"
#include "log/File.h"
#include "log/Formats.h"
#include "SquidTime.h"

void
Log::Format::SquidUserAgent(AccessLogEntry * al, Logfile * logfile)
{
    char clientip[MAX_IPSTRLEN];

    const char *agent = al->request->header.getStr(HDR_USER_AGENT);

    // do not log unless there is something to be displayed.
    if (!agent || *agent == '\0')
        return;

    logfilePrintf(logfile, "%s [%s] \"%s\"\n",
                  al->cache.caddr.NtoA(clientip,MAX_IPSTRLEN),
                  Time::FormatHttpd(squid_curtime),
                  agent);
}
