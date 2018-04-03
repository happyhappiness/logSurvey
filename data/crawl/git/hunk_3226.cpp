 				 * a proper prefix of refname; e.g.,
 				 * "refs/foo", and is not in skip.
 				 */
-				error("'%s' exists; cannot create '%s'",
-				      dirname.buf, refname);
+				strbuf_addf(err, "'%s' exists; cannot create '%s'",
+					    dirname.buf, refname);
 				goto cleanup;
 			}
 		}
 
 		if (extras && string_list_has_string(extras, dirname.buf) &&
 		    (!skip || !string_list_has_string(skip, dirname.buf))) {
-			error("cannot process '%s' and '%s' at the same time",
-			      refname, dirname.buf);
+			strbuf_addf(err, "cannot process '%s' and '%s' at the same time",
+				    refname, dirname.buf);
 			goto cleanup;
 		}
 
