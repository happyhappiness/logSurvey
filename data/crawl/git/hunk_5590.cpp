 
 		if (!rc)
 			fprintf(stderr, "    done\n");
+		if (helper_status)
+			printf("%s %s\n", !rc ? "ok" : "error", ref->name);
 		unlock_remote(ref_lock);
 		check_locks();
 	}
