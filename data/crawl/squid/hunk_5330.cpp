 	if (u == NULL) {
 	    printf("ERR\n");
 	} else {
-	    DigestCalcHA1("md5", user, realm, u->passwd, NULL, NULL, HA1, HHA1);
-	    printf("%s\n", HHA1);
+
+	    if(! ha1mode )
+            {
+                DigestCalcHA1("md5", user, realm, u->passwd, NULL, NULL, HA1, HHA1);
+                printf("%s\n", HHA1);
+                /* fprintf(stderr, "digest_pw_auth: %s:{HHA1}%s\n", user, HHA1); */
+            }
+            else
+            {
+		printf("%s\n", &u->passwd[6]);
+            }
 	}
     }
     exit(0);
