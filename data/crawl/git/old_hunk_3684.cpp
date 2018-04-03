def gittz(tz):
    return '%+03d%02d' % (tz / 3600, tz % 3600 / 60)

class Marks:

    def __init__(self, path):
