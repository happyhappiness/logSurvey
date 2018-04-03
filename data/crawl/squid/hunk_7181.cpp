     meta_data.misc += MAX_URL * 3;
 }
 
-void
-squid_error_entry(StoreEntry * entry, log_type type, const char *msg)
-{
-    int error_index;
-
-    if (entry == NULL)
-	return;
-    if (entry->store_status != STORE_PENDING)
-	return;
-    if (type < ERR_MIN || type > ERR_MAX)
-	fatal_dump("squid_error_entry: type out of range.");
-    error_index = (int) (type - ERR_MIN);
-    debug(4, 1) ("%s: %s\n", ErrorData[error_index].tag, entry->url);
-    sprintf(tmp_error_buf, SQUID_ERROR_MSG_P1,
-	entry->url,
-	entry->url,
-	ErrorData[error_index].shrt);
-    if (msg) {
-	sprintf(tbuf, SQUID_ERROR_MSG_P2, msg);
-	strcat(tmp_error_buf, tbuf);
-    }
-    sprintf(tbuf, SQUID_ERROR_MSG_P3,
-	ErrorData[error_index].lng,
-	Config.errHtmlText,
-	appname,
-	version_string,
-	getMyHostname());
-    strcat(tmp_error_buf, tbuf);
-    if (entry->mem_obj) {
-	entry->mem_obj->abort_code = type;
-	if (entry->mem_obj->reply->code == 0)
-	    entry->mem_obj->reply->code = 400;
-    }
-    storeAbort(entry, tmp_error_buf);
-}
-
-
-
 char *
 squid_error_url(const char *url, int method, int type, const char *address, int code, const char *msg)
 {
