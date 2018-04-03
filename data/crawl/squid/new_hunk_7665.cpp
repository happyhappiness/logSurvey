    LOCAL_ARRAY(char, where, 100);

    where[0] = '\0';
    sprintf (where, "D%d/%s/%s",
	entry->swap_file_number,
	swapStatusStr[entry->swap_status],
	memStatusStr[entry->mem_status]);
    return (where);
}

