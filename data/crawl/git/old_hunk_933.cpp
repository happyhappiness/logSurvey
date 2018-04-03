/*
 * If a lock is already taken for the file, `die()` with an error
 * message. If this flag is not specified, trying to lock a file that
 * is already locked returns -1 to the caller.
 */
#define LOCK_DIE_ON_ERROR 1

/*
 * Usually symbolic links in the destination path are resolved. This
 * means that (1) the lockfile is created by adding ".lock" to the
