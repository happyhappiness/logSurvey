struct key_value_info {
	const char *filename;
	int linenr;
};

extern NORETURN void git_die_config(const char *key, const char *err, ...) __attribute__((format(printf, 2, 3)));
