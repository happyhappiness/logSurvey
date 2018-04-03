	alias_all_urls();
}

struct refspec *parse_ref_spec(int nr_refspec, const char **refspec)
{
	int i;
	int st;
	struct refspec *rs = xcalloc(sizeof(*rs), nr_refspec);
	for (i = 0; i < nr_refspec; i++) {
		const char *sp, *ep, *gp;
		sp = refspec[i];
		if (*sp == '+') {
			rs[i].force = 1;
			sp++;
		}
		gp = strstr(sp, "/*");
		ep = strchr(sp, ':');
		if (gp && ep && gp > ep)
			gp = NULL;
		if (ep) {
			if (ep[1]) {
				const char *glob = strstr(ep + 1, "/*");
				if (glob && glob[2])
					glob = NULL;
				if (!glob)
					gp = NULL;
				if (gp)
					rs[i].dst = xstrndup(ep + 1,
							     glob - ep - 1);
				else
					rs[i].dst = xstrdup(ep + 1);
			}
		} else {
			ep = sp + strlen(sp);
		}
		if (gp && gp + 2 != ep)
			gp = NULL;
		if (gp) {
			rs[i].pattern = 1;
			ep = gp;
		}
		rs[i].src = xstrndup(sp, ep - sp);

		if (*rs[i].src) {
			st = check_ref_format(rs[i].src);
			if (st && st != CHECK_REF_FORMAT_ONELEVEL)
				die("Invalid refspec '%s'", refspec[i]);
		}
		if (rs[i].dst && *rs[i].dst) {
			st = check_ref_format(rs[i].dst);
			if (st && st != CHECK_REF_FORMAT_ONELEVEL)
				die("Invalid refspec '%s'", refspec[i]);
		}
	}
	return rs;
}

static int valid_remote_nick(const char *name)
