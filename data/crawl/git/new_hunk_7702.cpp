	output without getting confused e.g. by values that
	contain line breaks.

--get-colorbool name [stdout-is-tty]::

	Find the color setting for `name` (e.g. `color.diff`) and output
	"true" or "false".  `stdout-is-tty` should be either "true" or
	"false", and is taken into account when configuration says
	"auto".  If `stdout-is-tty` is missing, then checks the standard
	output of the command itself, and exits with status 0 if color
	is to be used, or exits with status 1 otherwise.

--get-color name default::

	Find the color configured for `name` (e.g. `color.diff.new`) and
