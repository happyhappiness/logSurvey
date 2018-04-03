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
