			return checkout_entry(active_cache[pos], state, NULL);
		pos++;
	}
	return error("path '%s' does not have %s version",
		     ce->name,
		     (stage == 2) ? "our" : "their");
}

static int checkout_merged(int pos, struct checkout *state)