    /* is this applicable? I Hope not .. */
    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
                      SD->map->n_files_in_map, SD->map->max_n_files,
                      Math::intPercent(SD->map->n_files_in_map, SD->map->max_n_files));
#endif

    //    storeAppendPrintf(&sentry, "Pending operations: %d out of %d\n", io->aq.aq_numpending, MAX_ASYNCOP);
