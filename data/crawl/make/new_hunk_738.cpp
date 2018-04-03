2005-06-27  Paul D. Smith  <psmith@gnu.org>

	* scripts/options/dash-W: Use 'echo >>' instead of touch to update
	files.
	* scripts/features/reinvoke: Rewrite to be safer on systems with
	subsecond timestamps.
	* scripts/features/patternrules: False exits with different error
	codes on different systems (for example, Linux => 1, Solaris => 255).

	* scripts/options/dash-W: Set the timestamp to foo.x in the future,
	to be sure it will be considered updated when it's remade.

