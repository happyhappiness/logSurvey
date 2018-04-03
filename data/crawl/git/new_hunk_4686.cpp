			return checkout_entry(active_cache[pos], state, NULL);
		pos++;
	}
	if (stage == 2)
		return error(_("path '%s' does not have our version"), ce->name);
	else
		return error(_("path '%s' does not have their version"), ce->name);
}

static int checkout_merged(int pos, struct checkout *state)