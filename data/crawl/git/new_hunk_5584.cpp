+
Supported if the helper has the "fetch" capability.

'push' +<src>:<dst>::
	Pushes the given <src> commit or branch locally to the
	remote branch described by <dst>.  A batch sequence of
	one or more push commands is terminated with a blank line.
Zero or more protocol options may be entered after the last 'push'
command, before the batch's terminating blank line.
When the push is complete, outputs one or more 'ok <dst>' or
'error <dst> <why>?' lines to indicate success or failure of
each pushed ref.  The status report output is terminated by
a blank line.  The option field <why> may be quoted in a C
style string if it contains an LF.
Supported if the helper has the "push" capability.

If a fatal error occurs, the program writes the error message to
stderr and exits. The caller should expect that a suitable error
message has been printed if the child closes the connection without
