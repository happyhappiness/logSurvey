 	    fatal("Failed to open error text file");
 	}
 	if (fstat(fd, &sb) < 0)
-	    fatal_dump("stat() failed on error text file");
+	    fatal("fstat() failed on error text file");
 	safe_free(error_text[i]);
 	error_text[i] = xcalloc(sb.st_size + 1, 1);
 	if (read(fd, error_text[i], sb.st_size) != sb.st_size)
-	    fatal_dump("failed to fully read error text file");
+	    fatal("failed to fully read error text file");
 	file_close(fd);
     }
 }
 
+/*
+ * Function:  errorCon
+ *
+ * Abstract:  This function creates a ErrorState object.
+ */
+ErrorState *
+errorCon(err_type type, http_status status)
+{
+    ErrorState *err = xcalloc(1, sizeof(ErrorState));
+    err->type = type;
+    err->http_status = status;
+    return err;
+}
+
+/*
+ * Function:  errorAppendEntry
+ *
+ * Arguments: err - This object is destroyed after use in this function.
+ *
+ * Abstract:  This function generates a error page from the info contained
+ *            by 'err' and then attaches it to the specified 'entry'
+ *
+ * Note:      The above abstract is should be check for correctness!!!!
+ */
+void
+errorAppendEntry(StoreEntry * entry, ErrorState * err)
+{
+    const char *buf;
+    MemObject *mem = entry->mem_obj;
+    int len;
+    assert(entry->store_status == STORE_PENDING);
+    buf = errorBuildBuf(err, &len);
+    storeAppend(entry, buf, len);
+    if (mem)
+	mem->reply->code = err->http_status;
+    errorStateFree(err);
+    xfree(err);
+}
+
+/*
+ * Function:  errorSend
+ *
+ * Arguments: err - This object is destroyed after use in this function.
+ *
+ * Abstract:  This function generates a error page from the info contained
+ *            by 'err' and then sends it to the client.
+ *
+ * Note:      The callback function errorSendComplete() cleans up 'err'
+ *
+ * Note:      I don't think we need to add 'err' to the callback table
+ *            since the only path ends up a errorSendComplete().
+ */
+void
+errorSend(int fd, ErrorState * err)
+{
+    const char *buf;
+    int len;
+    debug(4, 3) ("errorSend: FD %d, err=%p\n", fd, err);
+    assert(fd >= 0);
+    buf = errorBuildBuf(err, &len);
+    cbdataAdd(err);
+    comm_write(fd, xstrdup(buf), len, errorSendComplete, err, xfree);
+}
+
+/*
+ * Function:  errorSendComplete
+ *
+ * Abstract:  This function 
+ *
+ * Note:      If there is a callback, the callback is responsible for
+ *            closeing the FD, otherwise we do it ourseves.
+ */
+static void
+errorSendComplete(int fd, char *buf, int size, int errflag, void *data)
+{
+    ErrorState *err = data;
+    debug(4, 3) ("errorSendComplete: FD %d, size=%d\n", fd, size);
+    if (errflag != COMM_ERR_CLOSING) {
+	if (err->callback)
+	    err->callback(fd, err->callback_data, size);
+	else
+	    comm_close(fd);
+    }
+    errorStateFree(err);
+    cbdataFree(err);
+}
+
 static void
 errorStateFree(ErrorState * err)
 {
