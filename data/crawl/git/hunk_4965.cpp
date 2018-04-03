 				printf("Removing %s\n", qname);
 			}
 			if (unlink(ent->name) != 0) {
-				warning("failed to remove '%s'", qname);
+				warning("failed to remove %s", qname);
 				errors++;
 			}
 		}