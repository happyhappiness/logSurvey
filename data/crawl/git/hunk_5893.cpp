 					case ECONNABORTED:
 						continue;
 					default:
-						die("accept returned %s", strerror(errno));
+						die_errno("accept returned");
 					}
 				}
 				handle(incoming, (struct sockaddr *)&ss, sslen);
