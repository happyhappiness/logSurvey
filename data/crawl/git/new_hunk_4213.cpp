
        return True

class View(object):
    """Represent a p4 view ("p4 help views"), and map files in a
       repo according to the view."""

    class Path(object):
        """A depot or client path, possibly containing wildcards.
           The only one supported is ... at the end, currently.
           Initialize with the full path, with //depot or //client."""

        def __init__(self, path, is_depot):
            self.path = path
            self.is_depot = is_depot
            self.find_wildcards()
            # remember the prefix bit, useful for relative mappings
            m = re.match("(//[^/]+/)", self.path)
            if not m:
                die("Path %s does not start with //prefix/" % self.path)
            prefix = m.group(1)
            if not self.is_depot:
                # strip //client/ on client paths
                self.path = self.path[len(prefix):]

        def find_wildcards(self):
            """Make sure wildcards are valid, and set up internal
               variables."""

            self.ends_triple_dot = False
            # There are three wildcards allowed in p4 views
            # (see "p4 help views").  This code knows how to
            # handle "..." (only at the end), but cannot deal with
            # "%%n" or "*".  Only check the depot_side, as p4 should
            # validate that the client_side matches too.
            if re.search(r'%%[1-9]', self.path):
                die("Can't handle %%n wildcards in view: %s" % self.path)
            if self.path.find("*") >= 0:
                die("Can't handle * wildcards in view: %s" % self.path)
            triple_dot_index = self.path.find("...")
            if triple_dot_index >= 0:
                if not self.path.endswith("..."):
                    die("Can handle ... wildcard only at end of path: %s" %
                        self.path)
                self.ends_triple_dot = True

        def ensure_compatible(self, other_path):
            """Make sure the wildcards agree."""
            if self.ends_triple_dot != other_path.ends_triple_dot:
                 die("Both paths must end with ... if either does;\n" +
                     "paths: %s %s" % (self.path, other_path.path))

        def match_wildcards(self, test_path):
            """See if this test_path matches us, and fill in the value
               of the wildcards if so.  Returns a tuple of
               (True|False, wildcards[]).  For now, only the ... at end
               is supported, so at most one wildcard."""
            if self.ends_triple_dot:
                dotless = self.path[:-3]
                if test_path.startswith(dotless):
                    wildcard = test_path[len(dotless):]
                    return (True, [ wildcard ])
            else:
                if test_path == self.path:
                    return (True, [])
            return (False, [])

        def match(self, test_path):
            """Just return if it matches; don't bother with the wildcards."""
            b, _ = self.match_wildcards(test_path)
            return b

        def fill_in_wildcards(self, wildcards):
            """Return the relative path, with the wildcards filled in
               if there are any."""
            if self.ends_triple_dot:
                return self.path[:-3] + wildcards[0]
            else:
                return self.path

    class Mapping(object):
        def __init__(self, depot_side, client_side, overlay, exclude):
            # depot_side is without the trailing /... if it had one
            self.depot_side = View.Path(depot_side, is_depot=True)
            self.client_side = View.Path(client_side, is_depot=False)
            self.overlay = overlay  # started with "+"
            self.exclude = exclude  # started with "-"
            assert not (self.overlay and self.exclude)
            self.depot_side.ensure_compatible(self.client_side)

        def __str__(self):
            c = " "
            if self.overlay:
                c = "+"
            if self.exclude:
                c = "-"
            return "View.Mapping: %s%s -> %s" % \
                   (c, self.depot_side, self.client_side)

        def map_depot_to_client(self, depot_path):
            """Calculate the client path if using this mapping on the
               given depot path; does not consider the effect of other
               mappings in a view.  Even excluded mappings are returned."""
            matches, wildcards = self.depot_side.match_wildcards(depot_path)
            if not matches:
                return ""
            client_path = self.client_side.fill_in_wildcards(wildcards)
            return client_path

    #
    # View methods
    #
    def __init__(self):
        self.mappings = []

    def append(self, view_line):
        """Parse a view line, splitting it into depot and client
           sides.  Append to self.mappings, preserving order."""

        # Split the view line into exactly two words.  P4 enforces
        # structure on these lines that simplifies this quite a bit.
        #
        # Either or both words may be double-quoted.
        # Single quotes do not matter.
        # Double-quote marks cannot occur inside the words.
        # A + or - prefix is also inside the quotes.
        # There are no quotes unless they contain a space.
        # The line is already white-space stripped.
        # The two words are separated by a single space.
        #
        if view_line[0] == '"':
            # First word is double quoted.  Find its end.
            close_quote_index = view_line.find('"', 1)
            if close_quote_index <= 0:
                die("No first-word closing quote found: %s" % view_line)
            depot_side = view_line[1:close_quote_index]
            # skip closing quote and space
            rhs_index = close_quote_index + 1 + 1
        else:
            space_index = view_line.find(" ")
            if space_index <= 0:
                die("No word-splitting space found: %s" % view_line)
            depot_side = view_line[0:space_index]
            rhs_index = space_index + 1

        if view_line[rhs_index] == '"':
            # Second word is double quoted.  Make sure there is a
            # double quote at the end too.
            if not view_line.endswith('"'):
                die("View line with rhs quote should end with one: %s" %
                    view_line)
            # skip the quotes
            client_side = view_line[rhs_index+1:-1]
        else:
            client_side = view_line[rhs_index:]

        # prefix + means overlay on previous mapping
        overlay = False
        if depot_side.startswith("+"):
            overlay = True
            depot_side = depot_side[1:]

        # prefix - means exclude this path
        exclude = False
        if depot_side.startswith("-"):
            exclude = True
            depot_side = depot_side[1:]

        m = View.Mapping(depot_side, client_side, overlay, exclude)
        self.mappings.append(m)

    def map_in_client(self, depot_path):
        """Return the relative location in the client where this
           depot file should live.  Returns "" if the file should
           not be mapped in the client."""

        paths_filled = []
        client_path = ""

        # look at later entries first
        for m in self.mappings[::-1]:

            # see where will this path end up in the client
            p = m.map_depot_to_client(depot_path)

            if p == "":
                # Depot path does not belong in client.  Must remember
                # this, as previous items should not cause files to
                # exist in this path either.  Remember that the list is
                # being walked from the end, which has higher precedence.
                # Overlap mappings do not exclude previous mappings.
                if not m.overlay:
                    paths_filled.append(m.client_side)

            else:
                # This mapping matched; no need to search any further.
                # But, the mapping could be rejected if the client path
                # has already been claimed by an earlier mapping.
                already_mapped_in_client = False
                for f in paths_filled:
                    # this is View.Path.match
                    if f.match(p):
                        already_mapped_in_client = True
                        break
                if not already_mapped_in_client:
                    # Include this file, unless it is from a line that
                    # explicitly said to exclude it.
                    if not m.exclude:
                        client_path = p

                # a match, even if rejected, always stops the search
                break

        return client_path

class P4Sync(Command, P4UserMap):
    delete_actions = ( "delete", "move/delete", "purge" )

