 	  if (*p == '\0')
 	    {
 	      error (&fileinfo,
-			      "no file name for `%sinclude'",
+			      _("no file name for `%sinclude'"),
 			      noerror ? "-" : "");
 	      continue;
 	    }
