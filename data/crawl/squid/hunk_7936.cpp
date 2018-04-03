 	     * errno indicates that the directory doesn't exist */
 	    if (errno != ENOENT)
 		continue;
-	    sprintf(tmpbuf, "WARNING: Cannot write to %s for storage swap area.\nForcing a *full restart* (e.g., cached -z)...", name);
+	    sprintf(tmp_error_buf, "WARNING: Cannot write to %s for storage swap area.\nForcing a *full restart* (e.g., cached -z)...", name);
 #if HAVE_SYSLOG
 	    if (syslog_enable)
-		syslog(LOG_ALERT, tmpbuf);
+		syslog(LOG_ALERT, tmp_error_buf);
 #endif
-	    fprintf(stderr, "cached: %s\n", tmpbuf);
+	    fprintf(stderr, "cached: %s\n", tmp_error_buf);
 	    zap_disk_store = 1;
 	    return;
 	}
