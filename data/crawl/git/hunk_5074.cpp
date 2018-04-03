 		}
 
 		return o->gently ? -1 :
-			error(ERRORMSG(o, error_type), ce->name);
+			add_rejected_path(o, error_type, ce->name);
 	}
 	return 0;
 }
