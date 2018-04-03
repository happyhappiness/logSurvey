
	for (; opts->type != OPTION_END; opts++) {
		if ((opts->flags & PARSE_OPT_LASTARG_DEFAULT) &&
		    (opts->flags & PARSE_OPT_OPTARG)) {
			if (opts->long_name) {
				error("`--%s` uses incompatible flags "
				      "LASTARG_DEFAULT and OPTARG", opts->long_name);
			} else {
				error("`-%c` uses incompatible flags "
				      "LASTARG_DEFAULT and OPTARG", opts->short_name);
			}
			err |= 1;
		}
	}

	if (err)
		exit(129);
}

void parse_options_start(struct parse_opt_ctx_t *ctx,