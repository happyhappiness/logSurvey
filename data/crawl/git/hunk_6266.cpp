 					memcpy(save, b + brk, sf);
 					b[brk + sf - 1] = b[brk - 1];
 					memcpy(b + brk - 1, suffix, sf);
-					safe_write(err, b, brk + sf);
+					fprintf(stderr, "%.*s", brk + sf, b);
 					memcpy(b + brk, save, sf);
 					len -= brk;
 				} else {
 					int l = brk ? brk : len;
-					safe_write(err, b, l);
+					fprintf(stderr, "%.*s", l, b);
 					len -= l;
 				}
 
