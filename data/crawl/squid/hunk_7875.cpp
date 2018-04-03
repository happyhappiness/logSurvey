 	     * errno indicates that the directory doesn't exist */
 	    if (errno != ENOENT)
 		continue;
-	    sprintf(tmp_error_buf, "WARNING: Cannot write to %s for storage swap area.\nForcing a *full restart* (e.g., cached -z)...", name);
-#if HAVE_SYSLOG
-	    if (syslog_enable)
-		syslog(LOG_ALERT, tmp_error_buf);
-#endif
-	    fprintf(stderr, "cached: %s\n", tmp_error_buf);
+	    debug(20,0, "WARNING: Cannot write to '%s' for storage swap area.\n", name);
+	    debug(20,0, "Forcing a *full restart* (e.g., cached -z)...");
 	    zap_disk_store = 1;
 	    return;
 	}
