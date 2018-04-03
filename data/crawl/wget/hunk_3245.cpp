 		       flag ? "0" : "1");
 	    break;
 	  }
-	case OPT__VERSION:
-	  printf ("GNU Wget %s\n\n", version_string);
-	  printf ("%s", _("\
-Copyright (C) 2003 Free Software Foundation, Inc.\n"));
-	  printf ("%s", _("\
-This program is distributed in the hope that it will be useful,\n\
-but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
-GNU General Public License for more details.\n"));
-	  printf (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"));
-	  exit (0);
-	  break;
 	}
 
       longindex = -1;
