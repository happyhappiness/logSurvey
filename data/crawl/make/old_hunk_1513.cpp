
      for (i = 0; v->searchpath[i] != 0; ++i)
	printf ("%s%c", v->searchpath[i],
		v->searchpath[i + 1] == 0 ? '\n' : ':');
    }

  if (vpaths == 0)
