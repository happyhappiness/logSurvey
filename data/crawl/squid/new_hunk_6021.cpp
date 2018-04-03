     */

    for (i = 0; i < swap->n_configured; i++) {
	if (0 == strcasecmp(path_str, swap->swapDirs[i].path)) {
	    /* This is a little weird, you'll appreciate it later */
	    fs = find_fstype(type_str);
	    if (fs < 0) {
		fatalf("Unknown cache_dir type '%s'\n", type_str);
	    }
	    sd = swap->swapDirs + i;
	    storefs_list[fs].reconfigurefunc(sd, i, path_str);
	    sd->max_objsize = maxobjsize;
	    update_maxobjsize();
	    return;
	}
    }

    fs = find_fstype(type_str);
    if (fs < 0) {
	/* If we get here, we didn't find a matching cache_dir type */
	fatalf("Unknown cache_dir type '%s'\n", type_str);
    }
    allocate_new_swapdir(swap);
    sd = swap->swapDirs + swap->n_configured;
    storefs_list[fs].parsefunc(sd, swap->n_configured, path_str);
