 		}
 
 		return o->gently ? -1 :
-			error(ERRORMSG(o, would_lose_untracked), ce->name, action);
+			error(ERRORMSG(o, ERROR_WOULD_LOSE_UNTRACKED), ce->name, action);
 	}
 	return 0;
 }
