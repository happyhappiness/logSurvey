  * they allow the user access. Password syncronisation is not tackled
  * by digest - just preventing on the wire compromise.
  *
+ * Copyright (c) 2003  Robert Collins  <robertc@squid-cache.org>
  */
 
-#include "config.h"
-#if HAVE_STDIO_H
-#include <stdio.h>
-#endif
-#if HAVE_STDLIB_H
-#include <stdlib.h>
-#endif
-#if HAVE_UNISTD_H
-#include <unistd.h>
-#endif
-#if HAVE_STRING_H
-#include <string.h>
-#endif
-#if HAVE_SYS_TYPES_H
-#include <sys/types.h>
-#endif
-#if HAVE_SYS_STAT_H
-#include <sys/stat.h>
-#endif
-#if HAVE_CRYPT_H
-#include <crypt.h>
-#endif
-
-#include "util.h"
-#include "hash.h"
-#include "rfc2617.h"
-
-static hash_table *hash = NULL;
-static HASHFREE my_free;
-
-typedef struct _user_data {
-    hash_link hash;
-    char *passwd;
-    char *realm;
-} user_data;
+#include "digest_common.h"
+#include "text_backend.h"
 
 static void
-my_free(void *p)
+ParseBuffer(char *buf, RequestData *requestData)
 {
-    user_data *u = p;
-    xfree(u->hash.key);
-    xfree(u->passwd);
-    xfree(u);
+    char *p;
+    requestData->parsed = 0;
+    if ((p = strchr(buf, '\n')) != NULL)
+	*p = '\0';		/* strip \n */
+    if ((requestData->user = strtok(buf, "\"")) == NULL)
+	return;
+    if ((requestData->realm = strtok(NULL, "\"")) == NULL)
+	return;
+    if ((requestData->realm = strtok(NULL, "\"")) == NULL)
+	return;
+    requestData->parsed = -1;
 }
 
 static void
-read_passwd_file(const char *passwdfile, int ha1mode)
+OutputHHA1(RequestData *requestData)
 {
-    FILE *f;
-    char buf[8192];
-    user_data *u;
-    char *user;
-    char *passwd;
-    int passwdha1;
-
-    if (hash != NULL) {
-	hashFreeItems(hash, my_free);
+    requestData->error = 0;
+    GetHHA1(requestData);
+    if (requestData->error) {    
+	printf("ERR\n");
+	return;
     }
-    /* initial setup */
-    hash = hash_create((HASHCMP *) strcmp, 7921, hash_string);
-    if (NULL == hash) {
-	fprintf(stderr, "digest_pw_auth: cannot create hash table\n");
-	exit(1);
-    }
-    f = fopen(passwdfile, "r");
-    while (fgets(buf, 8192, f) != NULL) {
-	if ((buf[0] == '#') || (buf[0] == ' ') || (buf[0] == '\t') ||
-	    (buf[0] == '\n'))
-	    continue;
-	user = strtok(buf, ":\n");
-	passwd = strtok(NULL, ":\n");
-	if ((strlen(user) > 0) && passwd) {
- 	    passwdha1 = (strncmp("{HHA1}", passwd, 6))?0:1;
- 	    if (!ha1mode || passwdha1) {
-		u = xmalloc(sizeof(*u));
-		u->hash.key = xstrdup(user);
-		u->passwd = xstrdup(passwd);
-		hash_join(hash, &u->hash);
-	    } else {
-		/* We cannot accept plaintext passwords when using HA1 encoding,
-		 * as the passwords may be output to cache.log if debugging is on.
-		 */
-		fprintf(stderr, "digest_pw_auth: ignoring %s password for %s\n",
-			"plaintext", user);
- 	    }
-  	}
+    printf("%s\n", requestData->HHA1);
+}
+
+static void
+DoOneRequest(char *buf)
+{
+    RequestData requestData;
+    ParseBuffer (buf, &requestData);
+    if (!requestData.parsed) {
+	printf ("ERR\n");
+	return;
     }
-    fclose(f);
+    OutputHHA1(&requestData);
 }
 
 int
 main(int argc, char **argv)
 {
-    struct stat sb;
-    time_t change_time = 0;
     char buf[256];
-    char *user, *realm, *p, *passwdfile=NULL;
-    user_data *u;
-    HASH HA1;
-    HASHHEX HHA1;
-    int ha1mode=0;
-
     setbuf(stdout, NULL);
-    if(argc == 2){
-        passwdfile = argv[1];
-    }
-    if((argc == 3) && !strcmp("-c", argv[1])){
-        ha1mode=1;
-        passwdfile = argv[2];
-    }
-    if (!passwdfile) {
-        fprintf(stderr, "Usage: digest_pw_auth [OPTIONS] <passwordfile>\n");
-        fprintf(stderr, "  -c   accept HHA1 passwords rather than plaintext in passwordfile\n");
-	exit(1);
-    }
-    if (stat(passwdfile, &sb) != 0) {
-	fprintf(stderr, "cannot stat %s\n", passwdfile);
-	exit(1);
-    }
-    while (fgets(buf, 256, stdin) != NULL) {
-	if ((p = strchr(buf, '\n')) != NULL)
-	    *p = '\0';		/* strip \n */
-	if (stat(passwdfile, &sb) == 0) {
-	    if (sb.st_mtime != change_time) {
-		read_passwd_file(passwdfile, ha1mode);
-		change_time = sb.st_mtime;
-	    }
-	}
-	if (!hash) {
-	    printf("ERR\n");
-	    continue;
-	}
-	if ((user = strtok(buf, "\"")) == NULL) {
-	    printf("ERR\n");
-	    continue;
-	}
-	if ((realm = strtok(NULL, "\"")) == NULL) {
-	    printf("ERR\n");
-	    continue;
-	}
-	if ((realm = strtok(NULL, "\"")) == NULL) {
-	    printf("ERR\n");
-	    continue;
-	}
-	u = (user_data *)hash_lookup(hash, user);
-	if (u == NULL) {
-	    printf("ERR\n");
-	} else {
-
-	    if(! ha1mode )
-            {
-                DigestCalcHA1("md5", user, realm, u->passwd, NULL, NULL, HA1, HHA1);
-                printf("%s\n", HHA1);
-                /* fprintf(stderr, "digest_pw_auth: %s:{HHA1}%s\n", user, HHA1); */
-            }
-            else
-            {
-		printf("%s\n", &u->passwd[6]);
-            }
-	}
-    }
+    ProcessArguments (argc, argv);
+    while (fgets(buf, 256, stdin) != NULL)
+	DoOneRequest (buf);
     exit(0);
 }
