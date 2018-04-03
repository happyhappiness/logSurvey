	r > 0 ? r : 0, (double) data->objcount / (r > 0 ? r : 1));
    debug(20, 1, "  store_swap_size = %dk\n", store_swap_size);
    store_rebuilding = STORE_NOT_REBUILDING;
    safe_free(data->line_in);
    safe_free(data);
    if (store_validating) {
	debug(20, 1, "Beginning Validation Procedure\n");
	eventAdd("storeCleanup", storeCleanup, NULL, 0);
