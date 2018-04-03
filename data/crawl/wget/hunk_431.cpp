 
 /*--------------------------------------------------------------------*/
 
-/* vms_vers()
+/* vms_basename()
+ *
+ *    Extract the basename from a VMS file spec.
+ */
+
+char *vms_basename( char *file_spec)
+{
+    /* Static storage for NAM[L], and so on. */
+
+    static struct NAM_STRUCT nam;
+    static char exp_name[ NAM_MAXRSS+ 1];
+    static char res_name[ NAM_MAXRSS+ 1];
+
+    struct FAB fab;
+    int status;
+
+    /* Set up the FAB and NAM[L] blocks. */
+
+    fab = cc$rms_fab;                   /* Initialize FAB. */
+    nam = CC_RMS_NAM;                   /* Initialize NAM[L]. */
+
+    fab.FAB_NAM = &nam;                 /* FAB -> NAM[L] */
+
+#ifdef NAML$C_MAXRSS
+
+    fab.fab$l_dna = (char *) -1;    /* Using NAML for default name. */
+    fab.fab$l_fna = (char *) -1;    /* Using NAML for file name. */
+
+#endif /* def NAML$C_MAXRSS */
+
+    /* Arg name and length. */
+    FAB_OR_NAML( fab, nam).FAB_OR_NAML_FNA = file_spec;
+    FAB_OR_NAML( fab, nam).FAB_OR_NAML_FNS = strlen( file_spec);
+
+    nam.NAM_ESA = exp_name;         /* Expanded name. */
+    nam.NAM_ESS = NAM_MAXRSS;       /* Max length. */
+    nam.NAM_RSA = res_name;         /* Resulting name. */
+    nam.NAM_RSS = NAM_MAXRSS;       /* Max length. */
+
+    nam.NAM_NOP = NAM_M_SYNCHK;     /* Syntax-only analysis. */
+
+    /* Parse the file name. */
+    status = sys$parse( &fab);      /* What could go wrong? */
+
+    nam.NAM_L_NAME[ nam.NAM_B_NAME] = '\0';
+
+    return nam.NAM_L_NAME;
+}
+
+/*--------------------------------------------------------------------*/
+
+/* 2009-09-07 SMS.
+ *
+ *       vms_getpass().
+ *
+ *    VMS-specific substitute for GNU getpass().
+ *
+ *       Returns passpord in locally allocated string.
+ */
+
+/* Terminal characteristics buffer structure. */
+typedef struct
+{
+    char class;
+    char type;
+    short page_width;
+    int basic_chars;    /* (The high eight bits are page length.) */
+    int extended_chars;
+} term_chars_t;
+
+/* Enable/disable terminal echo. */
+
+int vms_set_term_echo( int able)
+{
+    int sts;
+    int sts2;
+    short term_chan;
+    $DESCRIPTOR( term_dscr, "SYS$COMMAND");
+    term_chars_t term_chars;
+    static int initial_echo = -1;
+
+    /* Open a channel to the terminal device. */
+    sts = sys$assign( &term_dscr,       /* Terminal device name. */
+                      &term_chan,       /* Channel. */
+                      0,                /* Access mode. */
+                      0);               /* Mailbox. */
+
+    /* Return immediately on failure. */
+    if ((sts& STS$M_SEVERITY) != STS$K_SUCCESS)
+    {
+        errno = EVMSERR;
+        vaxc$errno = sts;
+        return -1;
+    }
+
+    /* Get the current terminal characteristics (mode). */
+    sts = sys$qiow( 0,                          /* Event flag. */
+                    term_chan,                  /* Channel. */
+                    IO$_SENSEMODE,              /* Function. */
+                    0,                          /* IOSB. */
+                    0,                          /* AST address. */
+                    0,                          /* AST parameter. */
+                    &term_chars,                /* P1 = Buffer address. */
+                    sizeof term_chars,          /* P2 = Buffer size. */
+                    0, 0, 0, 0);                /* P3-P6 not used. */
+
+    if ((sts& STS$M_SEVERITY) != STS$K_SUCCESS)
+    {
+        errno = EVMSERR;
+        vaxc$errno = sts;
+    }
+    else if (term_chars.class != DC$_TERM)
+    {
+        errno = ENOTTY;
+    }
+    else
+    {
+        /* Save the initial echo state, to allow proper restoration. */
+        if (initial_echo < 0)
+        {
+            initial_echo = ((term_chars.basic_chars& TT$M_NOECHO) == 0);
+        }
+
+        if (able < 0)
+        {
+           if (initial_echo)
+           {
+               /* Was initially enabled. */
+               able = 1;
+           }
+           else
+           {
+               /* Was initially disabled. */
+               able = 0;
+           }
+        }
 
+        if (able == 0)
+        {
+            /* Disable.  Set the no-echo bit. */
+            term_chars.basic_chars |= TT$M_NOECHO;
+        }
+        else
+        {
+            /* Enable.  Clear the no-echo bit. */
+            term_chars.basic_chars &= ~TT$M_NOECHO;
+        }
+
+        /* Set the terminal characteristics (mode). */
+        sts = sys$qiow( 0,                      /* Event flag. */
+                        term_chan,              /* Channel. */
+                        IO$_SETMODE,            /* Function. */
+                        0,                      /* IOSB. */
+                        0,                      /* AST address. */
+                        0,                      /* AST parameter. */
+                        &term_chars,            /* P1 = Buffer address. */
+                        sizeof term_chars,      /* P2 = Buffer size. */
+                        0, 0, 0, 0);            /* P3-P6 not used. */
+
+        if ((sts& STS$M_SEVERITY) != STS$K_SUCCESS)
+        {
+            errno = EVMSERR;
+            vaxc$errno = sts;
+        }
+        else
+        {
+            /* All is well. */
+            sts = 0;
+        }
+    }
+
+    /* Close the channel to the terminal device. */
+    sts2 = sys$dassgn( term_chan);              /* Channel. */
+    if ((sts2& STS$M_SEVERITY) != STS$K_SUCCESS)
+    {
+        /* If all was not well, leave the old error codes as were. */
+        if (sts == 0)
+        {
+            /* All was well, but DASSGN failed. */
+            errno = EVMSERR;
+            vaxc$errno = sts2;
+            sts = sts2;
+        }
+    }
+    return sts;
+}
+
+static char pw_buf[ PASS_MAX+ 1];
+
+char *vms_getpass( const char *prompt)
+{
+    char *ret;
+    int sts;
+    FILE *sdc;
+
+    ret = NULL;
+
+    sdc = fopen( "SYS$COMMAND", "r");
+    if (sdc != NULL)
+    {
+        sts = vms_set_term_echo( 0);
+        if (sts == 0)
+        {
+            /* Read password string. */
+            if (sts == 0)
+            {
+                fprintf( stdout, "%s", prompt);
+                sts = fread( pw_buf, 1, PASS_MAX, sdc);
+                if ((sts > 0) && (pw_buf[ sts- 1]) == '\n')
+                {
+                    pw_buf[ --sts] = '\0';
+                }
+                else
+                {
+                    pw_buf[ sts = '\0'];
+                }
+                ret = pw_buf;
+            }
+            sts = vms_set_term_echo( -1);
+        }
+        fclose( sdc);
+    }
+    return ret;
+}    
+
+/*--------------------------------------------------------------------*/
+
+/* vms_vers()
+  
       Returns (run-time) VMS version string.
 */
 
