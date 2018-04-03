	return error("unknown option `%s'", arg);
}

static NORETURN void usage_with_options_internal(const char * const *,
                                                 const struct option *, int);

