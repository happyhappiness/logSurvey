 	(i >> 16) & 255,
 	(i >> 8) & 255,
 	i & 255);
-    printf("rfc1035BuildPTRQuery: {%s}\n", rev);
     h.id = rfc1035Qid();
     h.qr = 0;
     h.rd = 1;