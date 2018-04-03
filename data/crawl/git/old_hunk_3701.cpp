		if (!strcmp(arg, "--dry-run") || !strcmp(arg, "-n"))
			cb.dry_run = 1;
		else if (!prefixcmp(arg, "--expire=")) {
			cb.expire_total = approxidate(arg + 9);
			explicit_expiry |= EXPIRE_TOTAL;
		}
		else if (!prefixcmp(arg, "--expire-unreachable=")) {
			cb.expire_unreachable = approxidate(arg + 21);
			explicit_expiry |= EXPIRE_UNREACH;
		}
		else if (!strcmp(arg, "--stale-fix"))
