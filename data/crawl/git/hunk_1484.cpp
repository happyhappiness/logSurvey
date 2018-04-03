 				break;
 			}
 			fprintf(stderr, "%s: unmerged (%s)\n",
-				ce->name, sha1_to_hex(ce->sha1));
+				ce->name, oid_to_hex(&ce->oid));
 		}
 	}
 	if (funny)
