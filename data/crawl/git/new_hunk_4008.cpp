#!/usr/bin/env python
#
# Copyright (c) 2012 Felipe Contreras
#

#
# Just copy to your ~/bin, or anywhere in your $PATH.
# Then you can clone with:
# % git clone bzr::/path/to/bzr/repo/or/url
#
# For example:
# % git clone bzr::$HOME/myrepo
# or
# % git clone bzr::lp:myrepo
#

import sys

import bzrlib
bzrlib.initialize()

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
    sys.exit(1)

def warn(msg, *args):
    sys.stderr.write('WARNING: %s\n' % (msg % args))

def gittz(tz):
    return '%+03d%02d' % (tz / 3600, tz % 3600 / 60)

class Marks:

    def __init__(self, path):
        self.path = path
        self.tips = {}
        self.marks = {}
        self.last_mark = 0
        self.load()

    def load(self):
        if not os.path.exists(self.path):
            return

        tmp = json.load(open(self.path))
        self.tips = tmp['tips']
        self.marks = tmp['marks']
        self.last_mark = tmp['last-mark']

    def dict(self):
        return { 'tips': self.tips, 'marks': self.marks, 'last-mark' : self.last_mark }

    def store(self):
        json.dump(self.dict(), open(self.path, 'w'))

    def __str__(self):
        return str(self.dict())

    def from_rev(self, rev):
        return self.marks[rev]

    def next_mark(self):
        self.last_mark += 1
        return self.last_mark

    def get_mark(self, rev):
        self.last_mark += 1
        self.marks[rev] = self.last_mark
        return self.last_mark

    def is_marked(self, rev):
        return self.marks.has_key(rev)

    def get_tip(self, branch):
        return self.tips.get(branch, None)

    def set_tip(self, branch, tip):
        self.tips[branch] = tip

class Parser:

    def __init__(self, repo):
        self.repo = repo
        self.line = self.get_line()

    def get_line(self):
        return sys.stdin.readline().strip()

    def __getitem__(self, i):
        return self.line.split()[i]

    def check(self, word):
        return self.line.startswith(word)

    def each_block(self, separator):
        while self.line != separator:
            yield self.line
            self.line = self.get_line()

    def __iter__(self):
        return self.each_block('')

    def next(self):
        self.line = self.get_line()
        if self.line == 'done':
            self.line = None

def rev_to_mark(rev):
    global marks
    return marks.from_rev(rev)

def fixup_user(user):
    name = mail = None
    user = user.replace('"', '')
    m = AUTHOR_RE.match(user)
    if m:
        name = m.group(1)
        mail = m.group(2).strip()
    else:
        m = NAME_RE.match(user)
        if m:
            name = m.group(1).strip()

    return '%s <%s>' % (name, mail)

def get_filechanges(cur, prev):
    modified = {}
    removed = {}

    changes = cur.changes_from(prev)

    for path, fid, kind in changes.added:
        modified[path] = fid
    for path, fid, kind in changes.removed:
        removed[path] = None
    for path, fid, kind, mod, _ in changes.modified:
        modified[path] = fid
    for oldpath, newpath, fid, kind, mod, _ in changes.renamed:
        removed[oldpath] = None
        modified[newpath] = fid

    return modified, removed

def export_files(tree, files):
    global marks, filenodes

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

    return final

def export_branch(branch, name):
    global prefix, dirname

    ref = '%s/heads/%s' % (prefix, name)
    tip = marks.get_tip(name)

    repo = branch.repository
    repo.lock_read()
    revs = branch.iter_merge_sorted_revisions(None, tip, 'exclude', 'forward')
    count = 0

    revs = [revid for revid, _, _, _ in revs if not marks.is_marked(revid)]

    for revid in revs:

        rev = repo.get_revision(revid)

        parents = rev.parent_ids
        time = rev.timestamp
        tz = rev.timezone
        committer = rev.committer.encode('utf-8')
        committer = "%s %u %s" % (fixup_user(committer), time, gittz(tz))
        author = committer
        msg = rev.message.encode('utf-8')

        msg += '\n'

        if len(parents) == 0:
            parent = bzrlib.revision.NULL_REVISION
        else:
            parent = parents[0]

        cur_tree = repo.revision_tree(revid)
        prev = repo.revision_tree(parent)
        modified, removed = get_filechanges(cur_tree, prev)

        modified_final = export_files(cur_tree, modified)

        if len(parents) == 0:
            print 'reset %s' % ref

        print "commit %s" % ref
        print "mark :%d" % (marks.get_mark(revid))
        print "author %s" % (author)
        print "committer %s" % (committer)
        print "data %d" % (len(msg))
        print msg

        for i, p in enumerate(parents):
            try:
                m = rev_to_mark(p)
            except KeyError:
                # ghost?
                continue
            if i == 0:
                print "from :%s" % m
            else:
                print "merge :%s" % m

        for f in modified_final:
            print "M %s :%u %s" % f
        for f in removed:
            print "D %s" % (f)
        print

        count += 1
        if (count % 100 == 0):
            print "progress revision %s (%d/%d)" % (revid, count, len(revs))
            print "#############################################################"

    repo.unlock()

    revid = branch.last_revision()

    # make sure the ref is updated
    print "reset %s" % ref
    print "from :%u" % rev_to_mark(revid)
    print

    marks.set_tip(name, revid)

def export_tag(repo, name):
    global tags
    try:
        print "reset refs/tags/%s" % name
        print "from :%u" % rev_to_mark(tags[name])
        print
    except KeyError:
        warn("TODO: fetch tag '%s'" % name)

def do_import(parser):
    global dirname

    branch = parser.repo
    path = os.path.join(dirname, 'marks-git')

    print "feature done"
    if os.path.exists(path):
        print "feature import-marks=%s" % path
    print "feature export-marks=%s" % path
    sys.stdout.flush()

    while parser.check('import'):
        ref = parser[1]
        if ref.startswith('refs/heads/'):
            name = ref[len('refs/heads/'):]
            export_branch(branch, name)
        if ref.startswith('refs/tags/'):
            name = ref[len('refs/tags/'):]
            export_tag(branch, name)
        parser.next()

    print 'done'

    sys.stdout.flush()

def do_capabilities(parser):
    print "import"
    print "refspec refs/heads/*:%s/heads/*" % prefix
    print

def do_list(parser):
    global tags
    print "? refs/heads/%s" % 'master'
    for tag, revid in parser.repo.tags.get_tag_dict().items():
        print "? refs/tags/%s" % tag
        tags[tag] = revid
    print "@refs/heads/%s HEAD" % 'master'
    print

def get_repo(url, alias):
    origin = bzrlib.controldir.ControlDir.open(url)
    return origin.open_branch()

def main(args):
    global marks, prefix, dirname
    global tags, filenodes

    alias = args[1]
    url = args[2]

    prefix = 'refs/bzr/%s' % alias
    tags = {}
    filenodes = {}

    gitdir = os.environ['GIT_DIR']
    dirname = os.path.join(gitdir, 'bzr', alias)

    if not os.path.exists(dirname):
        os.makedirs(dirname)

    repo = get_repo(url, alias)

    marks_path = os.path.join(dirname, 'marks-int')
    marks = Marks(marks_path)

    parser = Parser(repo)
    for line in parser:
        if parser.check('capabilities'):
            do_capabilities(parser)
        elif parser.check('list'):
            do_list(parser)
        elif parser.check('import'):
            do_import(parser)
        else:
            die('unhandled command: %s' % line)
        sys.stdout.flush()

    marks.store()

sys.exit(main(sys.argv))