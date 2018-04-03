	fm->toggle++;
	debug(8, 0) ("You should increment MAX_SWAP_FILE\n");
    } else if (fm->n_files_in_map > (fm->max_n_files - 100)) {
	debug(8, 0) ("You've run out of swap file numbers. Freeing 1MB\n");
	storeGetSwapSpace(1000000);
    }
    return (file_number);
}