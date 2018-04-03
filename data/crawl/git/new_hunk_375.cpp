/* Dumb servers support */
extern int update_server_info(int);

extern const char *get_log_output_encoding(void);
extern const char *get_commit_output_encoding(void);

/*
 * This is a hack for test programs like test-dump-untracked-cache to
 * ensure that they do not modify the untracked cache when reading it.
 * Do not use it otherwise!
 */
extern int ignore_untracked_cache_config;

extern int committer_ident_sufficiently_given(void);
extern int author_ident_sufficiently_given(void);

