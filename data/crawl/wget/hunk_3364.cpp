 
       if (!check_user_specified_header (val))
 	{
-	  fprintf (stderr, _("%s: %s: Invalid specification `%s'.\n"),
+	  fprintf (stderr, _("%s: %s: Invalid header `%s'.\n"),
 		   exec_name, com, val);
 	  return 0;
 	}
