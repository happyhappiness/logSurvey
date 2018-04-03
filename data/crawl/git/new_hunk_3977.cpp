
    final = []
    for path, fid in files.iteritems():
        kind = tree.kind(fid)

        h = tree.get_file_sha1(fid)

        if kind == 'symlink':
            d = tree.get_symlink_target(fid)
            mode = '120000'
        elif kind == 'file':

            if tree.is_executable(fid):
                mode = '100755'
            else:
                mode = '100644'

            # is the blog already exported?
            if h in filenodes:
                mark = filenodes[h]
                final.append((mode, mark, path))
                continue

            d = tree.get_file_text(fid)
        elif kind == 'directory':
            continue
        else:
            die("Unhandled kind '%s' for path '%s'" % (kind, path))

        mark = marks.next_mark()
        filenodes[h] = mark

        print "blob"
        print "mark :%u" % mark
        print "data %d" % len(d)
        print d

        final.append((mode, mark, path))

