 */
extern int create_tempfile(struct tempfile *tempfile, const char *path);


/*
 * mks_tempfile functions
 *
 * The following functions attempt to create and open temporary files
 * with names derived automatically from a template, in the manner of
 * mkstemps(), and arrange for them to be deleted if the program ends
 * before they are deleted explicitly. There is a whole family of such
 * functions, named according to the following pattern:
 *
 *     x?mks_tempfile_t?s?m?()
 *
 * The optional letters have the following meanings:
 *
 *   x - die if the temporary file cannot be created.
 *
 *   t - create the temporary file under $TMPDIR (as opposed to
 *       relative to the current directory). When these variants are
 *       used, template should be the pattern for the filename alone,
 *       without a path.
 *
 *   s - template includes a suffix that is suffixlen characters long.
 *
 *   m - the temporary file should be created with the specified mode
 *       (otherwise, the mode is set to 0600).
 *
 * None of these functions modify template. If the caller wants to
 * know the (absolute) path of the file that was created, it can be
 * read from tempfile->filename.
 *
 * On success, the functions return a file descriptor that is open for
 * writing the temporary file. On errors, they return -1 and set errno
 * appropriately (except for the "x" variants, which die() on errors).
 */

/* See "mks_tempfile functions" above. */
extern int mks_tempfile_sm(struct tempfile *tempfile,
			   const char *template, int suffixlen, int mode);

/* See "mks_tempfile functions" above. */
static inline int mks_tempfile_s(struct tempfile *tempfile,
				 const char *template, int suffixlen)
{
	return mks_tempfile_sm(tempfile, template, suffixlen, 0600);
}

/* See "mks_tempfile functions" above. */
static inline int mks_tempfile_m(struct tempfile *tempfile,
				 const char *template, int mode)
{
	return mks_tempfile_sm(tempfile, template, 0, mode);
}

/* See "mks_tempfile functions" above. */
static inline int mks_tempfile(struct tempfile *tempfile,
			       const char *template)
{
	return mks_tempfile_sm(tempfile, template, 0, 0600);
}

/* See "mks_tempfile functions" above. */
extern int mks_tempfile_tsm(struct tempfile *tempfile,
			    const char *template, int suffixlen, int mode);

/* See "mks_tempfile functions" above. */
static inline int mks_tempfile_ts(struct tempfile *tempfile,
				  const char *template, int suffixlen)
{
	return mks_tempfile_tsm(tempfile, template, suffixlen, 0600);
}

/* See "mks_tempfile functions" above. */
static inline int mks_tempfile_tm(struct tempfile *tempfile,
				  const char *template, int mode)
{
	return mks_tempfile_tsm(tempfile, template, 0, mode);
}

/* See "mks_tempfile functions" above. */
static inline int mks_tempfile_t(struct tempfile *tempfile,
				 const char *template)
{
	return mks_tempfile_tsm(tempfile, template, 0, 0600);
}

/* See "mks_tempfile functions" above. */
extern int xmks_tempfile_m(struct tempfile *tempfile,
			   const char *template, int mode);

/* See "mks_tempfile functions" above. */
static inline int xmks_tempfile(struct tempfile *tempfile,
				const char *template)
{
	return xmks_tempfile_m(tempfile, template, 0600);
}

/*
 * Associate a stdio stream with the temporary file (which must still
 * be open). Return `NULL` (*without* deleting the file) on error. The