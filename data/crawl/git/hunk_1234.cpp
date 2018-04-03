 		 * apply the patch data to it, which is stored
 		 * in the patch->fragments->{patch,size}.
 		 */
-		if (apply_binary_fragment(img, patch))
+		if (apply_binary_fragment(state, img, patch))
 			return error(_("binary patch does not apply to '%s'"),
 				     name);
 
