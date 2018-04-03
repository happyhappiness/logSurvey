import bzrlib.plugin
bzrlib.plugin.load_plugins()

import bzrlib.generate_ids

import sys
import os
import json
import re
import StringIO

NAME_RE = re.compile('^([^<>]+)')
AUTHOR_RE = re.compile('^([^<>]+?)? ?<([^<>]*)>$')
RAW_AUTHOR_RE = re.compile('^(\w+) (.+)? <(.*)> (\d+) ([+-]\d+)')

def die(msg, *args):
    sys.stderr.write('ERROR: %s\n' % (msg % args))
