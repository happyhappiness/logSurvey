    long-named options.  */
 
 int
-_getopt_internal (int argc, char *const *argv, const char *optstring,
-		  const struct option *longopts, int *longind, int long_only)
+_getopt_internal (argc, argv, optstring, longopts, longind, long_only)
+     int argc;
+     char *const *argv;
+     const char *optstring;
+     const struct option *longopts;
+     int *longind;
+     int long_only;
 {
-  int option_index;
+  optarg = NULL;
 
-  optarg = 0;
-
-  /* Initialize the internal data when the first call is made.
-     Start processing options with ARGV-element 1 (since ARGV-element 0
-     is the program name); the sequence of previously skipped
-     non-option ARGV-elements is empty.  */
-
-  if (optind == 0)
+  if (optind == 0 || !__getopt_initialized)
     {
-      first_nonopt = last_nonopt = optind = 1;
-
-      nextchar = NULL;
-
-      /* Determine how to handle the ordering of options and nonoptions.  */
-
-      if (optstring[0] == '-')
-        {
-          ordering = RETURN_IN_ORDER;
-          ++optstring;
-        }
-      else if (optstring[0] == '+')
-        {
-          ordering = REQUIRE_ORDER;
-          ++optstring;
-        }
-      else if (getenv ("POSIXLY_CORRECT") != NULL)
-        ordering = REQUIRE_ORDER;
-      else
-        ordering = PERMUTE;
+      if (optind == 0)
+	optind = 1;	/* Don't scan ARGV[0], the program name.  */
+      optstring = _getopt_initialize (argc, argv, optstring);
+      __getopt_initialized = 1;
     }
 
+  /* Test whether ARGV[optind] points to a non-option argument.
+     Either it does not have option syntax, or there is an environment flag
+     from the shell indicating it is not an option.  The later information
+     is only used when the used in the GNU libc.  */
+#ifdef _LIBC
+# define NONOPTION_P (argv[optind][0] != '-' || argv[optind][1] == '\0'	      \
+		      || (optind < nonoption_flags_len			      \
+			  && __getopt_nonoption_flags[optind] == '1'))
+#else
+# define NONOPTION_P (argv[optind][0] != '-' || argv[optind][1] == '\0')
+#endif
+
   if (nextchar == NULL || *nextchar == '\0')
     {
+      /* Advance to the next ARGV-element.  */
+
+      /* Give FIRST_NONOPT & LAST_NONOPT rational values if OPTIND has been
+	 moved back by the user (who may also have changed the arguments).  */
+      if (last_nonopt > optind)
+	last_nonopt = optind;
+      if (first_nonopt > optind)
+	first_nonopt = optind;
+
       if (ordering == PERMUTE)
-        {
-          /* If we have just processed some options following some non-options,
-             exchange them so that the options come first.  */
-
-          if (first_nonopt != last_nonopt && last_nonopt != optind)
-            exchange ((char **) argv);
-          else if (last_nonopt != optind)
-            first_nonopt = optind;
-
-          /* Now skip any additional non-options
-             and extend the range of non-options previously skipped.  */
-
-          while (optind < argc
-                 && (argv[optind][0] != '-' || argv[optind][1] == '\0')
-#ifdef GETOPT_COMPAT
-                 && (longopts == NULL
-                     || argv[optind][0] != '+' || argv[optind][1] == '\0')
-#endif                                /* GETOPT_COMPAT */
-                 )
-            optind++;
-          last_nonopt = optind;
-        }
-
-      /* Special ARGV-element `--' means premature end of options.
-         Skip it like a null option,
-         then exchange with previous non-options as if it were an option,
-         then skip everything else like a non-option.  */
+	{
+	  /* If we have just processed some options following some non-options,
+	     exchange them so that the options come first.  */
+
+	  if (first_nonopt != last_nonopt && last_nonopt != optind)
+	    exchange ((char **) argv);
+	  else if (last_nonopt != optind)
+	    first_nonopt = optind;
+
+	  /* Skip any additional non-options
+	     and extend the range of non-options previously skipped.  */
+
+	  while (optind < argc && NONOPTION_P)
+	    optind++;
+	  last_nonopt = optind;
+	}
+
+      /* The special ARGV-element `--' means premature end of options.
+	 Skip it like a null option,
+	 then exchange with previous non-options as if it were an option,
+	 then skip everything else like a non-option.  */
 
       if (optind != argc && !strcmp (argv[optind], "--"))
-        {
-          optind++;
+	{
+	  optind++;
 
-          if (first_nonopt != last_nonopt && last_nonopt != optind)
-            exchange ((char **) argv);
-          else if (first_nonopt == last_nonopt)
-            first_nonopt = optind;
-          last_nonopt = argc;
+	  if (first_nonopt != last_nonopt && last_nonopt != optind)
+	    exchange ((char **) argv);
+	  else if (first_nonopt == last_nonopt)
+	    first_nonopt = optind;
+	  last_nonopt = argc;
 
-          optind = argc;
-        }
+	  optind = argc;
+	}
 
       /* If we have done all the ARGV-elements, stop the scan
-         and back over any non-options that we skipped and permuted.  */
+	 and back over any non-options that we skipped and permuted.  */
 
       if (optind == argc)
-        {
-          /* Set the next-arg-index to point at the non-options
-             that we previously skipped, so the caller will digest them.  */
-          if (first_nonopt != last_nonopt)
-            optind = first_nonopt;
-          return EOF;
-        }
+	{
+	  /* Set the next-arg-index to point at the non-options
+	     that we previously skipped, so the caller will digest them.  */
+	  if (first_nonopt != last_nonopt)
+	    optind = first_nonopt;
+	  return -1;
+	}
 
       /* If we have come to a non-option and did not permute it,
-         either stop the scan or describe it to the caller and pass it by.  */
-
-      if ((argv[optind][0] != '-' || argv[optind][1] == '\0')
-#ifdef GETOPT_COMPAT
-          && (longopts == NULL
-              || argv[optind][0] != '+' || argv[optind][1] == '\0')
-#endif                                /* GETOPT_COMPAT */
-          )
-        {
-          if (ordering == REQUIRE_ORDER)
-            return EOF;
-          optarg = argv[optind++];
-          return 1;
-        }
+	 either stop the scan or describe it to the caller and pass it by.  */
+
+      if (NONOPTION_P)
+	{
+	  if (ordering == REQUIRE_ORDER)
+	    return -1;
+	  optarg = argv[optind++];
+	  return 1;
+	}
 
       /* We have found another option-ARGV-element.
-         Start decoding its characters.  */
+	 Skip the initial punctuation.  */
 
       nextchar = (argv[optind] + 1
-                  + (longopts != NULL && argv[optind][1] == '-'));
+		  + (longopts != NULL && argv[optind][1] == '-'));
     }
 
