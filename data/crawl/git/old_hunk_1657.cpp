		o->call_depth--;

		if (!merged_common_ancestors)
			die(_("merge returned no commit"));
	}

	discard_cache();