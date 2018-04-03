             do_list(parser)
         elif parser.check('import'):
             do_import(parser)
+        elif parser.check('export'):
+            do_export(parser)
         else:
             die('unhandled command: %s' % line)
         sys.stdout.flush()