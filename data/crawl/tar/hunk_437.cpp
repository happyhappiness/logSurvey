 	       && uname_to_uid (optarg, &owner_option)))
 	  {
 	    uintmax_t u;
-	    if (!check_decimal (optarg, &u) || u != (uid_t) u)
-	      ERROR ((TAREXIT_FAILURE, 0, _("Invalid owner given on option")));
-	    else
+	    if (xstrtoumax (optarg, (char **) 0, 10, &u, "") == LONGINT_OK
+		&& u == (uid_t) u)
 	      owner_option = u;
+	    else
+	      ERROR ((TAREXIT_FAILURE, 0, _("Invalid owner given on option")));
 	  }
 	break;
 
