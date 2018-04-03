 		errors_found |= ERROR_REACHABLE;
 		return;
 	}
-
-	/*
-	 * Check that everything that we try to reference is also good.
-	 */
-	refs = lookup_object_refs(obj);
-	if (refs) {
-		unsigned j;
-		for (j = 0; j < refs->count; j++) {
-			struct object *ref = refs->ref[j];
-			if (ref->parsed ||
-			    (has_sha1_file(ref->sha1)))
-				continue;
-			printf("broken link from %7s %s\n",
-			       typename(obj->type), sha1_to_hex(obj->sha1));
-			printf("              to %7s %s\n",
-			       typename(ref->type), sha1_to_hex(ref->sha1));
-			errors_found |= ERROR_REACHABLE;
-		}
-	}
 }
 
 /*
