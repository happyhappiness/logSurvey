 				 */
 				if (parse_commit(p) < 0)
 					die("cannot simplify commit %s (invalid %s)",
-					    sha1_to_hex(commit->object.sha1),
-					    sha1_to_hex(p->object.sha1));
+					    oid_to_hex(&commit->object.oid),
+					    oid_to_hex(&p->object.oid));
 				p->parents = NULL;
 			}
 		/* fallthrough */
