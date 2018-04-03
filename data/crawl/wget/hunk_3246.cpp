   windows_main_junk (&argc, (char **) argv, (char **) &exec_name);
 #endif
 
-  initialize (); /* sets option defaults; reads the system wgetrc and .wgetrc */
+  /* Set option defaults; read the system wgetrc and ~/.wgetrc.  */
+  initialize ();
 
-  /* [Is the order of the option letters significant?  If not, they should be
-      alphabetized, like the long_options.  The only thing I know for sure is
-      that the options with required arguments must be followed by a ':'.
-      -- Dan Harkless <wget@harkless.org>] */
-  while ((c = getopt_long (argc, argv, "\
-hpVqvdkKsxmNWrHSLcFbEY:G:g:T:U:O:l:n:i:o:a:t:D:A:R:P:B:e:Q:X:I:w:C:",
-			   long_options, (int *)0)) != EOF)
+  init_switches ();
+  longindex = -1;
+  while ((ret = getopt_long (argc, argv,
+			     short_options, long_options, &longindex)) != -1)
     {
-      switch (c)
+      int val;
+      struct cmdline_option *opt;
+      if (ret == '?')
 	{
-	  /* Options without arguments: */
-	case 132:
-	  setoptval ("spider", "on");
-	  break;
-	case 133:
-	  setoptval ("noparent", "on");
-	  break;
-	case 136:
-	  setoptval ("deleteafter", "on");
-	  break;
-	case 137:
-	  setoptval ("retrsymlinks", "on");
-	  break;
-	case 138:
-	  setoptval ("ignorelength", "on");
-	  break;
-	case 139:
-	  setoptval ("passiveftp", "on");
-	  break;
-	case 141:
-	  setoptval ("noclobber", "on");
-	  break;
-	case 142:
-	  setoptval ("followftp", "on");
-	  break;
-	case 145:
-	  setoptval ("cutdirs", optarg);
-	  break;
-	case 146:
-	  setoptval ("verbose", "off");
-	  break;
-	case 147:
-	  setoptval ("dirstruct", "off");
-	  break;
-	case 148:
-	  setoptval ("addhostdir", "off");
-	  break;
-	case 149:
-	  setoptval ("removelisting", "off");
-	  break;
-	case 155:
-	  setoptval ("bindaddress", optarg);
- 	  break;
-	case 156:
-	  setoptval ("httpkeepalive", "off");
-	  break;
-	case 165:
-	  setoptval ("randomwait", "on");
-	  break;
-	case 'b':
-	  setoptval ("background", "on");
-	  break;
-	case 'c':
-	  setoptval ("continue", "on");
-	  break;
-	case 'd':
-#ifdef ENABLE_DEBUG
-	  setoptval ("debug", "on");
-#else
-	  fprintf (stderr, _("%s: debug support not compiled in.\n"),
-		   exec_name);
-#endif
-	  break;
-	case 'E':
-	  setoptval ("htmlextension", "on");
-	  break;
-	case 'F':
-	  setoptval ("forcehtml", "on");
+	  print_usage ();
+	  printf ("\n");
+	  printf (_("Try `%s --help' for more options.\n"), exec_name);
+	  exit (2);
+	}
+
+      /* If LONGINDEX is unchanged, it means RET is referring a short
+	 option.  Look it up in the mapping table.  */
+      if (longindex == -1)
+	longindex = optmap[ret - 32];
+      val = long_options[longindex].val;
+
+      /* Use the retrieved value to locate the option in the
+	 option_data array, and to see if we're dealing with the
+	 negated "--no-FOO" variant of the boolean option "--foo".  */
+      opt = &option_data[val & ~BOOLEAN_NEG_MARKER];
+      switch (opt->type)
+	{
+	case OPT_VALUE:
+	  setoptval (opt->handle_cmd, optarg);
+	  break;
+	case OPT_BOOLEAN:
+	  if (optarg)
+	    /* The user has specified a value -- use it. */
+	    setoptval (opt->handle_cmd, optarg);
+	  else
+	    {
+	      /* NEG is true for `--no-FOO' style boolean options. */
+	      int neg = val & BOOLEAN_NEG_MARKER;
+	      setoptval (opt->handle_cmd, neg ? "0" : "1");
+	    }
 	  break;
-	case 'H':
-	  setoptval ("spanhosts", "on");
+	case OPT__APPEND_OUTPUT:
+	  setoptval ("logfile", optarg);
+	  append_to_log = 1;
 	  break;
-	case 'h':
+	case OPT__HELP:
 	  print_help ();
 #ifdef WINDOWS
 	  ws_help (exec_name);
 #endif
 	  exit (0);
 	  break;
-	case 'K':
-	  setoptval ("backupconverted", "on");
-	  break;
-	case 'k':
-	  setoptval ("convertlinks", "on");
-	  break;
-	case 'L':
-	  setoptval ("relativeonly", "on");
-	  break;
-	case 'm':
-	  setoptval ("mirror", "on");
-	  break;
-	case 'N':
-	  setoptval ("timestamping", "on");
-	  break;
-	case 'p':
-	  setoptval ("pagerequisites", "on");
-	  break;
-	case 'S':
-	  setoptval ("serverresponse", "on");
-	  break;
-	case 's':
-	  setoptval ("saveheaders", "on");
-	  break;
-	case 'q':
-	  setoptval ("quiet", "on");
-	  break;
-	case 'r':
-	  setoptval ("recursive", "on");
-	  break;
-	case 'V':
-	  printf ("GNU Wget %s\n\n", version_string);
-	  printf ("%s", _("\
-Copyright (C) 2003 Free Software Foundation, Inc.\n"));
-	  printf ("%s", _("\
-This program is distributed in the hope that it will be useful,\n\
-but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
-GNU General Public License for more details.\n"));
-	  printf (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"));
-	  exit (0);
-	  break;
-	case 'v':
-	  setoptval ("verbose", "on");
-	  break;
-	case 'x':
-	  setoptval ("dirstruct", "on");
-	  break;
-	case 174:
-	  setoptval ("retryconnrefused", "on");
-	  break;
-	case 177:
-	  setoptval ("strictcomments", "on");
-	  break;
-	case 181:
-	  setoptval ("keepsessioncookies", "on");
-	  break;
-
-	  /* Options accepting an argument: */
-	case 129:
-	  setoptval ("httpuser", optarg);
-	  break;
-	case 130:
-	  setoptval ("httppasswd", optarg);
-	  break;
-	case 131:
-	  setoptval ("header", optarg);
-	  break;
-	case 134:
-	  setoptval ("dotstyle", optarg);
-	  break;
-	case 135:
-	  setoptval ("htmlify", optarg);
-	  break;
-	case 140:
-	  setoptval ("excludedomains", optarg);
-	  break;
-	case 143:
-	  setoptval ("proxyuser", optarg);
-	  break;
-	case 144:
-	  setoptval ("proxypasswd", optarg);
-	  break;
-	case 151:
-	  setoptval ("backups", optarg);
-	  break;
-	case 152:
-	  setoptval ("waitretry", optarg);
-	  break;
-	case 153:
-	  setoptval ("followtags", optarg);
-	  break;
-	case 160:
-	  setoptval ("cookies", optarg);
-	  break;
-	case 161:
-	  setoptval ("loadcookies", optarg);
-	  break;
-	case 162:
-	  setoptval ("savecookies", optarg);
-	  break;
-	case 163:
-	  setoptval ("progress", optarg);
-	  break;
-	case 164:
-	  setoptval ("limitrate", optarg);
-	  break;
-	case 157:
-	  setoptval ("referer", optarg);
-	  break;
-#ifdef HAVE_SSL
-	case 158:
-	  setoptval ("sslcertfile", optarg);
-	  break;
-	case 159:
-	  setoptval ("sslcertkey", optarg);
-	  break;
-	case 166:
-	  setoptval ("egdfile", optarg);
-	  break;
-	case 169:
-	  setoptval ("sslcadir", optarg);
-	  break;
-	case 170:
-	  setoptval ("sslcafile", optarg);
-	  break;
-	case 171:
-	  setoptval ("sslcerttype", optarg);
-	  break;
-	case 172:
-	  setoptval ("sslcheckcert", optarg);
-	  break;
-	case 173:
-	  setoptval ("sslprotocol", optarg);
-	  break;
-#endif /* HAVE_SSL */
-	case 167:
-	  setoptval ("postdata", optarg);
-	  break;
-	case 168:
-	  setoptval ("postfile", optarg);
-	  break;
-	case 175:
-	  setoptval ("dnscache", optarg);
-	  break;
-	case 176:
-	  setoptval ("restrictfilenames", optarg);
-	  break;
-	case 178:
-	  setoptval ("dnstimeout", optarg);
-	  break;
-	case 179:
-	  setoptval ("readtimeout", optarg);
-	  break;
-	case 180:
-	  setoptval ("connecttimeout", optarg);
-	  break;
-	case 'A':
-	  setoptval ("accept", optarg);
-	  break;
-	case 'a':
-	  setoptval ("logfile", optarg);
-	  append_to_log = 1;
-	  break;
-	case 'B':
-	  setoptval ("base", optarg);
-	  break;
-	case 'C':
-	  setoptval ("cache", optarg);
-	  break;
-	case 'D':
-	  setoptval ("domains", optarg);
-	  break;
-	case 'e':
+	case OPT__EXECUTE:
 	  run_command (optarg);
 	  break;
-	case 'G':
-	  setoptval ("ignoretags", optarg);
-	  break;
-	case 'g':
-	  setoptval ("glob", optarg);
-	  break;
-	case 'I':
-	  setoptval ("includedirectories", optarg);
-	  break;
-	case 'i':
-	  setoptval ("input", optarg);
-	  break;
-	case 'l':
-	  setoptval ("reclevel", optarg);
-	  break;
-	case 'n':
+	case OPT__NO:
 	  {
-	    /* #### What we really want here is --no-foo. */
+	    /* We support real --no-FOO flags now, but keep these
+	       short options for convenience and backward
+	       compatibility.  */
 	    char *p;
-
 	    for (p = optarg; *p; p++)
 	      switch (*p)
 		{
 		case 'v':
-		  setoptval ("verbose", "off");
+		  setoptval ("verbose", "0");
 		  break;
 		case 'H':
-		  setoptval ("addhostdir", "off");
+		  setoptval ("addhostdir", "0");
 		  break;
 		case 'd':
-		  setoptval ("dirstruct", "off");
+		  setoptval ("dirstruct", "0");
 		  break;
 		case 'c':
-		  setoptval ("noclobber", "on");
-		  break;
-		case 'r':
-		  setoptval ("removelisting", "off");
+		  setoptval ("noclobber", "1");
 		  break;
 		case 'p':
-		  setoptval ("noparent", "on");
-		  break;
-		case 'k':
-		  setoptval ("httpkeepalive", "off");
+		  setoptval ("noparent", "1");
 		  break;
 		default:
 		  printf (_("%s: illegal option -- `-n%c'\n"), exec_name, *p);
