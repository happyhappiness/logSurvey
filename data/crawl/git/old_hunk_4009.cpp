    m = { '0100755': 'x', '0120000': 'l' }
    return m.get(mode, '')

class Marks:

    def __init__(self, path):
