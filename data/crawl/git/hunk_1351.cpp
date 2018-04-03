             )
 
         if options.show_env:
-            sys.stderr.write('Environment values:\n')
-            for (k, v) in sorted(environment.get_values().items()):
-                sys.stderr.write('    %s : %r\n' % (k, v))
-            sys.stderr.write('\n')
+            show_env(environment, sys.stderr)
 
         if options.stdout or environment.stdout:
             mailer = OutputMailer(sys.stdout)
         else:
             mailer = choose_mailer(config, environment)
 
+        must_check_setup = os.environ.get('GIT_MULTIMAIL_CHECK_SETUP')
+        if must_check_setup == '':
+            must_check_setup = False
+        if options.check_ref_filter:
+            check_ref_filter(environment)
+        elif must_check_setup:
+            check_setup(environment)
         # Dual mode: if arguments were specified on the command line, run
         # like an update hook; otherwise, run as a post-receive hook.
-        if args:
+        elif args:
             if len(args) != 3:
                 parser.error('Need zero or three non-option arguments')
             (refname, oldrev, newrev) = args
+            environment.get_logger().debug(
+                "run_as_update_hook: refname=%s, oldrev=%s, newrev=%s, force_send=%s" %
+                (refname, oldrev, newrev, options.force_send))
             run_as_update_hook(environment, mailer, refname, oldrev, newrev, options.force_send)
         else:
             run_as_post_receive_hook(environment, mailer)
     except ConfigurationException:
         sys.exit(sys.exc_info()[1])
+    except SystemExit:
+        raise
     except Exception:
         t, e, tb = sys.exc_info()
         import traceback
-        sys.stdout.write('\n')
-        sys.stdout.write('Exception \'' + t.__name__ +
-                         '\' raised. Please report this as a bug to\n')
-        sys.stdout.write('https://github.com/git-multimail/git-multimail/issues\n')
-        sys.stdout.write('with the information below:\n\n')
-        sys.stdout.write('git-multimail version ' + get_version() + '\n')
-        sys.stdout.write('Python version ' + sys.version + '\n')
-        traceback.print_exc(file=sys.stdout)
+        sys.stderr.write('\n')  # Avoid mixing message with previous output
+        msg = (
+            'Exception \'' + t.__name__ +
+            '\' raised. Please report this as a bug to\n'
+            'https://github.com/git-multimail/git-multimail/issues\n'
+            'with the information below:\n\n'
+            'git-multimail version ' + get_version() + '\n'
+            'Python version ' + sys.version + '\n' +
+            traceback.format_exc())
+        try:
+            environment.get_logger().error(msg)
+        except:
+            sys.stderr.write(msg)
         sys.exit(1)
 
 if __name__ == '__main__':
