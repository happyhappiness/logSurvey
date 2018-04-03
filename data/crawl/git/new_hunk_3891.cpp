	default: /* PARSE_OPT_UNKNOWN */
		if (ctx.argv[0][1] == '-') {
			error("unknown option `%s'", ctx.argv[0] + 2);
		} else if (isascii(*ctx.opt)) {
			error("unknown switch `%c'", *ctx.opt);
		} else {
			error("unknown non-ascii option in string: `%s'",
			      ctx.argv[0]);
		}
		usage_with_options(usagestr, options);
	}