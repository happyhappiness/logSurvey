
    where[0] = '\0';
    if (entry->swap_file_number >= 0)
	sprintf(where, "D%d", entry->swap_file_number);
    if (entry->swap_status == SWAPPING_OUT)
	strncat(where, "/SWAP-OUT", sizeof(where));
    if (entry->swap_status == SWAP_OK)
