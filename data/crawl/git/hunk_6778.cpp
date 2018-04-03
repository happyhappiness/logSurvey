 	 * ref points at a nonexistent object.
 	 */
 	if (!has_sha1_file(sha1))
-		die("git-show-ref: bad ref %s (%s)", refname,
+		die("git show-ref: bad ref %s (%s)", refname,
 		    sha1_to_hex(sha1));
 
 	if (quiet)
