                    }
                }
#ifdef WINDOWS32
              printf (_("# %s (key %s, mtime %ull): "),
                      dir->name, dir->contents->path_key,
                      (unsigned long long)dir->contents->mtime);
#else  /* WINDOWS32 */
#ifdef VMS_INO_T
              printf (_("# %s (device %d, inode [%d,%d,%d]): "),
