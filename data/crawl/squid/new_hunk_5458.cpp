	fatalf("Unknown cache_dir type '%s'\n", type_str);
    }
    allocate_new_swapdir(swap);
    swap->swapDirs[swap->n_configured] = SwapDir::Factory(storefs_list[fs]);
    sd = swap->swapDirs[swap->n_configured];
    /* parse the FS parameters and options */
    sd->parse(swap->n_configured, path_str);
    ++swap->n_configured;
    /* Update the max object size */
    update_maxobjsize();
}
