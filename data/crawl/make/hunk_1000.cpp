 		}
 	    }
 	  else if (!ignoring
-		   && !try_variable_definition (&fileinfo, p2, o_override))
+		   && !try_variable_definition (&fileinfo, p2, o_override, 0))
 	    error (&fileinfo, _("invalid `override' directive"));
 
 	  continue;
