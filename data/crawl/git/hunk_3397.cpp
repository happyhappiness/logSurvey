 				saved = shared_repository;
 				shared_repository = 0;
 				switch (safe_create_leading_directories_const(argv[0])) {
+				case SCLD_OK:
+				case SCLD_PERMS:
+					break;
 				case SCLD_EXISTS:
 					errno = EEXIST;
 					/* fallthru */
-				case SCLD_FAILED:
-					die_errno(_("cannot mkdir %s"), argv[0]);
-					break;
 				default:
+					die_errno(_("cannot mkdir %s"), argv[0]);
 					break;
 				}
 				shared_repository = saved;