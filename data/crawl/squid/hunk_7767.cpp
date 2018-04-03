 
 /* -------------------------------------------------------------------------- */
 
-/* free whole entry */
-void storeFreeEntry(e)
-     StoreEntry *e;
-{
-    int i;
-
-    if (!e)
-	fatal_dump("storeFreeEntry: NULL Entry");
-
-    debug(20, 3, "storeFreeEntry: Freeing %s\n", e->key);
-
-    if (e->mem_obj) {
-	destroy_MemObjectData(e->mem_obj);
-	e->mem_obj->data = NULL;
-    }
-    meta_data.url_strings -= strlen(e->url);
-    safe_free(e->url);
-    if (BIT_TEST(e->flag, KEY_URL))
-	e->key = NULL;
-    else
-	safe_free(e->key);
-    if (e->mem_obj) {
-	safe_free(e->mem_obj->mime_hdr);
-	/* Leave an unzeroed pointer to the abort msg for posterity */
-	safe_free(e->mem_obj->e_abort_msg);
-	safe_free(e->mem_obj->pending);
-	/* look up to free client_list */
-	if (e->mem_obj->client_list) {
-	    for (i = 0; i < e->mem_obj->client_list_size; ++i)
-		safe_free(e->mem_obj->client_list[i]);
-	    safe_free(e->mem_obj->client_list);
-	}
-    }
-    destroy_StoreEntry(e);
-}
-
 static char *time_describe(t)
      time_t t;
 {
