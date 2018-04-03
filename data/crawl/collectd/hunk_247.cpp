 			continue;
 		}
 
-		printf ("%s\n", id);
+		/* skip over the (empty) hostname and following '/' */
+		printf ("\t%s\n", id + 1);
 	}
 
 	if (ret_ident != NULL)