    }
    disk_stats.n_pages_in_use++;
    if (page == NULL) {
	debug(19, 0, "Null page pointer?");
	fatal_dump(NULL);
    }
    return (page);
