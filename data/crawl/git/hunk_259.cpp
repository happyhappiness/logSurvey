 		return 0;
 	}
 
-	if (!fdopen_lock_file(lock->lk, "w"))
+	if (!fdopen_lock_file(&lock->lk, "w"))
 		return error("unable to fdopen %s: %s",
-			     lock->lk->tempfile->filename.buf, strerror(errno));
+			     lock->lk.tempfile->filename.buf, strerror(errno));
 
 	update_symref_reflog(refs, lock, refname, target, logmsg);
 
 	/* no error check; commit_ref will check ferror */
-	fprintf(lock->lk->tempfile->fp, "ref: %s\n", target);
+	fprintf(lock->lk.tempfile->fp, "ref: %s\n", target);
 	if (commit_ref(lock) < 0)
 		return error("unable to write symref for %s: %s", refname,
 			     strerror(errno));
