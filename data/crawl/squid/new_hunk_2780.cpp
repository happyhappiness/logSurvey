        fatalf("Rock cache_dir failed to open db file: %s", filePath);
	}

    cur_size = (HeaderSize + max_objsize * map->entryCount()) >> 10;

    // TODO: lower debugging level
    debugs(47,1, "Rock cache_dir[" << index << "] limits: " << 
        std::setw(12) << maximumSize() << " disk bytes and " <<
        std::setw(7) << map->entryLimit() << " entries");
}

void
