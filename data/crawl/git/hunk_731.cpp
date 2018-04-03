 	}
 
 	if (log && rename(sb_oldref.buf, tmp_renamed_log.buf)) {
-		ret = error("unable to move logfile logs/%s to "TMP_RENAMED_LOG": %s",
+		ret = error("unable to move logfile logs/%s to logs/"TMP_RENAMED_LOG": %s",
 			    oldrefname, strerror(errno));
 		goto out;
 	}
