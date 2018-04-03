 				 * commits at the remote end and likely
 				 * we were not up to date to begin with.
 				 */
-				error("remote '%s' is not a strict "
-				      "subset of local ref '%s'. "
-				      "maybe you are not up-to-date and "
+				error("remote '%s' is not an ancestor of\n"
+				      " local  '%s'.\n"
+				      " Maybe you are not up-to-date and "
 				      "need to pull first?",
 				      ref->name,
 				      ref->peer_ref->name);