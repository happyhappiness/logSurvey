 	return mask;
 }
 
-static int unpack_failed(struct unpack_trees_options *o, const char *message)
-{
-	discard_index(&o->result);
-	if (!o->gently) {
-		if (message)
-			return error("%s", message);
-		return -1;
-	}
-	return -1;
-}
-
 /*
  * N-way merge "len" trees.  Returns 0 on success, -1 on failure to manipulate the
  * resulting index, -2 on failure to reflect the changes to the work tree.