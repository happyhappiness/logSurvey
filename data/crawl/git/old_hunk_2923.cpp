#define LOCK_SUFFIX ".lock"
#define LOCK_SUFFIX_LEN 5

#define LOCK_DIE_ON_ERROR 1
#define LOCK_NO_DEREF 2

extern void unable_to_lock_message(const char *path, int err,
				   struct strbuf *buf);
extern NORETURN void unable_to_lock_die(const char *path, int err);
extern int hold_lock_file_for_update_timeout(
		struct lock_file *lk, const char *path,
		int flags, long timeout_ms);

static inline int hold_lock_file_for_update(
		struct lock_file *lk, const char *path,
		int flags)
{
	return hold_lock_file_for_update_timeout(lk, path, flags, 0);
}

extern int hold_lock_file_for_append(struct lock_file *lk, const char *path,
				     int flags);

extern FILE *fdopen_lock_file(struct lock_file *, const char *mode);
extern char *get_locked_file_path(struct lock_file *);
extern int commit_lock_file_to(struct lock_file *, const char *path);
extern int commit_lock_file(struct lock_file *);
extern int reopen_lock_file(struct lock_file *);
extern int close_lock_file(struct lock_file *);
extern void rollback_lock_file(struct lock_file *);

#endif /* LOCKFILE_H */