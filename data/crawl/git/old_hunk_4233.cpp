	Instead of printing both the SHA-1 and the name, print only
	the name.  If given with --tags the usual tag prefix of
	"tags/" is also omitted from the name, matching the output
	of 'git-describe' more closely.  This option
	cannot be combined with --stdin.

--no-undefined::
	Die with error code != 0 when a reference is undefined,
