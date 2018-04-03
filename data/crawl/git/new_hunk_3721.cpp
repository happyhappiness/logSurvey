from :17
M 100644 :18 b.c

blob
mark :20
data 243
#include <unistd.h>
#include <stdio.h>

long f(long x)
{
	int s = 0;
	while (x) {
		x >>= 1;
		s++;
	}
	return s;
}

/*
 * This is only a short example!
 */

int main ()
{
	printf("%ld\n", f(15));
	return 0;
}

/* incomplete lines are bad! */

commit refs/heads/parallel-change
mark :21
author Thomas Rast <trast@inf.ethz.ch> 1365776157 +0200
committer Thomas Rast <trast@inf.ethz.ch> 1365776157 +0200
data 55
change on another line of history while rename happens
from :14
M 100644 :20 a.c

blob
mark :22
data 242
#include <unistd.h>
#include <stdio.h>

long f(long x)
{
	int s = 0;
	while (x) {
		x /= 2;
		s++;
	}
	return s;
}

/*
 * This is only a short example!
 */

int main ()
{
	printf("%ld\n", f(15));
	return 0;
}

/* incomplete lines are bad! */

commit refs/heads/parallel-change
mark :23
author Thomas Rast <trast@inf.ethz.ch> 1365776184 +0200
committer Thomas Rast <trast@inf.ethz.ch> 1365776191 +0200
data 24
Merge across the rename
from :21
merge :17
D a.c
M 100644 :22 b.c

reset refs/heads/parallel-change
from :23
