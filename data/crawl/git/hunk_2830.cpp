 	return hold_lock_file_for_update_timeout(lk, path, flags, 0);
 }
 
-/*
- * Like `hold_lock_file_for_update()`, but before returning copy the
- * existing contents of the file (if any) to the lockfile and position
- * its write pointer at the end of the file. The flags argument and
- * error handling are described above.
- */
-extern int hold_lock_file_for_append(struct lock_file *lk,
-				     const char *path, int flags);
-
 /*
  * Append an appropriate error message to `buf` following the failure
- * of `hold_lock_file_for_update()` or `hold_lock_file_for_append()`
- * to lock `path`. `err` should be the `errno` set by the failing
- * call.
+ * of `hold_lock_file_for_update()` to lock `path`. `err` should be the
+ * `errno` set by the failing call.
  */
 extern void unable_to_lock_message(const char *path, int err,
 				   struct strbuf *buf);
 
 /*
  * Emit an appropriate error message and `die()` following the failure
- * of `hold_lock_file_for_update()` or `hold_lock_file_for_append()`
- * to lock `path`. `err` should be the `errno` set by the failing
+ * of `hold_lock_file_for_update()` to lock `path`. `err` should be the
+ * `errno` set by the failing
  * call.
  */
 extern NORETURN void unable_to_lock_die(const char *path, int err);