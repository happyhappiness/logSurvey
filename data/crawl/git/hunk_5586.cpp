 	}
 	if (!remote_refs) {
 		fprintf(stderr, "No refs in common and none specified; doing nothing.\n");
+		if (helper_status)
+			printf("error null no match\n");
 		rc = 0;
 		goto cleanup;
 	}
