    init_stats();

    while (fgets(mbuf, 256, fp)!=NULL) {
	switch(mbuf[0]) {
	case 'm': /* malloc */
           sscanf(&mbuf[2],"%d:%s", &size, abuf);
	   mi=malloc(sizeof(memitem)); 
	   mi->orig_ptr=(char *)strdup(abuf);
	   mi->size=size;
	   mi->id=size2id(size);
	   mi->my_ptr=(void *)xmalloc(size);
	   hash_insert(mem_table, mi->orig_ptr, mi);
	   mstat.mallocs++;
	   break;
	case 'c': /* calloc */
	   sscanf(&mbuf[2],"%d:%d:%s",&amt ,&size, abuf);
           mi=malloc(sizeof(memitem));
	   mi->orig_ptr=(char *)strdup(abuf);
	   mi->id=size2id(size);
           mi->size=amt*size;
           mi->my_ptr=(void *)xmalloc(amt*size);
	   hash_insert(mem_table, mi->orig_ptr, mi);
	   mstat.callocs++;
	   break;
	case 'f':
	   sscanf(&mbuf[2],"%s", abuf);
	   mem_entry=hash_lookup(mem_table, abuf);		
	   if (mem_entry==NULL) {
		fprintf(stderr,"invalid free!\n");
	   }
	   mi=(memitem *)mem_entry;
	   xfree(mi->my_ptr);
	   mstat.frees++;
	   break;
	default:
