	    "\tConsider decreasing store_avg_object_size in squid.conf\n",
            percent(fm->n_files_in_map, fm->max_n_files));
    } else if (fm->n_files_in_map > (fm->max_n_files - 100)) {
	fatal_dump("You've run out of swap file numbers.");
    }
    return (file_number);
}