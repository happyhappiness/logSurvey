 };
 
 static PF dnsShutdownRead;
+static PF dnsFDClosed;
 static dnsserver_t **dns_child_table = NULL;
+static int NDnsServersRunning = 0;
+
+static void
+dnsFDClosed(int fd, void *data)
+{
+    dnsserver_t *dns = data;
+    NDnsServersRunning--;
+    if (shutting_down || reconfiguring)
+	return;
+    debug(34, 0) ("WARNING: DNSSERVER #%d (FD %d) exited\n",
+	dns->id, fd);
+    if (NDnsServersRunning < Config.dnsChildren / 2)
+	fatal("Too few DNSSERVER processes are running");
+}
 
 dnsserver_t *
 dnsGetFirstAvailable(void)
