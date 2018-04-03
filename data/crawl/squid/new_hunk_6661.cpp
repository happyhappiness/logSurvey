                fprintf(stderr,"invalid realloc (%s)!\n",p);
		break;
           }
	   mi=(memitem *)(mem_entry->item);
	   assert(mi->pool);
	   assert(mi->my_ptr);
	   xmemFree(mi); /* xfree(mi->my_ptr); */
	   size2id(atoi(p),mi);   /* we don't need it here I guess? */
           strcpy(mi->orig_ptr,abuf);
	   p=strtok(NULL,"\n");
	   if (!p) badformat();
	   mi->my_ptr= xmemAlloc(mi); /* (char *)xmalloc(atoi(p)); */
	   assert(mi->my_ptr);
	   mstat.reallocs++;
	   break;
	case 'f':
	   p=strtok(&mbuf[2],"\n");
	   mem_entry=hash_lookup(mem_table, p);		
	   if (mem_entry==NULL) {
		if (p[0]!='0')
		fprintf(stderr,"invalid free (%s) at line %d!\n",p,a);
		break;
	   }
	   mi=(memitem *)(mem_entry->item);
	   assert(mi->pool);
	   assert(mi->my_ptr);
	   xmemFree(mi); /* xfree(mi->my_ptr); */ 
	   hash_unlink(mem_table, mem_entry, 1);
	   mstat.frees++;
	   break;
