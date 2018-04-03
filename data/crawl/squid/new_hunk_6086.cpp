	    return file_map_bit_set(fm, suggestion);
	}
    }
    debug(8, 3) ("growing from file_map_allocate\n");
    file_map_grow(fm);
    return file_map_allocate(fm, fm->max_n_files >> 1);
}

void
