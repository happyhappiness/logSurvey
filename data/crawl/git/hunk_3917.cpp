 			strbuf_release(&branch_ref);
 
 			if (!argc)
-				return error("No commit on branch '%s' yet.",
+				return error(_("No commit on branch '%s' yet."),
 					     branch_name);
 			else
-				return error("No such branch '%s'.", branch_name);
+				return error(_("No branch named '%s'."),
+					     branch_name);
 		}
 		strbuf_release(&branch_ref);
 