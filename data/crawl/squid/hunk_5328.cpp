 	user = strtok(buf, ":\n");
 	passwd = strtok(NULL, ":\n");
 	if ((strlen(user) > 0) && passwd) {
-	    u = xmalloc(sizeof(*u));
-	    u->hash.key = xstrdup(user);
-	    u->passwd = xstrdup(passwd);
-	    hash_join(hash, &u->hash);
-	}
+ 	    passwdha1 = (strncmp("{HHA1}", passwd, 6))?0:1;
+ 	    if (!ha1mode || passwdha1) {
+		u = xmalloc(sizeof(*u));
+		u->hash.key = xstrdup(user);
+		u->passwd = xstrdup(passwd);
+		hash_join(hash, &u->hash);
+	    } else {
+		/* We cannot accept plaintext passwords when using HA1 encoding,
+		 * as the passwords may be output to cache.log if debugging is on.
+		 */
+		fprintf(stderr, "digest_pw_auth: ignoring %s password for %s\n",
+			"plaintext", user);
+ 	    }
+  	}
     }
     fclose(f);
 }
