        }
    }

    /* new cache_dir */
    assert(swap->n_configured < 63);	/* 7 bits, signed */

    allocate_new_swapdir(swap);

    swap->swapDirs[swap->n_configured] = StoreFileSystem::FileSystems().items[fs]->createSwapDir();

    sd = dynamic_cast<SwapDir *>(swap->swapDirs[swap->n_configured].getRaw());

    /* parse the FS parameters and options */
    sd->parse(swap->n_configured, path_str);

    ++swap->n_configured;

    /* Update the max object size */
    update_maxobjsize();
}