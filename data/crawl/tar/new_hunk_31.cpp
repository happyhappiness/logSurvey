   zero, otherwise the fgetfileconat is used against correct file descriptor */
void
xattrs_selinux_get (int parentfd, char const *file_name,
                    struct tar_stat_info *st, int fd)
{
  if (selinux_context_option > 0)
    {
#if HAVE_SELINUX_SELINUX_H != 1
      static int done = 0;
      if (!done)
        WARN ((0, 0, _("SELinux support is not available")));
      done = 1;
#else
      int result = fd ?
	            fgetfilecon (fd, &st->cntx_name)
                    : lgetfileconat (parentfd, file_name, &st->cntx_name);

      if (result == -1 && errno != ENODATA && errno != ENOTSUP)
        call_arg_warn (fd ? "fgetfilecon" : "lgetfileconat", file_name);
#endif
    }
}

void
xattrs_selinux_set (struct tar_stat_info const *st,
                    char const *file_name, char typeflag)
{
  if (selinux_context_option > 0)
    {
#if HAVE_SELINUX_SELINUX_H != 1
      static int done = 0;
      if (!done)
        WARN ((0, 0, _("SELinux support is not available")));
      done = 1;
#else
      const char *sysname = "setfilecon";
      int ret;

      if (!st->cntx_name)
        return;

      if (typeflag != SYMTYPE)
        {
          ret = setfileconat (chdir_fd, file_name, st->cntx_name);
          sysname = "setfileconat";
        }
      else
        {
          ret = lsetfileconat (chdir_fd, file_name, st->cntx_name);
          sysname = "lsetfileconat";
        }

      if (ret == -1)
        WARNOPT (WARN_XATTR_WRITE,
		 (0, errno,
		  _("%s: Cannot set SELinux context for file '%s'"),
		  sysname, file_name));
