endif::git-format-patch[]

-O<orderfile>::
	Output the patch in the order specified in the
	<orderfile>, which has one shell glob pattern per line.
	This overrides the `diff.orderFile` configuration variable
	(see linkgit:git-config[1]).  To cancel `diff.orderFile`,
	use `-O/dev/null`.

ifndef::git-format-patch[]
-R::