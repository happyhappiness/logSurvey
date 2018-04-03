
NAME_RE = re.compile('^([^<>]+)')
AUTHOR_RE = re.compile('^([^<>]+?)? ?<([^<>]+)>$')
RAW_AUTHOR_RE = re.compile('^(\w+) (?:(.+)? )?<(.+)> (\d+) ([+-]\d+)')

def die(msg, *args):
    sys.stderr.write('ERROR: %s\n' % (msg % args))
