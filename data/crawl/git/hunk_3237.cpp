 				 * "refs/foo"). So we can stop looking
 				 * now and return true.
 				 */
-				return 1;
+				ret = 1;
+				goto cleanup;
 			}
-			error("'%s' exists; cannot create '%s'", entry->name, refname);
-			return 0;
+			error("'%s' exists; cannot create '%s'", dirname.buf, refname);
+			goto cleanup;
 		}
 
 
