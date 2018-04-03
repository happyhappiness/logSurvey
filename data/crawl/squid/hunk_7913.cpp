 
 void cached_error_entry(entry, type, msg)
      StoreEntry *entry;
-     error_t type;
+     int type;
      char *msg;
 {
-    if (type == ERR_NONE || type > ERR_MAX)
-	return;
+    int index;
+    if (type < ERR_MIN || type > ERR_MAX)
+	fatal_dump("cached_error_entry: type out of range.");
+    index = (int) (type - ERR_MIN);
     sprintf(tmp_error_buf, CACHED_ERROR_MSG_P1,
 	entry->url,
 	entry->url,
-	ErrorData[type].shrt);
+	ErrorData[index].shrt);
     if (msg) {
 	sprintf(tbuf, CACHED_ERROR_MSG_P2, msg);
 	strcat(tmp_error_buf, tbuf);
     }
     sprintf(tbuf, CACHED_ERROR_MSG_P3,
-	ErrorData[type].lng,
+	ErrorData[index].lng,
 	SQUID_VERSION,
 	getMyHostname());
     strcat(tmp_error_buf, tbuf);
+    entry->mem_obj->abort_code = type;
     storeAbort(entry, tmp_error_buf);
-    if (!log_errors)
-	return;
-    CacheInfo->log_append(CacheInfo,
-	entry->url,
-	"0.0.0.0",
-	entry->mem_obj->e_current_len,
-	ErrorData[type].tag,
-	"GET");
 }
 
 
 
 char *cached_error_url(url, type, msg)
      char *url;
-     error_t type;
+     int type;
      char *msg;
 {
-    tmp_error_buf[0] = '\0';
+    int index;
 
-    if (type == ERR_NONE || type > ERR_MAX)
-	return tmp_error_buf;
+    tmp_error_buf[0] = '\0';
+    if (type == ERR_MIN || type > ERR_MAX)
+	fatal_dump("cached_error_url: type out of range.");
+    index = (int) (type - ERR_MIN);
     sprintf(tmp_error_buf, CACHED_ERROR_MSG_P1,
 	url,
 	url,
-	ErrorData[type].shrt);
+	ErrorData[index].shrt);
 
     if (msg) {
 	sprintf(tbuf, CACHED_ERROR_MSG_P2, msg);
 	strcat(tmp_error_buf, tbuf);
     }
     sprintf(tbuf, CACHED_ERROR_MSG_P3,
-	ErrorData[type].lng,
+	ErrorData[index].lng,
 	SQUID_VERSION,
 	getMyHostname());
     if (!log_errors)
