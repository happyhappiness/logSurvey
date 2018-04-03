 				return error_non_fast_forward($remote);
 			}
 			if ($status ne "ok") {
-				die("Unknown error from mw_push_file()");
+				die("Unknown error from mw_push_file()\n");
 			}
 		}
 		unless ($dumb_push) {