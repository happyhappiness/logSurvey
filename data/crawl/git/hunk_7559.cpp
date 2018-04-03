 		else if (ce_compare_gitlink(ce))
 			changed |= DATA_CHANGED;
 		return changed;
-	case 0: /* Special case: unmerged file in index */
-		return MODE_CHANGED | DATA_CHANGED | TYPE_CHANGED;
 	default:
-		die("internal error: ce_mode is %o", ntohl(ce->ce_mode));
+		die("internal error: ce_mode is %o", ce->ce_mode);
 	}
-	if (ce->ce_mtime.sec != htonl(st->st_mtime))
-		changed |= MTIME_CHANGED;
-	if (ce->ce_ctime.sec != htonl(st->st_ctime))
-		changed |= CTIME_CHANGED;
-
-#ifdef USE_NSEC
-	/*
-	 * nsec seems unreliable - not all filesystems support it, so
-	 * as long as it is in the inode cache you get right nsec
-	 * but after it gets flushed, you get zero nsec.
-	 */
-	if (ce->ce_mtime.nsec != htonl(st->st_mtim.tv_nsec))
+	if (ce->ce_mtime != (unsigned int) st->st_mtime)
 		changed |= MTIME_CHANGED;
-	if (ce->ce_ctime.nsec != htonl(st->st_ctim.tv_nsec))
+	if (ce->ce_ctime != (unsigned int) st->st_ctime)
 		changed |= CTIME_CHANGED;
-#endif
 
-	if (ce->ce_uid != htonl(st->st_uid) ||
-	    ce->ce_gid != htonl(st->st_gid))
+	if (ce->ce_uid != (unsigned int) st->st_uid ||
+	    ce->ce_gid != (unsigned int) st->st_gid)
 		changed |= OWNER_CHANGED;
-	if (ce->ce_ino != htonl(st->st_ino))
+	if (ce->ce_ino != (unsigned int) st->st_ino)
 		changed |= INODE_CHANGED;
 
 #ifdef USE_STDEV
