 	f = &fd_table[i];
 	if (!f->flags.open)
 	    continue;
-	storeAppendPrintf(sentry, "%4d %-6.6s %4d %7d %7d %-21s %s\n",
+	storeAppendPrintf(sentry, "%4d %-6.6s %4d %7d %7d %-21s %20s:%-5d %s\n",
 	    i,
 	    fdTypeStr[f->type],
 	    f->timeout_handler ? (int) (f->timeout - squid_curtime) / 60 : 0,
 	    f->bytes_read,
 	    f->bytes_written,
 	    fdRemoteAddr(f),
+	    f->last.line ? f->last.file : null_string,
+	    f->last.line,
 	    f->desc);
     }
 }
