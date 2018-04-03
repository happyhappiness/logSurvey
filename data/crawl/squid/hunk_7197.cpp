     if (type < ERR_MIN || type > ERR_MAX)
 	fatal_dump("squid_error_entry: type out of range.");
     error_index = (int) (type - ERR_MIN);
-    debug(4, 1, "%s: %s\n", ErrorData[error_index].tag, entry->url);
+    debug(4, 1) ("%s: %s\n", ErrorData[error_index].tag, entry->url);
     sprintf(tmp_error_buf, SQUID_ERROR_MSG_P1,
 	entry->url,
 	entry->url,
