/*
 * File write-locks as used by Git.
 *
 * The lockfile API serves two purposes:
 *
 * * Mutual exclusion and atomic file updates. When we want to change
 *   a file, we create a lockfile `<filename>.lock`, write the new
 *   file contents into it, and then rename the lockfile to its final
 *   destination `<filename>`. We create the `<filename>.lock` file
 *   with `O_CREAT|O_EXCL` so that we can notice and fail if somebody
 *   else has already locked the file, then atomically rename the
 *   lockfile to its final destination to commit the changes and
 *   unlock the file.
 *
 * * Automatic cruft removal. If the program exits after we lock a
 *   file but before the changes have been committed, we want to make
 *   sure that we remove the lockfile. This is done by remembering the
 *   lockfiles we have created in a linked list and setting up an
 *   `atexit(3)` handler and a signal handler that clean up the
 *   lockfiles. This mechanism ensures that outstanding lockfiles are
 *   cleaned up if the program exits (including when `die()` is
 *   called) or if the program is terminated by a signal.
 *
 * Please note that lockfiles only block other writers. Readers do not
 * block, but they are guaranteed to see either the old contents of
 * the file or the new contents of the file (assuming that the
 * filesystem implements `rename(2)` atomically).
 *
 *
 * Calling sequence
 * ----------------
 *
 * The caller:
 *
 * * Allocates a `struct lock_file` either as a static variable or on
 *   the heap, initialized to zeros. Once you use the structure to
 *   call the `hold_lock_file_for_*()` family of functions, it belongs
 *   to the lockfile subsystem and its storage must remain valid
 *   throughout the life of the program (i.e. you cannot use an
 *   on-stack variable to hold this structure).
 *
 * * Attempts to create a lockfile by calling
 *   `hold_lock_file_for_update()` or `hold_lock_file_for_append()`.
 *
 * * Writes new content for the destination file by either:
 *
 *   * writing to the file descriptor returned by the
 *     `hold_lock_file_for_*()` functions (also available via
 *     `lock->fd`).
 *
 *   * calling `fdopen_lock_file()` to get a `FILE` pointer for the
 *     open file and writing to the file using stdio.
 *
 * When finished writing, the caller can:
 *
 * * Close the file descriptor and rename the lockfile to its final
 *   destination by calling `commit_lock_file()` or
 *   `commit_lock_file_to()`.
 *
 * * Close the file descriptor and remove the lockfile by calling
 *   `rollback_lock_file()`.
 *
 * * Close the file descriptor without removing or renaming the
 *   lockfile by calling `close_lock_file()`, and later call
 *   `commit_lock_file()`, `commit_lock_file_to()`,
 *   `rollback_lock_file()`, or `reopen_lock_file()`.
 *
 * Even after the lockfile is committed or rolled back, the
 * `lock_file` object must not be freed or altered by the caller.
 * However, it may be reused; just pass it to another call of
 * `hold_lock_file_for_update()` or `hold_lock_file_for_append()`.
 *
 * If the program exits before `commit_lock_file()`,
 * `commit_lock_file_to()`, or `rollback_lock_file()` is called, an
 * `atexit(3)` handler will close and remove the lockfile, thereby
 * rolling back any uncommitted changes.
 *
 * If you need to close the file descriptor you obtained from a
 * `hold_lock_file_for_*()` function yourself, do so by calling
 * `close_lock_file()`. You should never call `close(2)` or
 * `fclose(3)` yourself, otherwise the `struct lock_file` structure
 * would still think that the file descriptor needs to be closed, and
 * a commit or rollback would result in duplicate calls to `close(2)`.
 * Worse yet, if you close and then later open another file descriptor
 * for a completely different purpose, then a commit or rollback might
 * close that unrelated file descriptor.
 *
 * Error handling
 * --------------
 *
 * The `hold_lock_file_for_*()` functions return a file descriptor on
 * success or -1 on failure (unless `LOCK_DIE_ON_ERROR` is used; see
 * "flags" below). On errors, `errno` describes the reason for
 * failure. Errors can be reported by passing `errno` to
 * `unable_to_lock_message()` or `unable_to_lock_die()`.
 *
 * Similarly, `commit_lock_file`, `commit_lock_file_to`, and
 * `close_lock_file` return 0 on success. On failure they set `errno`
 * appropriately, do their best to roll back the lockfile, and return
 * -1.
 */

struct lock_file {
