   init_switches ();
   longindex = -1;
   while ((ret = getopt_long (argc, argv,
-			     short_options, long_options, &longindex)) != -1)
+                             short_options, long_options, &longindex)) != -1)
     {
       int val;
       struct cmdline_option *opt;
 
       /* If LONGINDEX is unchanged, it means RET is referring a short
-	 option.  */
+         option.  */
       if (longindex == -1)
-	{
-	  if (ret == '?')
-	    {
-	      print_usage ();
-	      printf ("\n");
-	      printf (_("Try `%s --help' for more options.\n"), exec_name);
-	      exit (2);
-	    }
-	  /* Find the short option character in the mapping.  */
-	  longindex = optmap[ret - 32];
-	}
+        {
+          if (ret == '?')
+            {
+              print_usage ();
+              printf ("\n");
+              printf (_("Try `%s --help' for more options.\n"), exec_name);
+              exit (2);
+            }
+          /* Find the short option character in the mapping.  */
+          longindex = optmap[ret - 32];
+        }
       val = long_options[longindex].val;
 
       /* Use the retrieved value to locate the option in the
-	 option_data array, and to see if we're dealing with the
-	 negated "--no-FOO" variant of the boolean option "--foo".  */
+         option_data array, and to see if we're dealing with the
+         negated "--no-FOO" variant of the boolean option "--foo".  */
       opt = &option_data[val & ~BOOLEAN_NEG_MARKER];
       switch (opt->type)
-	{
-	case OPT_VALUE:
-	  setoptval (opt->data, optarg, opt->long_name);
-	  break;
-	case OPT_BOOLEAN:
-	  if (optarg)
-	    /* The user has specified a value -- use it. */
-	    setoptval (opt->data, optarg, opt->long_name);
-	  else
-	    {
-	      /* NEG is true for `--no-FOO' style boolean options. */
-	      bool neg = !!(val & BOOLEAN_NEG_MARKER);
-	      setoptval (opt->data, neg ? "0" : "1", opt->long_name);
-	    }
-	  break;
-	case OPT_FUNCALL:
-	  {
-	    void (*func) (void) = (void (*) (void)) opt->data;
-	    func ();
-	  }
-	  break;
-	case OPT__APPEND_OUTPUT:
-	  setoptval ("logfile", optarg, opt->long_name);
-	  append_to_log = true;
-	  break;
-	case OPT__EXECUTE:
-	  run_command (optarg);
-	  break;
-	case OPT__NO:
-	  {
-	    /* We support real --no-FOO flags now, but keep these
-	       short options for convenience and backward
-	       compatibility.  */
-	    char *p;
-	    for (p = optarg; *p; p++)
-	      switch (*p)
-		{
-		case 'v':
-		  setoptval ("verbose", "0", opt->long_name);
-		  break;
-		case 'H':
-		  setoptval ("addhostdir", "0", opt->long_name);
-		  break;
-		case 'd':
-		  setoptval ("dirstruct", "0", opt->long_name);
-		  break;
-		case 'c':
-		  setoptval ("noclobber", "1", opt->long_name);
-		  break;
-		case 'p':
-		  setoptval ("noparent", "1", opt->long_name);
-		  break;
-		default:
-		  printf (_("%s: illegal option -- `-n%c'\n"), exec_name, *p);
-		  print_usage ();
-		  printf ("\n");
-		  printf (_("Try `%s --help' for more options.\n"), exec_name);
-		  exit (1);
-		}
-	    break;
-	  }
-	case OPT__PARENT:
-	case OPT__CLOBBER:
-	  {
-	    /* The wgetrc commands are named noparent and noclobber,
-	       so we must revert the meaning of the cmdline options
-	       before passing the value to setoptval.  */
-	    bool flag = true;
-	    if (optarg)
-	      flag = (*optarg == '1' || TOLOWER (*optarg) == 'y'
-		      || (TOLOWER (optarg[0]) == 'o'
-			  && TOLOWER (optarg[1]) == 'n'));
-	    setoptval (opt->type == OPT__PARENT ? "noparent" : "noclobber",
-		       flag ? "0" : "1", opt->long_name);
-	    break;
-	  }
-	case OPT__DONT_REMOVE_LISTING:
-	  setoptval ("removelisting", "0", opt->long_name);
-	  break;
-	}
+        {
+        case OPT_VALUE:
+          setoptval (opt->data, optarg, opt->long_name);
+          break;
+        case OPT_BOOLEAN:
+          if (optarg)
+            /* The user has specified a value -- use it. */
+            setoptval (opt->data, optarg, opt->long_name);
+          else
+            {
+              /* NEG is true for `--no-FOO' style boolean options. */
+              bool neg = !!(val & BOOLEAN_NEG_MARKER);
+              setoptval (opt->data, neg ? "0" : "1", opt->long_name);
+            }
+          break;
+        case OPT_FUNCALL:
+          {
+            void (*func) (void) = (void (*) (void)) opt->data;
+            func ();
+          }
+          break;
+        case OPT__APPEND_OUTPUT:
+          setoptval ("logfile", optarg, opt->long_name);
+          append_to_log = true;
+          break;
+        case OPT__EXECUTE:
+          run_command (optarg);
+          break;
+        case OPT__NO:
+          {
+            /* We support real --no-FOO flags now, but keep these
+               short options for convenience and backward
+               compatibility.  */
+            char *p;
+            for (p = optarg; *p; p++)
+              switch (*p)
+                {
+                case 'v':
+                  setoptval ("verbose", "0", opt->long_name);
+                  break;
+                case 'H':
+                  setoptval ("addhostdir", "0", opt->long_name);
+                  break;
+                case 'd':
+                  setoptval ("dirstruct", "0", opt->long_name);
+                  break;
+                case 'c':
+                  setoptval ("noclobber", "1", opt->long_name);
+                  break;
+                case 'p':
+                  setoptval ("noparent", "1", opt->long_name);
+                  break;
+                default:
+                  printf (_("%s: illegal option -- `-n%c'\n"), exec_name, *p);
+                  print_usage ();
+                  printf ("\n");
+                  printf (_("Try `%s --help' for more options.\n"), exec_name);
+                  exit (1);
+                }
+            break;
+          }
+        case OPT__PARENT:
+        case OPT__CLOBBER:
+          {
+            /* The wgetrc commands are named noparent and noclobber,
+               so we must revert the meaning of the cmdline options
+               before passing the value to setoptval.  */
+            bool flag = true;
+            if (optarg)
+              flag = (*optarg == '1' || TOLOWER (*optarg) == 'y'
+                      || (TOLOWER (optarg[0]) == 'o'
+                          && TOLOWER (optarg[1]) == 'n'));
+            setoptval (opt->type == OPT__PARENT ? "noparent" : "noclobber",
+                       flag ? "0" : "1", opt->long_name);
+            break;
+          }
+        case OPT__DONT_REMOVE_LISTING:
+          setoptval ("removelisting", "0", opt->long_name);
+          break;
+        }
 
       longindex = -1;
     }
 
+  nurl = argc - optind;
+
   /* All user options have now been processed, so it's now safe to do
      interoption dependency checks. */
 
