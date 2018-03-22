If this behavior is not wanted, use @option{--ignore-command-error}:

@table @option
@item --ignore-command-error
Ignore exit codes of subprocesses.  Notice that if the program
exits on signal or otherwise terminates abnormally, the error message
will be printed even if this option is used.

@item --no-ignore-command-error
Cancel the effect of any previous @option{--ignore-command-error}
option. This option is useful if you have set
