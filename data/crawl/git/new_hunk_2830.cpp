	return hold_lock_file_for_update_timeout(lk, path, flags, 0);
}

/*
 * Append an appropriate error message to `buf` following the failure
 * of `hold_lock_file_for_update()` to lock `path`. `err` should be the
 * `errno` set by the failing call.
 */
extern void unable_to_lock_message(const char *path, int err,
				   struct strbuf *buf);

/*
 * Emit an appropriate error message and `die()` following the failure
 * of `hold_lock_file_for_update()` to lock `path`. `err` should be the
 * `errno` set by the failing
 * call.
 */
extern NORETURN void unable_to_lock_die(const char *path, int err);