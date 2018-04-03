 				 * check both source and destination
 				 */
 				if (S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)) {
-					warning(_("overwriting '%s'"), dst);
+					if (verbose)
+						warning(_("overwriting '%s'"), dst);
 					bad = NULL;
 				} else
 					bad = _("Cannot overwrite");