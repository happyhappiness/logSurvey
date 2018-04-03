 		} else if (S_ISLNK(a->mode)) {
 			oidcpy(&result.oid, &a->oid);
 
-			if (!sha_eq(a->oid.hash, b->oid.hash))
+			if (!oid_eq(&a->oid, &b->oid))
 				result.clean = 0;
 		} else {
 			die(_("unsupported object type in the tree"));
