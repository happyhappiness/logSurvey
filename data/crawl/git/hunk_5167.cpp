 				       mime_boundary_leader,
 				       rev.mime_boundary);
 			else
-				printf("-- \n%s\n\n", git_version_string);
+				print_signature();
 		}
 		if (!use_stdout)
 			fclose(stdout);
