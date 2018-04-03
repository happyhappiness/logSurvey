 				 */
 				return 1;
 			}
-			report_refname_conflict(entry, refname);
+			error("'%s' exists; cannot create '%s'", entry->name, refname);
 			return 0;
 		}
 
