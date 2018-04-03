             check_pw = 1;
             break;
         case 'g':
-            grents[i] = calloc(strlen(optarg) + 1, sizeof(char));
-            strcpy(grents[i], optarg);
-            if (i < MAX_GROUP) {
-                i++;
-            } else {
-                fprintf(stderr,
-                        "Exceeded maximum number of allowed groups (%i)\n", i);
-                exit(1);
-            }
+	    grents = realloc(grents, sizeof(*grents) * (ngroups+1));
+            grents[ngroups++] = optarg;
             break;
         case '?':
             if (xisprint(optopt)) {
-
                 fprintf(stderr, "Unknown option '-%c'.\n", optopt);
             } else {
                 fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
