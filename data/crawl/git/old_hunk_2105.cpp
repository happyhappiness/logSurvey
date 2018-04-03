        except UnicodeEncodeError:
            f.buffer.write(msg.encode(ENCODING))
else:
    def str_to_bytes(s):
        return s

