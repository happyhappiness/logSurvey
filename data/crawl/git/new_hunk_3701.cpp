		if (!strcmp(arg, "--dry-run") || !strcmp(arg, "-n"))
			cb.dry_run = 1;
		else if (!prefixcmp(arg, "--expire=")) {
			if (parse_expiry_date(arg + 9, &cb.expire_total))
				die(_("'%s' is not a valid timestamp"), arg);
			explicit_expiry |= EXPIRE_TOTAL;
		}
		else if (!prefixcmp(arg, "--expire-unreachable=")) {
			if (parse_expiry_date(arg + 21, &cb.expire_unreachable))
				die(_("'%s' is not a valid timestamp"), arg);
			explicit_expiry |= EXPIRE_UNREACH;
		}
		else if (!strcmp(arg, "--stale-fix"))
