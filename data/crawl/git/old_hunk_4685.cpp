			return 0;
		pos++;
	}
	return error("path '%s' does not have %s version",
		     ce->name,
		     (stage == 2) ? "our" : "their");
}

static int check_all_stages(struct cache_entry *ce, int pos)
