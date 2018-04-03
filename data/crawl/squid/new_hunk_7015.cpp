	fm->toggle++;
	debug(8, 0) ("You should increment MAX_SWAP_FILE\n");
    } else if (fm->n_files_in_map > (fm->max_n_files - 100)) {
	fatal("You've run out of swap file numbers.");
    }
    return (file_number);
}