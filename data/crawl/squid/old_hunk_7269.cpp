	debug(35, 1, "fqdncache_release: Someone called on a DISPATCHED entry\n");
	return;
    }
    if (hash_remove_link(fqdn_table, table_entry)) {
	debug(35, 0, "fqdncache_release: hash_remove_link() failed for '%s'\n",
	    f->name);
