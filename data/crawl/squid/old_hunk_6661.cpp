                fprintf(stderr,"invalid realloc (%s)!\n",p);
		break;
           }
	   mi=(memitem *)mem_entry;
	   xfree(mi->my_ptr);
           strcpy(mi->orig_ptr,abuf);
	   p=strtok(NULL,"\n");
	   if (!p) badformat();
	   mi->my_ptr=(char *)xmalloc(atoi(p)); 
	   mstat.reallocs++;
	   break;
	case 'f':
	   p=strtok(&mbuf[2],"\n");
	   mem_entry=hash_lookup(mem_table, p);		
	   if (mem_entry==NULL) {
		fprintf(stderr,"invalid free (%s)!\n",p);
		break;
	   }
	   mi=(memitem *)mem_entry;
	   xfree(mi->my_ptr);
	   hash_unlink(mem_table, mem_entry, 1);
	   mstat.frees++;
	   break;
