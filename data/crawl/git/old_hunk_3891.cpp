	default: /* PARSE_OPT_UNKNOWN */
		if (ctx.argv[0][1] == '-') {
			error("unknown option `%s'", ctx.argv[0] + 2);
		} else {
			error("unknown switch `%c'", *ctx.opt);
		}
		usage_with_options(usagestr, options);
	}