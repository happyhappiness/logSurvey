     ref = parser[1]
     parser.next()
 
-    if ref != 'refs/heads/master':
-        die("bzr doesn't support multiple branches; use 'master'")
-
     # ugh
     if parser.check('commit'):
         parse_commit(parser)
