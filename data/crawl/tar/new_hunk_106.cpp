	    }
	  expect = 'T';
	  break;

	case 'T':
	  if (expect != 'T')
	    {
	      ERROR ((0, 0,
		      _("Malformed dumpdir: 'T' not preceeded by 'R'")));
	      return false;
	    }
	  if (p[1] == 0 && !has_tempdir)
	    {
	      ERROR ((0, 0,
