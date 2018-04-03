
#include "config.h"
#include "AccessLogEntry.h"
#include "format/Tokens.h"
#include "log/File.h"
#include "log/Formats.h"
#include "MemBuf.h"

void
Log::Format::SquidCustom(AccessLogEntry * al, customlog * log)
{
    static MemBuf mb;
    mb.reset();

    // XXX: because we do not yet have a neutral form of transaction slab. use AccessLogEntry
    log->logFormat->assemble(mb, al, log->logfile->sequence_number);

    logfilePrintf(log->logfile, "%s\n", mb.buf);
}
