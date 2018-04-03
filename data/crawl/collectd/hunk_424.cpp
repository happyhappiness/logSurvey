 	CHECK(handle);
 
 	printf("libiptc v%s. %u bytes.\n",
-	       IPTABLES_VERSION, handle->entries->size);
+	       XTABLES_VERSION, handle->entries->size);
 	printf("Table `%s'\n", handle->info.name);
 	printf("Hooks: pre/in/fwd/out/post = %u/%u/%u/%u/%u\n",
 	       handle->info.hook_entry[HOOK_PRE_ROUTING],
