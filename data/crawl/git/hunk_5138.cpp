 		error("unable to restore logfile %s from %s: %s",
 			oldref, newref, strerror(errno));
 	if (!logmoved && log &&
-	    rename(git_path("tmp-renamed-log"), git_path("logs/%s", oldref)))
-		error("unable to restore logfile %s from tmp-renamed-log: %s",
+	    rename(git_path(TMP_RENAMED_LOG), git_path("logs/%s", oldref)))
+		error("unable to restore logfile %s from "TMP_RENAMED_LOG": %s",
 			oldref, strerror(errno));
 
 	return 1;