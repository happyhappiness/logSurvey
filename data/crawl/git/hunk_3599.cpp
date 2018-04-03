 		data = patch_delta(base, base_size,
 				   delta_data, delta_size,
 				   &size);
+
+		/*
+		 * We could not apply the delta; warn the user, but keep going.
+		 * Our failure will be noticed either in the next iteration of
+		 * the loop, or if this is the final delta, in the caller when
+		 * we return NULL. Those code paths will take care of making
+		 * a more explicit warning and retrying with another copy of
+		 * the object.
+		 */
 		if (!data)
-			die("failed to apply delta");
+			error("failed to apply delta");
 
 		free(delta_data);
 	}
