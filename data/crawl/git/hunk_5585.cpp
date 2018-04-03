 
 	/* Remove a remote branch if -d or -D was specified */
 	if (delete_branch) {
-		if (delete_remote_branch(refspec[0], force_delete) == -1)
+		if (delete_remote_branch(refspec[0], force_delete) == -1) {
 			fprintf(stderr, "Unable to delete remote branch %s\n",
 				refspec[0]);
+			if (helper_status)
+				printf("error %s cannot remove\n", refspec[0]);
+		}
 		goto cleanup;
 	}
 
