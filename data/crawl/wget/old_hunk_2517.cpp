      fprintf (stderr, "%011o %011o %011o\n", this_segment, address, stkl);
#endif
      if (pseg == 0)
	break;
      stkl = stkl - pseg;
      ssptr = (struct stack_segment_linkage *) stkl;
      size = ssptr->sssize;
