 #include "cache.h"
 #include "transport.h"
 #include "run-command.h"
+#include "http.h"
+#include "pkt-line.h"
+#include "fetch-pack.h"
+#include "walker.h"
+
+/* Generic functions for using commit walkers */
+
+static int fetch_objs_via_walker(const struct transport *transport,
+				 int nr_objs, char **objs)
+{
+	char *dest = xstrdup(transport->url);
+	struct walker *walker = transport->data;
+
+	walker->get_all = 1;
+	walker->get_tree = 1;
+	walker->get_history = 1;
+	walker->get_verbosely = transport->verbose;
+	walker->get_recover = 0;
+
+	if (walker_fetch(walker, nr_objs, objs, NULL, dest))
+		die("Fetch failed.");
+
+	free(dest);
+	return 0;
+}
+
+static int disconnect_walker(struct transport *transport)
+{
+	struct walker *walker = transport->data;
+	if (walker)
+		walker_free(walker);
+	return 0;
+}
 
 static const struct transport_ops rsync_transport;
 
