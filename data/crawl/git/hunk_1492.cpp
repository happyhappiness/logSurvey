 		}
 	}
 
-	hold_lock_file_for_update(&lock, filename, LOCK_DIE_ON_ERROR);
+	hold_lock_file_for_update(&lock, state->fake_ancestor, LOCK_DIE_ON_ERROR);
 	res = write_locked_index(&result, &lock, COMMIT_LOCK);
 	discard_index(&result);
 
 	if (res)
-		return error("Could not write temporary index to %s", filename);
+		return error("Could not write temporary index to %s",
+			     state->fake_ancestor);
 
 	return 0;
 }
