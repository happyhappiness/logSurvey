		o->call_depth--;

		if (!merged_common_ancestors)
			return err(o, _("merge returned no commit"));
	}

	discard_cache();
