	debug_trap("ipcacheChangeKey: hash_remove_link() failed\n");
	return;
    }
    sprintf(new_key, "%d/%-128.128s", ++index, i->name);
    debug(14, 1, "ipcacheChangeKey: from '%s' to '%s'\n", i->name, new_key);
    safe_free(i->name);
    i->name = xstrdup(new_key);
    ipcache_add_to_hash(i);
}
