                 for (i = 0; i < n; i++) {
                     if (answers[i].type == RFC1035_TYPE_A) {
                         struct in_addr a;
+                        char ipa_str[sizeof(a)];
                         memcpy(&a, answers[i].rdata, 4);
-                        printf("A\t%d\t%s\n", answers[i].ttl, inet_ntoa(a));
+                        printf("A\t%d\t%s\n", answers[i].ttl, inet_ntop(AF_INET,&a,tmp,sizeof(a)));
                     } else if (answers[i].type == RFC1035_TYPE_PTR) {
                         char ptr[128];
                         strncpy(ptr, answers[i].rdata, answers[i].rdlength);
