/*
 * Copyright (C) 1996-2016 The Squid Software Foundation and contributors
 *
 * Squid software is distributed under GPLv2+ license and includes
 * contributions from numerous individuals and organizations.
 * Please see the COPYING and CONTRIBUTORS files for details.
 */

#include "squid.h"
#include "fde.h"

#define STUB_API "log/liblog.la"
#include "tests/STUB.h"

#include "log/access_log.h"
void fvdbCountVia(const char *) STUB
void fvdbCountForw(const char *) STUB
#if HEADERS_LOG
void headersLog(int, int, const HttpRequestMethod &, void *) STUB
#endif

#include "log/Config.h"
namespace Log
{
void LogConfig::parseFormats() STUB
LogConfig TheConfig;
}

//#include "log/CustomLog.h"
#include "log/File.h"
CBDATA_CLASS_INIT(Logfile);
Logfile::Logfile(const char *) {STUB}
//void Logfile::f_linestart(Logfile *) STUB
//void Logfile::f_linewrite(Logfile *, const char *, size_t) STUB
//void Logfile::f_lineend(Logfile *) STUB
//void Logfile::f_flush(Logfile *) STUB
//void Logfile::f_rotate(Logfile *, const int16_t) STUB
//void Logfile::f_close(Logfile *) STUB
Logfile *logfileOpen(const char *, size_t, int) STUB_RETVAL(nullptr)
void logfileClose(Logfile *) STUB
void logfileRotate(Logfile *, int16_t) STUB
void logfileWrite(Logfile *, char *, size_t) STUB
void logfileFlush(Logfile *) STUB
void logfilePrintf(Logfile *, const char *, ...) STUB
void logfileLineStart(Logfile *) STUB
void logfileLineEnd(Logfile *) STUB

#include "log/Formats.h"
namespace Log
{
namespace Format
{
void SquidNative(const AccessLogEntryPointer &, Logfile *) STUB
void SquidIcap(const AccessLogEntryPointer &, Logfile *) STUB
void SquidUserAgent(const AccessLogEntryPointer &, Logfile *) STUB
void SquidReferer(const AccessLogEntryPointer &, Logfile *) STUB
void SquidCustom(const AccessLogEntryPointer &, CustomLog *) STUB
void HttpdCommon(const AccessLogEntryPointer &, Logfile *) STUB
void HttpdCombined(const AccessLogEntryPointer &, Logfile *) STUB
}
}

#include "log/ModDaemon.h"
int logfile_mod_daemon_open(Logfile *, const char *, size_t, int) STUB_RETVAL(0)

#include "log/ModStdio.h"
int logfile_mod_stdio_open(Logfile *, const char *, size_t, int) STUB_RETVAL(0)

#include "log/ModSyslog.h"
int logfile_mod_syslog_open(Logfile *, const char *, size_t, int) STUB_RETVAL(0)

#include "log/ModUdp.h"
int logfile_mod_udp_open(Logfile *, const char *, size_t, int) STUB_RETVAL(0)

#include "log/TcpLogger.h"
namespace Log
{
CBDATA_CLASS_INIT(TcpLogger);
int TcpLogger::Open(Logfile *, const char *, size_t, int) STUB_RETVAL(0)

/*
protected:
    TcpLogger(size_t, bool, Ip::Address);
    virtual ~TcpLogger();
    void endGracefully();
    void logRecord(const char *buf, size_t len);
    void flush();
    virtual void start() STUB
    virtual bool doneAll() const STUB_RETVAL(true)
    virtual void swanSong() STUB
*/
}
