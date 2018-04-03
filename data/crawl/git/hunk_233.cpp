 		case DIFF_STATUS_DELETED:
 			printf("D ");
 			print_path(spec->path);
+			string_list_insert(changed, spec->path);
 			putchar('\n');
 			break;
 
 		case DIFF_STATUS_COPIED:
 		case DIFF_STATUS_RENAMED:
-			printf("%c ", q->queue[i]->status);
-			print_path(ospec->path);
-			putchar(' ');
-			print_path(spec->path);
-			putchar('\n');
-
-			if (!oidcmp(&ospec->oid, &spec->oid) &&
-			    ospec->mode == spec->mode)
-				break;
+			/*
+			 * If a change in the file corresponding to ospec->path
+			 * has been observed, we cannot trust its contents
+			 * because the diff is calculated based on the prior
+			 * contents, not the current contents.  So, declare a
+			 * copy or rename only if there was no change observed.
+			 */
+			if (!string_list_has_string(changed, ospec->path)) {
+				printf("%c ", q->queue[i]->status);
+				print_path(ospec->path);
+				putchar(' ');
+				print_path(spec->path);
+				string_list_insert(changed, spec->path);
+				putchar('\n');
+
+				if (!oidcmp(&ospec->oid, &spec->oid) &&
+				    ospec->mode == spec->mode)
+					break;
+			}
 			/* fallthrough */
 
 		case DIFF_STATUS_TYPE_CHANGED:
