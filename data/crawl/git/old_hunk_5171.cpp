		die("STOP_AT_NON_OPTION and KEEP_UNKNOWN don't go together");
}

static int usage_with_options_internal(const char * const *,
				       const struct option *, int, int);

int parse_options_step(struct parse_opt_ctx_t *ctx,
