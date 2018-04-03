                    }
                }
#ifdef WINDOWS32
              printf (_("# %s (key %s, mtime %I64u): "),
                      dir->name, dir->contents->path_key,
                      (unsigned long long)dir->contents->mtime);
#else  /* WINDOWS32 */
