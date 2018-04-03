	SD->map->n_files_in_map, SD->map->max_n_files,
	percent(SD->map->n_files_in_map, SD->map->max_n_files));
#endif
    storeAppendPrintf(sentry, "Flags:");
    if (SD->flags.selected)
	storeAppendPrintf(sentry, " SELECTED");