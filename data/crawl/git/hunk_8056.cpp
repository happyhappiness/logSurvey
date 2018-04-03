 		}
 	}
 
-	if (!get_recover)
+	if (!walker->get_recover)
 		for_each_ref(mark_complete, NULL);
 
 	for (i = 0; i < targets; i++) {
-		if (interpret_target(target[i], &sha1[20 * i])) {
+		if (interpret_target(walker, target[i], &sha1[20 * i])) {
 			error("Could not interpret %s as something to pull", target[i]);
 			goto unlock_and_fail;
 		}
-		if (process(lookup_unknown_object(&sha1[20 * i])))
+		if (process(walker, lookup_unknown_object(&sha1[20 * i])))
 			goto unlock_and_fail;
 	}
 
-	if (loop())
+	if (loop(walker))
 		goto unlock_and_fail;
 
 	if (write_ref_log_details) {
