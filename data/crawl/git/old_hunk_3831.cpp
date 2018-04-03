				      &res->u.pat.patternlen,
				      &res->u.pat.flags,
				      &res->u.pat.nowildcardlen);
		if (res->u.pat.flags & EXC_FLAG_NEGATIVE)
			die(_("Negative patterns are forbidden in git attributes\n"
			      "Use '\\!' for literal leading exclamation."));
	}
	res->is_macro = is_macro;
	res->num_attr = num_attr;