+  /* Decode the current option-ARGV-element.  */
+
+  /* Check whether the ARGV-element is a long option.
+
+     If long_only and the ARGV-element has the form "-f", where f is
+     a valid short option, don't consider it an abbreviated form of
+     a long option that starts with f.  Otherwise there would be no
+     way to give the -f short option.
+
+     On the other hand, if there's a long option "fubar" and
+     the ARGV-element is "-fu", do consider that an abbreviation of
+     the long option, just like "--fu", and not "-f" with arg "u".
+
+     This distinction seems to be the most useful approach.  */
+
   if (longopts != NULL
-      && ((argv[optind][0] == '-'
-           && (argv[optind][1] == '-' || long_only))
-#ifdef GETOPT_COMPAT
-          || argv[optind][0] == '+'
-#endif                                /* GETOPT_COMPAT */
-          ))
+      && (argv[optind][1] == '-'
+	  || (long_only && (argv[optind][2] || !my_index (optstring, argv[optind][1])))))
     {
+      char *nameend;
       const struct option *p;
-      char *s = nextchar;
+      const struct option *pfound = NULL;
       int exact = 0;
       int ambig = 0;
-      const struct option *pfound = NULL;
-      int indfound;
-
-      indfound = 0;             /* To silence the compiler.  */
-
-      while (*s && *s != '=')
-        s++;
-
-      /* Test all options for either exact match or abbreviated matches.  */
-      for (p = longopts, option_index = 0; p->name;
-           p++, option_index++)
-        if (!strncmp (p->name, nextchar, s - nextchar))
-          {
-            if (s - nextchar == strlen (p->name))
-              {
-                /* Exact match found.  */
-                pfound = p;
-                indfound = option_index;
-                exact = 1;
-                break;
-              }
-            else if (pfound == NULL)
-              {
-                /* First nonexact match found.  */
-                pfound = p;
-                indfound = option_index;
-              }
-            else
-              /* Second nonexact match found.  */
-              ambig = 1;
-          }
+      int indfound = -1;
+      int option_index;
+
+      for (nameend = nextchar; *nameend && *nameend != '='; nameend++)
+	/* Do nothing.  */ ;
+
+      /* Test all long options for either exact match
+	 or abbreviated matches.  */
+      for (p = longopts, option_index = 0; p->name; p++, option_index++)
+	if (!strncmp (p->name, nextchar, nameend - nextchar))
+	  {
+	    if ((unsigned int) (nameend - nextchar)
+		== (unsigned int) strlen (p->name))
+	      {
+		/* Exact match found.  */
+		pfound = p;
+		indfound = option_index;
+		exact = 1;
+		break;
+	      }
+	    else if (pfound == NULL)
+	      {
+		/* First nonexact match found.  */
+		pfound = p;
+		indfound = option_index;
+	      }
+	    else
+	      /* Second or later nonexact match found.  */
+	      ambig = 1;
+	  }
 
       if (ambig && !exact)
-        {
-          if (opterr)
-            fprintf (stderr, _("%s: option `%s' is ambiguous\n"),
-                     exec_name, argv[optind]);
-          nextchar += strlen (nextchar);
-          optind++;
-          return '?';
-        }
+	{
+	  if (opterr)
+	    fprintf (stderr, _("%s: option `%s' is ambiguous\n"),
+		     argv[0], argv[optind]);
+	  nextchar += strlen (nextchar);
+	  optind++;
+	  optopt = 0;
+	  return '?';
+	}
 
       if (pfound != NULL)
-        {
-          option_index = indfound;
-          optind++;
-          if (*s)
-            {
-              /* Don't test has_arg with >, because some C compilers don't
-                 allow it to be used on enums.  */
-              if (pfound->has_arg)
-                optarg = s + 1;
-              else
-                {
-                  if (opterr)
-                    {
-                      if (argv[optind - 1][1] == '-')
-                        /* --option */
-                        fprintf (stderr,
-                                 _("%s: option `--%s' doesn't allow an argument\n"),
-                                 exec_name, pfound->name);
-                      else
-                        /* +option or -option */
-                        fprintf (stderr,
+	{
+	  option_index = indfound;
+	  optind++;
+	  if (*nameend)
+	    {
+	      /* Don't test has_arg with >, because some C compilers don't
+		 allow it to be used on enums.  */
+	      if (pfound->has_arg)
+		optarg = nameend + 1;
+	      else
+		{
+		  if (opterr)
+		    {
+		      if (argv[optind - 1][1] == '-')
+			/* --option */
+			fprintf (stderr,
+				 _("%s: option `--%s' doesn't allow an argument\n"),
+				 argv[0], pfound->name);
+		      else
+			/* +option or -option */
+			fprintf (stderr,
 				 _("%s: option `%c%s' doesn't allow an argument\n"),
-				 exec_name, argv[optind - 1][0], pfound->name);
-                    }
-                  nextchar += strlen (nextchar);
-                  return '?';
-                }
-            }
-          else if (pfound->has_arg == 1)
-            {
-              if (optind < argc)
-                optarg = argv[optind++];
-              else
-                {
-                  if (opterr)
-                    fprintf (stderr,
-			     _("%s: option `%s' requires an argument\n"),
-                             exec_name, argv[optind - 1]);
-                  nextchar += strlen (nextchar);
-                  return optstring[0] == ':' ? ':' : '?';
-                }
-            }
-          nextchar += strlen (nextchar);
-          if (longind != NULL)
-            *longind = option_index;
-          if (pfound->flag)
-            {
-              *(pfound->flag) = pfound->val;
-              return 0;
-            }
-          return pfound->val;
-        }
+				 argv[0], argv[optind - 1][0], pfound->name);
+		    }
+
+		  nextchar += strlen (nextchar);
+
+		  optopt = pfound->val;
+		  return '?';
+		}
+	    }
+	  else if (pfound->has_arg == 1)
+	    {
+	      if (optind < argc)
+		optarg = argv[optind++];
+	      else
+		{
+		  if (opterr)
+		    fprintf (stderr,
+			   _("%s: option `%s' requires an argument\n"),
+			   argv[0], argv[optind - 1]);
+		  nextchar += strlen (nextchar);
+		  optopt = pfound->val;
+		  return optstring[0] == ':' ? ':' : '?';
+		}
+	    }
+	  nextchar += strlen (nextchar);
+	  if (longind != NULL)
+	    *longind = option_index;
+	  if (pfound->flag)
+	    {
+	      *(pfound->flag) = pfound->val;
+	      return 0;
+	    }
+	  return pfound->val;
+	}
+
       /* Can't find it as a long option.  If this is not getopt_long_only,
-         or the option starts with '--' or is not a valid short
-         option, then it's an error.
-         Otherwise interpret it as a short option.  */
+	 or the option starts with '--' or is not a valid short
+	 option, then it's an error.
+	 Otherwise interpret it as a short option.  */
       if (!long_only || argv[optind][1] == '-'
-#ifdef GETOPT_COMPAT
-          || argv[optind][0] == '+'
-#endif                                /* GETOPT_COMPAT */
-          || my_index (optstring, *nextchar) == NULL)
-        {
-          if (opterr)
-            {
-              if (argv[optind][1] == '-')
-                /* --option */
-                fprintf (stderr, _("%s: unrecognized option `--%s'\n"),
-                         exec_name, nextchar);
-              else
-                /* +option or -option */
-                fprintf (stderr, _("%s: unrecognized option `%c%s'\n"),
-                         exec_name, argv[optind][0], nextchar);
-            }
-          nextchar = (char *) "";
-          optind++;
-          return '?';
-        }
+	  || my_index (optstring, *nextchar) == NULL)
+	{
+	  if (opterr)
+	    {
+	      if (argv[optind][1] == '-')
+		/* --option */
+		fprintf (stderr, _("%s: unrecognized option `--%s'\n"),
+			 argv[0], nextchar);
+	      else
+		/* +option or -option */
+		fprintf (stderr, _("%s: unrecognized option `%c%s'\n"),
+			 argv[0], argv[optind][0], nextchar);
+	    }
+	  nextchar = (char *) "";
+	  optind++;
+	  optopt = 0;
+	  return '?';
+	}
     }
 
-  /* Look at and handle the next option-character.  */
+  /* Look at and handle the next short option-character.  */
 
   {
     char c = *nextchar++;
