		}
	    break;
	  }
	case OPT__PARENT:
	case OPT__CLOBBER:
	  {
	    /* The wgetrc commands are named noparent and noclobber,
	       so we must revert the meaning of the cmdline options
	       before passing the value to setoptval.  */
	    int flag = 1;
	    if (optarg)
	      flag = (*optarg == '1' || TOLOWER (*optarg) == 'y'
		      || (TOLOWER (optarg[0]) == 'o'
			  && TOLOWER (optarg[1]) == 'n'));
	    setoptval (opt->type == OPT__PARENT ? "noparent" : "noclobber",
		       flag ? "0" : "1");
	    break;
	  }
	case OPT__VERSION:
	  printf ("GNU Wget %s\n\n", version_string);
	  printf ("%s", _("\
Copyright (C) 2003 Free Software Foundation, Inc.\n"));
	  printf ("%s", _("\
This program is distributed in the hope that it will be useful,\n\
but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
GNU General Public License for more details.\n"));
	  printf (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"));
	  exit (0);
	  break;
	}

      longindex = -1;
    }

  /* All user options have now been processed, so it's now safe to do
