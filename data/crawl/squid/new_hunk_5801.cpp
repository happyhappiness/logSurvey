	SD->map->n_files_in_map, SD->map->max_n_files,
	percent(SD->map->n_files_in_map, SD->map->max_n_files));
#endif
    storeAppendPrintf(sentry, "Pending operations: %d out of %d\n", cs->aq.aq_numpending, MAX_ASYNCOP);
    storeAppendPrintf(sentry, "Flags:");
    if (SD->flags.selected)
	storeAppendPrintf(sentry, " SELECTED");