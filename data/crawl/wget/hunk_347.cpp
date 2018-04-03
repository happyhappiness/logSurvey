   windows_main ((char **) &exec_name);
 #endif
 
-  /* Set option defaults; read the system wgetrc and ~/.wgetrc.  */
-  initialize ();
+  /* Load the hard-coded defaults.  */
+  defaults ();
 
   init_switches ();
+
+  /* This seperate getopt_long is needed to find the user config
+     and parse it before the other user options. */
+  longindex = -1;
+  int retconf;
+  bool use_userconfig = false;
+
+  while ((retconf = getopt_long (argc, argv,
+                                short_options, long_options, &longindex)) != -1)
+    {
+      int confval;
+      bool userrc_ret = true;
+      struct cmdline_option *config_opt;
+      confval = long_options[longindex].val;
+      config_opt = &option_data[confval & ~BOOLEAN_NEG_MARKER];
+      if (strcmp (config_opt->long_name, "config") == 0)
+        {
+          userrc_ret &= run_wgetrc (optarg);
+          use_userconfig = true;
+        }
+      if (!userrc_ret)
+        {
+          printf ("Exiting due to error in %s\n", optarg);
+          exit (2);
+        }
+      else
+        break;
+    }
+
+  /* If the user did not specify a config, read the system wgetrc and ~/.wgetrc. */
+  if (use_userconfig == false)
+    initialize ();
+
+  opterr = 0;
+  optind = 0;
+
   longindex = -1;
   while ((ret = getopt_long (argc, argv,
                              short_options, long_options, &longindex)) != -1)
