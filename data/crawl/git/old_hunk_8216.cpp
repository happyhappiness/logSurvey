			continue;
		}
		if (ce_match_stat(ce, &st, 0))
			errs = error("'%s' has local modifications "
				     "(hint: try -f)", ce->name);
		if (no_head
		     || get_tree_entry(head, name, sha1, &mode)
		     || ce->ce_mode != create_ce_mode(mode)
		     || hashcmp(ce->sha1, sha1))
			errs = error("'%s' has changes staged in the index "
				     "(hint: try -f)", name);
	}
	return errs;
}
