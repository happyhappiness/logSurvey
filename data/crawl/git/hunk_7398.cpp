 		error("%s: not a commit", refname);
 	default_refs++;
 	obj->used = 1;
-	mark_reachable(obj, REACHABLE);
+	mark_object_reachable(obj);
 
 	return 0;
 }
