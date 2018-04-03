			result |= delete_ref(ref->name, NULL, 0);
		if (verbosity >= 0) {
			fprintf(stderr, " x %-*s %-*s -> %s\n",
				TRANSPORT_SUMMARY_WIDTH, "[deleted]",
				REFCOL_WIDTH, "(none)", prettify_refname(ref->name));
			warn_dangling_symref(stderr, dangling_msg, ref->name);
		}
