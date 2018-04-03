		    }
		}

	      g->file = g->file->prev;
	      if (stop || g->file == 0)
		{
		  /* This goal is finished.  Remove it from the chain.  */
		  if (lastgoal == 0)
		    goals = g->next;
