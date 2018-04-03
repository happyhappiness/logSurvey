 	  if (in_ignored_define)
 	    in_ignored_define = 0;
 	  else
-	    fatal (&fileinfo, "extraneous `endef'");
+	    fatal (&fileinfo, _("extraneous `endef'"));
 	  continue;
 	}
 
