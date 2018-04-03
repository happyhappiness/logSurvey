 		error("unable to restore logfile %s from "TMP_RENAMED_LOG": %s",
 			oldrefname, strerror(errno));
 
-	return 1;
+	ret = 1;
+ out:
+	return ret;
 }
 
 static int close_ref(struct ref_lock *lock)