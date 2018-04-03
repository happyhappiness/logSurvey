 			goto bad_graft_data;
 	}
 	return graft;
+
+bad_graft_data:
+	error("bad graft data: %s", buf);
+	free(graft);
+	return NULL;
 }
 
 static int read_graft_file(const char *graft_file)