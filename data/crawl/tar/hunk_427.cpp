 		&& u == (uid_t) u)
 	      owner_option = u;
 	    else
-	      ERROR ((TAREXIT_FAILURE, 0, _("Invalid owner given on option")));
+	      FATAL_ERROR ((0, 0, _("Invalid owner given on option")));
 	  }
 	break;
 
