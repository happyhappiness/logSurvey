 				    $_->{INDEX_ADDDEL} eq 'create') {
 					system(qw(git update-index --force-remove --),
 					       $_->{VALUE});
-					print "note: $_->{VALUE} is untracked now.\n";
+					printf(__("note: %s is untracked now.\n"), $_->{VALUE});
 				}
 			}
 		}
