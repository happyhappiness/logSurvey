 
 #include "config.h"
 #include "AccessLogEntry.h"
+#include "format/Quoting.h"
+#include "format/Tokens.h"
 #include "log/File.h"
 #include "log/Formats.h"
-#include "log/Gadgets.h"
-#include "log/Tokens.h"
 #include "SquidTime.h"
 
 void
 Log::Format::HttpdCommon(AccessLogEntry * al, Logfile * logfile)
 {
     char clientip[MAX_IPSTRLEN];
-    const char *user_auth = FormatName(al->cache.authuser);
-    const char *user_ident = FormatName(al->cache.rfc931);
+    const char *user_auth = ::Format::QuoteUrlEncodeUsername(al->cache.authuser);
+    const char *user_ident = ::Format::QuoteUrlEncodeUsername(al->cache.rfc931);
 
     logfilePrintf(logfile, "%s %s %s [%s] \"%s %s %s/%d.%d\" %d %"PRId64" %s%s:%s%s",
                   al->cache.caddr.NtoA(clientip,MAX_IPSTRLEN),
