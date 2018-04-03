 		struct commit_list *j;
 
 		if (remoteheads->next) {
-			error("Not handling anything other than two heads merge.");
+			error(_("Not handling anything other than two heads merge."));
 			return 2;
 		}
 
