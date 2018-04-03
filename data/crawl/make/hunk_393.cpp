+2013-05-13  Paul Smith  <psmith@gnu.org>
+
+	* makeint.h (TRACE_NONE, TRACE_RULE, TRACE_DIRECTORY): Define
+	constants for the trace mode.
+	* main.c: Add new --trace mode parsing.
+	(decode_trace_flags): New function.
+	(decode_switches): Call it.
+	(define_makeflags): Fix a bug with long-name options.
+	* misc.c (fatal): Remove special output-sync handling.
+	* make.1: Document new --trace mode flags.
+	* doc/make.texi (Options Summary): Ditto.
+
 2013-05-11  Eli Zaretskii  <eliz@gnu.org>
 
 	* job.c (child_out): Output the newline following the message
