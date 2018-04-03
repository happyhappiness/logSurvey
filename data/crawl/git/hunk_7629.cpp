 
 	for (i = 0; i < targets; i++) {
 		if (interpret_target(walker, target[i], &sha1[20 * i])) {
-			error("Could not interpret %s as something to pull", target[i]);
+			error("Could not interpret response from server '%s' as something to pull", target[i]);
 			goto unlock_and_fail;
 		}
 		if (process(walker, lookup_unknown_object(&sha1[20 * i])))