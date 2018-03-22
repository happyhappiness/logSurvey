 
 #endif /* not DEVICE_PREFIX */
 
+    case ARGP_KEY_ERROR:
+      if (args->loc->source == OPTS_FILE)
+	error (0, 0, _("%s:%lu: location of the error"), args->loc->name,
+	       (unsigned long) args->loc->line);
+      else if (args->loc->source == OPTS_ENVIRON)
+	error (0, 0, _("error parsing %s"), args->loc->name);
+      exit (EX_USAGE);
+      
     default:
       return ARGP_ERR_UNKNOWN;
     }
