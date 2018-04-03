 			const char *lead = (namlen < len) ? entry->name : refname;
 			if (!strncmp(refname, entry->name, cmplen) &&
 			    lead[cmplen] == '/') {
-				if (!quiet)
-					error("'%s' exists; cannot create '%s'",
-					      entry->name, refname);
+				error("'%s' exists; cannot create '%s'",
+				      entry->name, refname);
 				return 0;
 			}
 		}
