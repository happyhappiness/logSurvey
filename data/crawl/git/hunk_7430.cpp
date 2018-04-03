 				printf("Removing %s\n",
 				       ent->name + prefix_offset);
 			}
-			unlink(ent->name);
+			if (unlink(ent->name) != 0) {
+				warning("failed to remove '%s'", ent->name);
+				errors++;
+			}
 		}
 	}
 	free(seen);
 
 	strbuf_release(&directory);
-	return 0;
+	return (errors != 0);
 }
