 
 #define MAXCMDLEN 200
 
+/* local helpers to make ctrl+c and ctrl+y working, see below */
+#include <iodef.h>
+#include <libclidef.h>
+#include <ssdef.h>
+
+static int ctrlMask= LIB$M_CLI_CTRLY;
+static int oldCtrlMask;
+static int setupYAstTried= 0;
+static int pidToAbort= 0;
+static int chan= 0;
+
+static void reEnableAst(void) {
+	lib$enable_ctrl (&oldCtrlMask,0);
+}
+
+static astHandler (void) {
+	if (pidToAbort) {
+		sys$forcex (&pidToAbort, 0, SS$_ABORT);
+		pidToAbort= 0;
+	}
+	kill (getpid(),SIGQUIT);
+}
+
+static void tryToSetupYAst(void) {
+	$DESCRIPTOR(inputDsc,"SYS$COMMAND");
+	int	status;
+	struct {
+		short int	status, count;
+		int	dvi;
+	} iosb;
+
+	setupYAstTried++;
+
+	if (!chan) {
+		status= sys$assign(&inputDsc,&chan,0,0);
+		if (!(status&SS$_NORMAL)) {
+			lib$signal(status);
+			return;
+		}
+	}
+	status= sys$qiow (0, chan, IO$_SETMODE|IO$M_CTRLYAST,&iosb,0,0,
+		astHandler,0,0,0,0,0);
+	if (status==SS$_ILLIOFUNC) {
+		sys$dassgn(chan);
+#ifdef	CTRLY_ENABLED_ANYWAY
+		fprintf (stderr, "-warning, CTRL-Y will leave "
+			"sub-process(es) around.\n");
+#else
+		return;
+#endif
+	}
+	if (status==SS$_NORMAL)
+		status= iosb.status;
+	if (!(status&SS$_NORMAL)) {
+		lib$signal(status);
+		return;
+	}
+
+	/* called from AST handler ? */
+	if (setupYAstTried>1)
+		return;
+	if (atexit(reEnableAst))
+		fprintf (stderr, "-warning, you may have to re-enable CTRL-Y"
+			"handling from DCL.\n");
+	status= lib$disable_ctrl (&ctrlMask, &oldCtrlMask);
+	if (!(status&SS$_NORMAL)) {
+		lib$signal(status);
+		return;
+	}
+}
 int
 child_execute_job (argv, child)
      char *argv;
