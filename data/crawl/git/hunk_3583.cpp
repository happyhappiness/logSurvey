 	default:
 		die("internal error: ce_mode is %o", ce->ce_mode);
 	}
-	if (ce->ce_mtime.sec != (unsigned int)st->st_mtime)
-		changed |= MTIME_CHANGED;
-	if (trust_ctime && check_stat &&
-	    ce->ce_ctime.sec != (unsigned int)st->st_ctime)
-		changed |= CTIME_CHANGED;
 
-#ifdef USE_NSEC
-	if (check_stat && ce->ce_mtime.nsec != ST_MTIME_NSEC(*st))
-		changed |= MTIME_CHANGED;
-	if (trust_ctime && check_stat &&
-	    ce->ce_ctime.nsec != ST_CTIME_NSEC(*st))
-		changed |= CTIME_CHANGED;
-#endif
-
-	if (check_stat) {
-		if (ce->ce_uid != (unsigned int) st->st_uid ||
-			ce->ce_gid != (unsigned int) st->st_gid)
-			changed |= OWNER_CHANGED;
-		if (ce->ce_ino != (unsigned int) st->st_ino)
-			changed |= INODE_CHANGED;
-	}
-
-#ifdef USE_STDEV
-	/*
-	 * st_dev breaks on network filesystems where different
-	 * clients will have different views of what "device"
-	 * the filesystem is on
-	 */
-	if (check_stat && ce->ce_dev != (unsigned int) st->st_dev)
-			changed |= INODE_CHANGED;
-#endif
-
-	if (ce->ce_size != (unsigned int) st->st_size)
-		changed |= DATA_CHANGED;
+	changed |= match_stat_data(&ce->ce_stat_data, st);
 
 	/* Racily smudged entry? */
-	if (!ce->ce_size) {
+	if (!ce->ce_stat_data.sd_size) {
 		if (!is_empty_blob_sha1(ce->sha1))
 			changed |= DATA_CHANGED;
 	}
