 			}
 			printf("\n");
 			fflush(stdout);
+		} else if (!prefixcmp(buf.buf, "option ")) {
+			char *name = buf.buf + strlen("option ");
+			char *value = strchr(name, ' ');
+			int result;
+
+			if (value)
+				*value++ = '\0';
+			else
+				value = "true";
+
+			result = set_option(name, value);
+			if (!result)
+				printf("ok\n");
+			else if (result < 0)
+				printf("error invalid value\n");
+			else
+				printf("unsupported\n");
+			fflush(stdout);
+
 		} else if (!strcmp(buf.buf, "capabilities")) {
 			printf("fetch\n");
+			printf("option\n");
 			printf("\n");
 			fflush(stdout);
 		} else {
