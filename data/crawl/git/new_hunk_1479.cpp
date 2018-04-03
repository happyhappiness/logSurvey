		ce->ce_mode = create_ce_mode(mode);
		ce->ce_flags = create_ce_flags(stage);
		ce->ce_namelen = namelen;
		oidcpy(&ce->oid, &patch->threeway_stage[stage - 1]);
		if (add_cache_entry(ce, ADD_CACHE_OK_TO_ADD) < 0)
			die(_("unable to add cache entry for %s"), patch->new_name);
	}
