	printf("%s\n", sha1_to_hex(sha1));
}

static const char hash_object_usage[] =
"git-hash-object [-t <type>] [-w] [--stdin] <file>...";

int main(int argc, char **argv)
{
