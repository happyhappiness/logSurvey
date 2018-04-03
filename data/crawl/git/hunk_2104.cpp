 		}
 	}
 	if (commit_ref(lock)) {
-		error("Couldn't set %s", lock->ref_name);
+		strbuf_addf(err, "Couldn't set %s", lock->ref_name);
 		unlock_ref(lock);
 		return -1;
 	}