           else if (dir->contents->dirfiles.ht_vec == 0)
             {
 #ifdef WINDOWS32
-              printf (_("# %s (key %s, mtime %ull): could not be opened.\n"),
+              printf (_("# %s (key %s, mtime %I64u): could not be opened.\n"),
                       dir->name, dir->contents->path_key,
                       (unsigned long long)dir->contents->mtime);
 #else  /* WINDOWS32 */
