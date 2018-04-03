 		return;
 
 	if (hold_lock_file_for_update(&mark_lock, export_marks_file, 0) < 0) {
-		failure |= error("Unable to write marks file %s: %s",
-			export_marks_file, strerror(errno));
+		failure |= error_errno("Unable to write marks file %s",
+				       export_marks_file);
 		return;
 	}
 
