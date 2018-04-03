     void *p = NULL;
     if (!empty_stack(&thing->free_page_stack)) {
 	p = pop(&thing->free_page_stack);
-	if (p == NULL)
-	    fatal_dump("get_free_thing: NULL pointer?");
+	assert(p != NULL);
     } else {
 	p = xmalloc(thing->page_size);
 	thing->total_pages_allocated++;
