 
     print 'done'
 
+def parse_blob(parser):
+    global blob_marks
+
+    parser.next()
+    mark = parser.get_mark()
+    parser.next()
+    data = parser.get_data()
+    blob_marks[mark] = data
+    parser.next()
+    return
+
+def parse_commit(parser):
+    global marks, blob_marks, bmarks, parsed_refs
+
+    from_mark = merge_mark = None
+
+    ref = parser[1]
+    parser.next()
+
+    commit_mark = parser.get_mark()
+    parser.next()
+    author = parser.get_author()
+    parser.next()
+    committer = parser.get_author()
+    parser.next()
+    data = parser.get_data()
+    parser.next()
+    if parser.check('from'):
+        from_mark = parser.get_mark()
+        parser.next()
+    if parser.check('merge'):
+        merge_mark = parser.get_mark()
+        parser.next()
+        if parser.check('merge'):
+            die('octopus merges are not supported yet')
+
+    files = {}
+
+    for line in parser:
+        if parser.check('M'):
+            t, m, mark_ref, path = line.split(' ')
+            mark = int(mark_ref[1:])
+            f = { 'mode' : hgmode(m), 'data' : blob_marks[mark] }
+        elif parser.check('D'):
+            t, path = line.split(' ')
+            f = { 'deleted' : True }
+        else:
+            die('Unknown file command: %s' % line)
+        files[path] = f
+
+    def getfilectx(repo, memctx, f):
+        of = files[f]
+        if 'deleted' in of:
+            raise IOError
+        is_exec = of['mode'] == 'x'
+        is_link = of['mode'] == 'l'
+        return context.memfilectx(f, of['data'], is_link, is_exec, None)
+
+    repo = parser.repo
+
+    user, date, tz = author
+    extra = {}
+
+    if committer != author:
+        extra['committer'] = "%s %u %u" % committer
+
+    if from_mark:
+        p1 = repo.changelog.node(mark_to_rev(from_mark))
+    else:
+        p1 = '\0' * 20
+
+    if merge_mark:
+        p2 = repo.changelog.node(mark_to_rev(merge_mark))
+    else:
+        p2 = '\0' * 20
+
+    ctx = context.memctx(repo, (p1, p2), data,
+            files.keys(), getfilectx,
+            user, (date, tz), extra)
+
+    node = repo.commitctx(ctx)
+
+    rev = repo[node].rev()
+
+    parsed_refs[ref] = node
+
+    marks.new_mark(rev, commit_mark)
+
+def parse_reset(parser):
+    ref = parser[1]
+    parser.next()
+    # ugh
+    if parser.check('commit'):
+        parse_commit(parser)
+        return
+    if not parser.check('from'):
+        return
+    from_mark = parser.get_mark()
+    parser.next()
+
+    node = parser.repo.changelog.node(mark_to_rev(from_mark))
+    parsed_refs[ref] = node
+
+def parse_tag(parser):
+    name = parser[1]
+    parser.next()
+    from_mark = parser.get_mark()
+    parser.next()
+    tagger = parser.get_author()
+    parser.next()
+    data = parser.get_data()
+    parser.next()
+
+    # nothing to do
+
+def do_export(parser):
+    global parsed_refs, bmarks
+
+    parser.next()
+
+    for line in parser.each_block('done'):
+        if parser.check('blob'):
+            parse_blob(parser)
+        elif parser.check('commit'):
+            parse_commit(parser)
+        elif parser.check('reset'):
+            parse_reset(parser)
+        elif parser.check('tag'):
+            parse_tag(parser)
+        elif parser.check('feature'):
+            pass
+        else:
+            die('unhandled export command: %s' % line)
+
+    for ref, node in parsed_refs.iteritems():
+        if ref.startswith('refs/heads/branches'):
+            pass
+        elif ref.startswith('refs/heads/'):
+            bmark = ref[len('refs/heads/'):]
+            if bmark in bmarks:
+                old = bmarks[bmark].hex()
+            else:
+                old = ''
+            if not bookmarks.pushbookmark(parser.repo, bmark, old, node):
+                continue
+        elif ref.startswith('refs/tags/'):
+            tag = ref[len('refs/tags/'):]
+            parser.repo.tag([tag], node, None, True, None, {})
+        print "ok %s" % ref
+
+    print
+
 def main(args):
-    global prefix, dirname, marks, branches, bmarks
+    global prefix, dirname, branches, bmarks
+    global marks, blob_marks, parsed_refs
 
     alias = args[1]
     url = args[2]
