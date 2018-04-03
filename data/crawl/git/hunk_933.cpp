 /*
  * If a lock is already taken for the file, `die()` with an error
  * message. If this flag is not specified, trying to lock a file that
- * is already locked returns -1 to the caller.
+ * is already locked silently returns -1 to the caller, or ...
  */
 #define LOCK_DIE_ON_ERROR 1
 
+/*
+ * ... this flag can be passed instead to return -1 and give the usual
+ * error message upon an error.
+ */
+#define LOCK_REPORT_ON_ERROR 2
+
 /*
  * Usually symbolic links in the destination path are resolved. This
  * means that (1) the lockfile is created by adding ".lock" to the
