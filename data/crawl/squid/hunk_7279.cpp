 #endif
 
 static const char *
-host_port_fmt(const char *host, u_short port)
+fdRemoteAddr(const FD_ENTRY * f)
 {
     LOCAL_ARRAY(char, buf, 32);
-    sprintf(buf, "%s.%d", host, (int) port);
+    if (f->type != FD_SOCKET)
+	return null_string;
+    sprintf(buf, "%s.%d", f->ipaddr, (int) f->remote_port);
     return buf;
 }
 
 static void
 statFiledescriptors(StoreEntry * sentry)
 {
     int i;
-    int to = 0;
     FD_ENTRY *f;
 
     storeAppendPrintf(sentry, open_bracket);
     storeAppendPrintf(sentry, "{Active file descriptors:}\n");
-    storeAppendPrintf(sentry, "{%-4s %-6s %-4s %-4s %-21s %s}\n",
+    storeAppendPrintf(sentry, "{%-4s %-6s %-4s %-7s %-7s %-21s %s}\n",
 	"File",
 	"Type",
-	"Lftm",
 	"Tout",
+	"Nread",
+	"Nwrite",
 	"Remote Address",
 	"Description");
-    storeAppendPrintf(sentry, "{---- ------ ---- ---- --------------------- ------------------------------}\n");
+    storeAppendPrintf(sentry, "{---- ------ ---- ------- ------- --------------------- ------------------------------}\n");
     for (i = 0; i < Squid_MaxFD; i++) {
 	f = &fd_table[i];
 	if (!f->open)
 	    continue;
-	storeAppendPrintf(sentry, "{%4d %-6s ",
+	storeAppendPrintf(sentry, "{%4d %-6.6s %4d %7d %7d %-21s %s}\n",
 	    i,
-	    fdstatTypeStr[f->type]);
-	switch (f->type) {
-	case FD_SOCKET:
-            if (f->timeout > 0)
-                to = (int) (f->timeout - squid_curtime) / 60;
-            if (f->timeout_handler == NULL)
-                to = 0;
-            storeAppendPrintf(sentry, "%4d %-21s %s}\n",
-                to,
-                host_port_fmt(f->ipaddr, f->remote_port),
-                f->desc);
-            break;
-	case FD_FILE:
-	    storeAppendPrintf(sentry, "%31s %s}\n",
-		null_string,
-		f->disk.filename);
-	    break;
-	case FD_PIPE:
-	    storeAppendPrintf(sentry, "%31s %s}\n", null_string, f->desc);
-	    break;
-	case FD_LOG:
-	    storeAppendPrintf(sentry, "%31s %s}\n", null_string, f->desc);
-	    break;
-	case FD_UNKNOWN:
-	default:
-	    storeAppendPrintf(sentry, "%31s %s}\n", null_string, f->desc);
-	    break;
-	}
+	    fdstatTypeStr[f->type],
+	    f->timeout_handler ? (f->timeout - squid_curtime) / 60 : 0,
+	    f->bytes_read,
+	    f->bytes_written,
+	    fdRemoteAddr(f),
+	    f->desc);
     }
     storeAppendPrintf(sentry, close_bracket);
 }
