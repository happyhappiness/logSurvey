     comm_close(fd);
 }
 
+static void
+pconnHistDump(StoreEntry * e)
+{
+    int i;
+    storeAppendPrintf(e,
+        "Client-side persistent connection counts:\n"
+        "\n"
+        "\treq/\n"
+        "\tconn      count\n"
+        "\t----  ---------\n");
+    for (i = 0; i < PCONN_HIST_SZ; i++) {
+        if (client_pconn_hist[i] == 0)
+            continue;
+        storeAppendPrintf(e, "\t%4d  %9d\n", i, client_pconn_hist[i]);
+    }
+    storeAppendPrintf(e,
+        "\n"
+        "Server-side persistent connection counts:\n"
+        "\n"
+        "\treq/\n"
+        "\tconn      count\n"
+        "\t----  ---------\n");
+    for (i = 0; i < PCONN_HIST_SZ; i++) {
+        if (server_pconn_hist[i] == 0)
+            continue;
+        storeAppendPrintf(e, "\t%4d  %9d\n", i, server_pconn_hist[i]);
+    }
+}
 
 /* ========== PUBLIC FUNCTIONS ============================================ */
 
