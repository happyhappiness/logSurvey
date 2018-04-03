 		if (write_in_full(revlist.in, sha1_to_hex(ref->old_sha1), 40) < 0 ||
 		    write_str_in_full(revlist.in, "\n") < 0) {
 			if (errno != EPIPE && errno != EINVAL)
-				error("failed write to rev-list: %s", strerror(errno));
+				error(_("failed write to rev-list: %s"), strerror(errno));
 			err = -1;
 			break;
 		}
 	}
 
 	if (close(revlist.in)) {
-		error("failed to close rev-list's stdin: %s", strerror(errno));
+		error(_("failed to close rev-list's stdin: %s"), strerror(errno));
 		err = -1;
 	}
 
