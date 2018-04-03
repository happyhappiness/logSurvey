 		}
 		refs[j] = NULL;
 		ref_nr = j;
-		for (j = 0; refs[j]; j++)
-			printf("ref: %s\n", refs[j]);
 	}
 
 	signal(SIGINT, unlock_pack_on_signal);