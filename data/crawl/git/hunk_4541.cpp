 				 * check both source and destination
 				 */
 				if (S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)) {
-					warning("%s; will overwrite!", bad);
+					warning(_("%s; will overwrite!"), bad);
 					bad = NULL;
 				} else
 					bad = "Cannot overwrite";
