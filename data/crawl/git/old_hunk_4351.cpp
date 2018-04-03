			break;
		if (!val)
			die("invalid dump: unsets svn:log");
		strbuf_reset(&rev_ctx.log);
		strbuf_add(&rev_ctx.log, val, len);
		break;
	case sizeof("svn:author"):
		if (constcmp(key, "svn:author"))
			break;
		strbuf_reset(&rev_ctx.author);
		if (val)
			strbuf_add(&rev_ctx.author, val, len);
		break;
	case sizeof("svn:date"):
		if (constcmp(key, "svn:date"))
			break;
		if (!val)
			die("invalid dump: unsets svn:date");
		if (parse_date_basic(val, &rev_ctx.timestamp, NULL))
			warning("invalid timestamp: %s", val);
		break;
	case sizeof("svn:executable"):
	case sizeof("svn:special"):
