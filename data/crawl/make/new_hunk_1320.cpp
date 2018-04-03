      implicit |= implicit_percent != 0;

      if (implicit && pattern != 0)
	fatal (flocp, "mixed implicit and static pattern rules");

      if (implicit && implicit_percent == 0)
	fatal (flocp, "mixed implicit and normal rules");

      if (implicit)
	{
