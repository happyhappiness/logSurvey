 
 #include "libcollectdclient/client.h"
 
+#include <assert.h>
+
+#include <errno.h>
+
+#include <getopt.h>
+
 #include <stdio.h>
 #include <stdlib.h>
-#include <errno.h>
 #include <string.h>
+
 #include <unistd.h>
-#include <getopt.h>
 
 #define DEFAULT_SOCK LOCALSTATEDIR"/run/"PACKAGE_NAME"-unixsock"
 
 extern char *optarg;
-
-static int flush (
-    const char *address,
-    const char *plugin,
-    const char *ident_str,
-    int timeout)
-{
-  lcc_connection_t *connection;
-  lcc_identifier_t ident;
-
-  /* Pointer which is passed to lcc_flush.
-   * Either a null pointer or it points to ident */
-  lcc_identifier_t *identp;
-  int status;
-
-  connection = NULL;
-  status = lcc_connect(address, &connection);
-  if (status != 0) {
-    fprintf (stderr, "ERROR: Connecting to daemon at %s failed: %s.\n",
-        address, strerror (errno));
-    return 1;
-  }
-
-  identp = NULL;
-  if (ident_str != NULL && *ident_str != '\0') {
-    status = lcc_string_to_identifier (connection, &ident, ident_str);
-    if (status != 0) {
-      fprintf (stderr, "ERROR: Creating and identifier failed: %s.\n",
-          lcc_strerror(connection));
-      LCC_DESTROY (connection);
-
-      return 1;
-    }
-    identp = &ident;
-  }
-
-  status = lcc_flush (connection, plugin, identp, timeout);
-  if (status != 0) {
-    fprintf (stderr, "ERROR: Flushing failed: %s.\n",
-        lcc_strerror (connection));
-    LCC_DESTROY (connection);
-
-    return 1;
-  }
-
-  LCC_DESTROY (connection);
-
-  return 0;
-}
+extern int   optind;
 
 static void exit_usage (const char *name, int status) {
   fprintf ((status == 0) ? stdout : stderr,
-      "Usage: %s [options]\n\n"
+      "Usage: %s [options] <command> [cmd options]\n\n"
 
       "Available options:\n"
-      "  -s             Path to collectd's UNIX socket.\n"
-      "                 Default: "DEFAULT_SOCK"\n"
-      "  -p <plugin>    Plugin to be flushed.\n"
-      "  -i <id>        Flush data identified by <id> only (see below).\n"
-      "  -t <seconds>   Flush values older than this value only.\n"
+      "  -s       Path to collectd's UNIX socket.\n"
+      "           Default: "DEFAULT_SOCK"\n"
+
+      "\n  -h       Display this help and exit.\n"
 
-      "\n  -h             Display this help and exit.\n"
+      "\nAvailable commands:\n\n"
 
-      "\nIdentfiers:\n\n"
+      " * flush [timeout=<seconds>] [plugin=<name>] [identifier=<id>]\n"
 
-      "An identifier (as accepted by the -i option) has the following\n"
-      "format:\n\n"
+      "\nIdentifiers:\n\n"
+
+      "An identifier has the following format:\n\n"
 
       "  [<hostname>/]<plugin>[-<plugin_instance>]/<type>[-<type_instance>]\n\n"
 
