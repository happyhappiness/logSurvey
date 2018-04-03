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
	    update_maxobjsize();
	    return;
	}
