         (((fsbs) != 0 && (fsbs) < (bs)) ? \
                 (num) / ((bs) / (fsbs)) : (num) * ((fsbs) / (bs)))
 	if (!statvfs(SD->path, &sfs)) {
-	    storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d (%d%%)\n",
-		fsbtoblk((sfs.f_blocks - sfs.f_bfree), sfs.f_bsize, 1024),
-		fsbtoblk(sfs.f_blocks, sfs.f_bsize, 1024),
+	    storeAppendPrintf(sentry, "Filesystem Space in use: %d/%d KB (%d%%)\n",
+		fsbtoblk((sfs.f_blocks - sfs.f_bfree), sfs.f_frsize, 1024),
+		fsbtoblk(sfs.f_blocks, sfs.f_frsize, 1024),
 		percent(sfs.f_blocks - sfs.f_bfree, sfs.f_blocks));
 	    storeAppendPrintf(sentry, "Filesystem Inodes in use: %d/%d (%d%%)\n",
 		sfs.f_files - sfs.f_ffree, sfs.f_files,