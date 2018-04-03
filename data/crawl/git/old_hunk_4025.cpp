
NAME_RE = re.compile('^([^<>]+)')
AUTHOR_RE = re.compile('^([^<>]+?)? ?<([^<>]+)>$')

def die(msg, *args):
    sys.stderr.write('ERROR: %s\n' % (msg % args))
