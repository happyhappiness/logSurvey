
      if (status == 0)
	{
	  ERROR ((0, 0, _("%d garbage bytes ignored at end of archive"),
		  (int) ((record_size - left) % BLOCKSIZE)));
	  break;
	}

