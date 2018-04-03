 
 		if (flags & TRANSPORT_PUSH_VERBOSE)
 			fprintf(stderr, "Pushing to %s\n", url[i]);
-		err = transport_push(transport, refspec_nr, refspec, flags);
+		err = transport_push(transport, refspec_nr, refspec, flags,
+				     &nonfastforward);
 		err |= transport_disconnect(transport);
 
 		if (!err)
 			continue;
 
 		error("failed to push some refs to '%s'", url[i]);
+		if (nonfastforward) {
+			printf("To prevent you from losing history, non-fast-forward updates were rejected.\n"
+			       "Merge the remote changes before pushing again.\n"
+			       "See 'non-fast forward' section of 'git push --help' for details.\n");
+		}
 		errs++;
 	}
 	return !!errs;
