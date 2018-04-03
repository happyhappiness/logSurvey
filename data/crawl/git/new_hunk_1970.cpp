	const char *filename;
	int linenr;
	const char *origin_type;
	enum config_scope scope;
};

extern NORETURN void git_die_config(const char *key, const char *err, ...) __attribute__((format(printf, 2, 3)));
