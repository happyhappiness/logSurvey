
      ENULLLOOP (d, readdir (dir->dirstream));
      if (d == 0)
        break;

#if defined(VMS) && defined(HAVE_DIRENT_H)
      /* In VMS we get file versions too, which have to be stripped off */
