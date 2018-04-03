	Output only the names of config variables for `--list` or
	`--get-regexp`.

--show-origin::
	Augment the output of all queried config options with the
	origin type (file, standard input, blob, command line) and
	the actual origin (config file path, ref, or blob id if
	applicable).

--get-colorbool name [stdout-is-tty]::

	Find the color setting for `name` (e.g. `color.diff`) and output
