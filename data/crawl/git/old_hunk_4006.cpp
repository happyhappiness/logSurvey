
    sys.stdout.flush()

def do_capabilities(parser):
    print "import"
    print "refspec refs/heads/*:%s/heads/*" % prefix
    print

def do_list(parser):
