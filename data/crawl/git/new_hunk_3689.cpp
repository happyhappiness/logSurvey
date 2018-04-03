# For remote repositories a local clone is stored in
# "$GIT_DIR/hg/origin/clone/.hg/".

from mercurial import hg, ui, bookmarks, context, util, encoding, node, error, extensions

import re
import sys
