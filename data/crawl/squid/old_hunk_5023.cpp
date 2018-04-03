        }
    }

    assert(swap->n_configured < 63);	/* 7 bits, signed */

    fs = find_fstype(type_str);

    if (fs < 0) {
        /* If we get here, we didn't find a matching cache_dir type */
        fatalf("Unknown cache_dir type '%s'\n", type_str);
    }

    allocate_new_swapdir(swap);
    swap->swapDirs[swap->n_configured] = StoreFileSystem::FileSystems().items[fs]->createSwapDir();
    sd = dynamic_cast<SwapDir *>(swap->swapDirs[swap->n_configured].getRaw());
    /* parse the FS parameters and options */
    sd->parse(swap->n_configured, path_str);
    ++swap->n_configured;
    /* Update the max object size */
    update_maxobjsize();
}