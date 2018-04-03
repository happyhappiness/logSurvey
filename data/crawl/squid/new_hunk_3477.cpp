                      100.0 * cur_size / max_size);
    storeAppendPrintf(&sentry, "Filemap bits in use: %d of %d (%d%%)\n",
                      map->n_files_in_map, map->max_n_files,
                      Math::intPercent(map->n_files_in_map, map->max_n_files));
    x = storeDirGetUFSStats(path, &totl_kb, &free_kb, &totl_in, &free_in);

    if (0 == x) {
        storeAppendPrintf(&sentry, "Filesystem Space in use: %d/%d KB (%d%%)\n",
                          totl_kb - free_kb,
                          totl_kb,
                          Math::intPercent(totl_kb - free_kb, totl_kb));
        storeAppendPrintf(&sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
                          totl_in - free_in,
                          totl_in,
                          Math::intPercent(totl_in - free_in, totl_in));
    }

    storeAppendPrintf(&sentry, "Flags:");
