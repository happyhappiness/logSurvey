	    return file_map_bit_set(fm, suggestion);
	}
    }
    fatal("file_map_allocate: Exceeded filemap limit");
    return 0;			/* NOTREACHED */
}

void
