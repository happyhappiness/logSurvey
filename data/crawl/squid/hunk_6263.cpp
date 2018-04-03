 	storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
 	    SD->map->n_files_in_map, SD->map->max_n_files,
 	    percent(SD->map->n_files_in_map, SD->map->max_n_files));
+#if HAVE_SYS_STATFS_H
+#define fsbtoblk(num, fsbs, bs) \
+        (((fsbs) != 0 && (fsbs) < (bs)) ? \
+                (num) / ((bs) / (fsbs)) : (num) * ((fsbs) / (bs)))
+	if (!statfs(SD->path, &sfs, sizeof(sfs), 0)) {
+	    storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d (%d%%)\n",
+		fsbtoblk((sfs.f_blocks - sfs.f_bfree), sfs.f_bsize, 1024),
+		fsbtoblk(sfs.f_blocks, sfs.f_bsize, 1024),
+		percent(sfs.f_blocks - sfs.f_bfree, sfs.f_blocks));
+	    storeAppendPrintf(sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
+		sfs.f_files - sfs.f_ffree, sfs.f_files,
+		percent(sfs.f_files - sfs.f_ffree, sfs.f_files));
+	}
+#endif
     }
 }
 