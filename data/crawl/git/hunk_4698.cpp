 				temp = log_all_ref_updates;
 				log_all_ref_updates = 1;
 				if (log_ref_setup(ref_name, log_file, sizeof(log_file))) {
-					fprintf(stderr, "Can not do reflog for '%s'\n",
+					fprintf(stderr, _("Can not do reflog for '%s'\n"),
 					    opts->new_orphan_branch);
 					log_all_ref_updates = temp;
 					return;
