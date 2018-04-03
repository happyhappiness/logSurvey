import bzrlib.plugin
bzrlib.plugin.load_plugins()

import sys
import os
import json
import re

NAME_RE = re.compile('^([^<>]+)')
AUTHOR_RE = re.compile('^([^<>]+?)? ?<([^<>]*)>$')

def die(msg, *args):
    sys.stderr.write('ERROR: %s\n' % (msg % args))
