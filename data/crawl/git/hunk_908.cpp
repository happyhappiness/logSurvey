 					} else {
 						next if ($suppress_cc{'cc'});
 					}
-					printf("(mbox) Adding cc: %s from line '%s'\n",
+					printf(__("(mbox) Adding cc: %s from line '%s'\n"),
 						$addr, $_) unless $quiet;
 					push @cc, $addr;
 				}
