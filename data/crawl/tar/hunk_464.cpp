 
       case GROUP_OPTION:
 	if (!gname_to_gid (optarg, &group_option))
-	  if (!check_decimal (optarg) >= 0)
-	    ERROR ((TAREXIT_FAILURE, 0, _("Invalid group given on option")));
-	  else
-	    group_option = check_decimal (optarg);
+	  {
+	    uintmax_t g;
+	    if (!check_decimal (optarg, &g) || g != (gid_t) g)
+	      ERROR ((TAREXIT_FAILURE, 0, _("Invalid group given on option")));
+	    else
+	      group_option = g;
+	  }
 	break;
 
       case MODE_OPTION:
