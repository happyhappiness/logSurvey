    if ((path_str = strtok(NULL, w_space)) == NULL)
        self_destruct();


    fs = find_fstype(type_str);

    if (fs < 0)
        self_destruct();

    /* reconfigure existing dir */

    for (i = 0; i < swap->n_configured; i++) {
        assert (swap->swapDirs[i].getRaw());

        if ((strcasecmp(path_str, dynamic_cast<SwapDir *>(swap->swapDirs[i].getRaw())->path)
            ) == 0) {
            /* this is specific to on-fs Stores. The right
             * way to handle this is probably to have a mapping 
             * from paths to stores, and have on-fs stores
             * register with that, and lookip in that in their
             * own setup logic. RBC 20041225. TODO.
             */

            sd = dynamic_cast<SwapDir *>(swap->swapDirs[i].getRaw());

            if (sd->type() != StoreFileSystem::FileSystems().items[fs]->type()) {
                debug(3, 0) ("ERROR: Can't change type of existing cache_dir %s %s to %s. Restart required\n", sd->type(), sd->path, type_str);
                return;
            }

            sd->reconfigure (i, path_str);

            update_maxobjsize();
