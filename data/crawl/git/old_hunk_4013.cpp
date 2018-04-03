def p4_move(src, dest):
    p4_system(["move", "-k", wildcard_encode(src), wildcard_encode(dest)])

#
# Canonicalize the p4 type and return a tuple of the
# base type, plus any modifiers.  See "p4 help filetypes"
