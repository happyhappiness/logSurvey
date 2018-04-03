                    }
                }
#ifdef WINDOWS32
              printf (_("# %s (key %s, mtime %d): "),
                      dir->name, dir->contents->path_key, dir->contents->mtime);
#else  /* WINDOWS32 */
#ifdef VMS_INO_T
              printf (_("# %s (device %d, inode [%d,%d,%d]): "),
