 			printf("Value not found for \"%s\"\n", argv[2]);
 			goto exit1;
 		}
+	} else if (!strcmp(argv[1], "iterate")) {
+		git_config(iterate_cb, NULL);
+		goto exit0;
 	}
 
 	die("%s: Please check the syntax and the function name", argv[0]);
