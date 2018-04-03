 	discard_index(&result);
 
 	 if (res)
-		 return error("Could not write temporary index to %s",
+		 return error(_("could not write temporary index to %s"),
 			      state->fake_ancestor);
 
 	 return 0;