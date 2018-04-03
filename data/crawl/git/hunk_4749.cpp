 	} else {
 		/* Nothing to checkout out */
 		if (!option_no_checkout)
-			warning("remote HEAD refers to nonexistent ref, "
-				"unable to checkout.\n");
+			warning(_("remote HEAD refers to nonexistent ref, "
+				"unable to checkout.\n"));
 		option_no_checkout = 1;
 	}
 
