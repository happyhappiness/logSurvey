 #define LOCK_SUFFIX ".lock"
 #define LOCK_SUFFIX_LEN 5
 
+
+/*
+ * Flags
+ * -----
+ *
+ * The following flags can be passed to `hold_lock_file_for_update()`
+ * or `hold_lock_file_for_append()`.
+ */
+
+/*
+ * If a lock is already taken for the file, `die()` with an error
+ * message. If this flag is not specified, trying to lock a file that
+ * is already locked returns -1 to the caller.
+ */
 #define LOCK_DIE_ON_ERROR 1
+
+/*
+ * Usually symbolic links in the destination path are resolved. This
+ * means that (1) the lockfile is created by adding ".lock" to the
+ * resolved path, and (2) upon commit, the resolved path is
+ * overwritten. However, if `LOCK_NO_DEREF` is set, then the lockfile
+ * is created by adding ".lock" to the path argument itself. This
+ * option is used, for example, when detaching a symbolic reference,
+ * which for backwards-compatibility reasons, can be a symbolic link
+ * containing the name of the referred-to-reference.
+ */
 #define LOCK_NO_DEREF 2
 
-extern void unable_to_lock_message(const char *path, int err,
-				   struct strbuf *buf);
-extern NORETURN void unable_to_lock_die(const char *path, int err);
+/*
+ * Attempt to create a lockfile for the file at `path` and return a
+ * file descriptor for writing to it, or -1 on error. If the file is
+ * currently locked, retry with quadratic backoff for at least
+ * timeout_ms milliseconds. If timeout_ms is 0, try exactly once; if
+ * timeout_ms is -1, retry indefinitely. The flags argument and error
+ * handling are described above.
+ */
 extern int hold_lock_file_for_update_timeout(
 		struct lock_file *lk, const char *path,
 		int flags, long timeout_ms);
 
+/*
+ * Attempt to create a lockfile for the file at `path` and return a
+ * file descriptor for writing to it, or -1 on error. The flags
+ * argument and error handling are described above.
+ */
 static inline int hold_lock_file_for_update(
 		struct lock_file *lk, const char *path,
 		int flags)
 {
 	return hold_lock_file_for_update_timeout(lk, path, flags, 0);
 }
 
-extern int hold_lock_file_for_append(struct lock_file *lk, const char *path,
-				     int flags);
+/*
+ * Like `hold_lock_file_for_update()`, but before returning copy the
+ * existing contents of the file (if any) to the lockfile and position
+ * its write pointer at the end of the file. The flags argument and
+ * error handling are described above.
+ */
+extern int hold_lock_file_for_append(struct lock_file *lk,
+				     const char *path, int flags);
+
+/*
+ * Append an appropriate error message to `buf` following the failure
+ * of `hold_lock_file_for_update()` or `hold_lock_file_for_append()`
+ * to lock `path`. `err` should be the `errno` set by the failing
+ * call.
+ */
+extern void unable_to_lock_message(const char *path, int err,
+				   struct strbuf *buf);
 
-extern FILE *fdopen_lock_file(struct lock_file *, const char *mode);
-extern char *get_locked_file_path(struct lock_file *);
-extern int commit_lock_file_to(struct lock_file *, const char *path);
-extern int commit_lock_file(struct lock_file *);
-extern int reopen_lock_file(struct lock_file *);
-extern int close_lock_file(struct lock_file *);
-extern void rollback_lock_file(struct lock_file *);
+/*
+ * Emit an appropriate error message and `die()` following the failure
+ * of `hold_lock_file_for_update()` or `hold_lock_file_for_append()`
+ * to lock `path`. `err` should be the `errno` set by the failing
+ * call.
+ */
+extern NORETURN void unable_to_lock_die(const char *path, int err);
+
+/*
+ * Associate a stdio stream with the lockfile (which must still be
+ * open). Return `NULL` (*without* rolling back the lockfile) on
+ * error. The stream is closed automatically when `close_lock_file()`
+ * is called or when the file is committed or rolled back.
+ */
+extern FILE *fdopen_lock_file(struct lock_file *lk, const char *mode);
+
+/*
+ * Return the path of the file that is locked by the specified
+ * lock_file object. The caller must free the memory.
+ */
+extern char *get_locked_file_path(struct lock_file *lk);
+
+/*
+ * If the lockfile is still open, close it (and the file pointer if it
+ * has been opened using `fdopen_lock_file()`) without renaming the
+ * lockfile over the file being locked. Return 0 upon success. On
+ * failure to `close(2)`, return a negative value and roll back the
+ * lock file. Usually `commit_lock_file()`, `commit_lock_file_to()`,
+ * or `rollback_lock_file()` should eventually be called if
+ * `close_lock_file()` succeeds.
+ */
+extern int close_lock_file(struct lock_file *lk);
+
+/*
+ * Re-open a lockfile that has been closed using `close_lock_file()`
+ * but not yet committed or rolled back. This can be used to implement
+ * a sequence of operations like the following:
+ *
+ * * Lock file.
+ *
+ * * Write new contents to lockfile, then `close_lock_file()` to
+ *   cause the contents to be written to disk.
+ *
+ * * Pass the name of the lockfile to another program to allow it (and
+ *   nobody else) to inspect the contents you wrote, while still
+ *   holding the lock yourself.
+ *
+ * * `reopen_lock_file()` to reopen the lockfile. Make further updates
+ *   to the contents.
+ *
+ * * `commit_lock_file()` to make the final version permanent.
+ */
+extern int reopen_lock_file(struct lock_file *lk);
+
+/*
+ * Commit the change represented by `lk`: close the file descriptor
+ * and/or file pointer if they are still open and rename the lockfile
+ * to its final destination. Return 0 upon success. On failure, roll
+ * back the lock file and return -1, with `errno` set to the value
+ * from the failing call to `close(2)` or `rename(2)`. It is a bug to
+ * call `commit_lock_file()` for a `lock_file` object that is not
+ * currently locked.
+ */
+extern int commit_lock_file(struct lock_file *lk);
+
+/*
+ * Like `commit_lock_file()`, but rename the lockfile to the provided
+ * `path`. `path` must be on the same filesystem as the lock file.
+ */
+extern int commit_lock_file_to(struct lock_file *lk, const char *path);
+
+/*
+ * Roll back `lk`: close the file descriptor and/or file pointer and
+ * remove the lockfile. It is a NOOP to call `rollback_lock_file()`
+ * for a `lock_file` object that has already been committed or rolled
+ * back.
+ */
+extern void rollback_lock_file(struct lock_file *lk);
 
 #endif /* LOCKFILE_H */