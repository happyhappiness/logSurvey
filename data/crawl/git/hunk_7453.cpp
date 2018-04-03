 		hashcpy(sha1, o->sha1);
 	}
 	else {
-		/* At this point, the syntax look correct, so
+		/*
+		 * At this point, the syntax look correct, so
 		 * if we do not get the needed object, we should
 		 * barf.
 		 */
-
-		while (1) {
-			if (!o || (!o->parsed && !parse_object(o->sha1)))
-				return -1;
-			if (o->type == expected_type) {
-				hashcpy(sha1, o->sha1);
-				return 0;
-			}
-			if (o->type == OBJ_TAG)
-				o = ((struct tag*) o)->tagged;
-			else if (o->type == OBJ_COMMIT)
-				o = &(((struct commit *) o)->tree->object);
-			else
-				return error("%.*s: expected %s type, but the object dereferences to %s type",
-					     len, name, typename(expected_type),
-					     typename(o->type));
-			if (!o->parsed)
-				parse_object(o->sha1);
+		o = peel_to_type(name, len, o, expected_type);
+		if (o) {
+			hashcpy(sha1, o->sha1);
+			return 0;
 		}
+		return -1;
 	}
 	return 0;
 }