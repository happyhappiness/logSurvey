
    final = []
    for path, fid in files.iteritems():
        h = tree.get_file_sha1(fid)

        mode = '100644'

        # is the blob already exported?
        if h in filenodes:
            mark = filenodes[h]
        else:
            d = tree.get_file_text(fid)

            mark = marks.next_mark()
            filenodes[h] = mark

            print "blob"
            print "mark :%u" % mark
            print "data %d" % len(d)
            print d

        final.append((mode, mark, path))

