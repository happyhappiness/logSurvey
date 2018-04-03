 {
     int i;
     storeAppendPrintf(dumpEntry, "Active file descriptors:\n");
+#ifdef _SQUID_MSWIN_
+
+    storeAppendPrintf(dumpEntry, "%-4s %-10s %-6s %-4s %-7s* %-7s* %-21s %s\n",
+                      "File",
+                      "Handle",
+#else
     storeAppendPrintf(dumpEntry, "%-4s %-6s %-4s %-7s* %-7s* %-21s %s\n",
                       "File",
+#endif
                       "Type",
                       "Tout",
                       "Nread",
                       "Nwrite",
                       "Remote Address",
                       "Description");
+#ifdef _SQUID_MSWIN_
+    storeAppendPrintf(dumpEntry, "---- ---------- ------ ---- -------- -------- --------------------- ------------------------------\n");
+#else
     storeAppendPrintf(dumpEntry, "---- ------ ---- -------- -------- --------------------- ------------------------------\n");
+#endif
 
     for (i = 0; i < Squid_MaxFD; i++) {
         fd_table[i].dumpStats(*dumpEntry, i);