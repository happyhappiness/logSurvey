 		}
 	}
 	if (!name)
-		die(_("unable to find filename in patch at line %d"), linenr);
+		die(_("unable to find filename in patch at line %d"), state_linenr);
 }
 
 static int gitdiff_hdrend(const char *line, struct patch *patch)
