 	return result;
 }
 
-/* Generic functions for using commit walkers */
-
-#ifndef NO_CURL /* http fetch is the only user */
-static int fetch_objs_via_walker(struct transport *transport,
-				 int nr_objs, const struct ref **to_fetch)
-{
-	char *dest = xstrdup(transport->url);
-	struct walker *walker = transport->data;
-	char **objs = xmalloc(nr_objs * sizeof(*objs));
-	int i;
-
-	walker->get_all = 1;
-	walker->get_tree = 1;
-	walker->get_history = 1;
-	walker->get_verbosely = transport->verbose >= 0;
-	walker->get_recover = 0;
-
-	for (i = 0; i < nr_objs; i++)
-		objs[i] = xstrdup(sha1_to_hex(to_fetch[i]->old_sha1));
-
-	if (walker_fetch(walker, nr_objs, objs, NULL, NULL))
-		die("Fetch failed.");
-
-	for (i = 0; i < nr_objs; i++)
-		free(objs[i]);
-	free(objs);
-	free(dest);
-	return 0;
-}
-#endif /* NO_CURL */
-
-static int disconnect_walker(struct transport *transport)
-{
-	struct walker *walker = transport->data;
-	if (walker)
-		walker_free(walker);
-	return 0;
-}
-
 #ifndef NO_CURL
 static int curl_transport_push(struct transport *transport, int refspec_nr, const char **refspec, int flags)
 {
