	git_config(handle_config);
}

struct refspec *parse_ref_spec(int nr_refspec, const char **refspec)
{
	int i;
	struct refspec *rs = xcalloc(sizeof(*rs), nr_refspec);
	for (i = 0; i < nr_refspec; i++) {
		const char *sp, *ep, *gp;
		sp = refspec[i];
		if (*sp == '+') {
			rs[i].force = 1;
			sp++;
		}
		gp = strchr(sp, '*');
		ep = strchr(sp, ':');
		if (gp && ep && gp > ep)
			gp = NULL;
		if (ep) {
			if (ep[1]) {
				const char *glob = strchr(ep + 1, '*');
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
		if (gp) {
			rs[i].pattern = 1;
			ep = gp;
		}
		rs[i].src = xstrndup(sp, ep - sp);
	}
	return rs;
}

static int valid_remote_nick(const char *name)
