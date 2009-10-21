/* Test for various Toom functions.

Copyright 2009 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library.  If not, see http://www.gnu.org/licenses/.  */


#include "gmp.h"
#include "gmp-impl.h"
#include "tests.h"

#include <stdlib.h>
#include <stdio.h>

/* Main file is expected to define M, N, mpn_toomMN_mul,
 * mpn_toomMN_mul_itch, mpn_toomMN_mul_ok, and then include this
 * file. */

/* Sizes are up to 2^SIZE_LOG limbs */
#ifndef SIZE_LOG
#define SIZE_LOG 10
#endif

#ifndef COUNT
#define COUNT 5000
#endif

#ifndef MIN_BLOCK
#define MIN_BLOCK 2
#endif

#define SIZE (1L << SIZE_LOG)

#define AMAX ((M)*(SIZE))
#define BMAX ((N)*(SIZE))

int
main (int argc, char **argv)
{
  mp_size_t an, bn;
  mp_ptr ap, bp, refp, pp, scratch;
  mp_limb_t keep;
  int count = COUNT;
  int test;
  gmp_randstate_ptr rands;
  TMP_DECL;
  TMP_MARK;

  if (argc > 1)
    {
      char *end;
      count = strtol (argv[1], &end, 0);
      if (*end || count <= 0)
	{
	  fprintf (stderr, "Invalid test count: %s.\n", argv[1]);
	  return 1;
	}
    }

  tests_start ();
  rands = RANDS;

  ap = TMP_ALLOC_LIMBS (AMAX);
  bp = TMP_ALLOC_LIMBS (BMAX);
  refp = TMP_ALLOC_LIMBS (AMAX+BMAX);
  pp = TMP_ALLOC_LIMBS (AMAX+BMAX+1);
  scratch = TMP_ALLOC_LIMBS (mpn_toomMN_mul_itch (AMAX, BMAX));

  for (test = 0; test < count; test++)
    {
      mp_limb_t size_range, n;

      /* We generate n in the range M <= n <= (1 << size_range).
	 size_range >= 3 is good enough for all current toom
	 functions. */
      mpn_random (&size_range, 1);
      size_range = 3 + size_range % (SIZE_LOG - 2);

      mpn_random (&n, 1);
      n = MIN_BLOCK + n % ((1L << size_range) + 1 - MIN_BLOCK);

      ASSERT_ALWAYS (n <= SIZE);

      /* All toom variants require that

	   M*bn >= (N-1)*an + N*(M-1) + 1
	   N*an >= (M-1)*bn + M*(N-1) + 1

	 so we could try to test that earlier. However, some toom
	 variants may have additional requirements. */
      do
	{
	  mp_limb_t r;

	  mpn_random (&r, 1);
	  an = r % (M*n) + 1;

	  mpn_random (&r, 1);
	  bn = r % MIN(an, N*n) + 1;
	}
      while (!mpn_toomMN_mul_ok(an, bn));

      mpn_random2 (ap, an);
      mpn_random2 (bp, bn);
      mpn_random2 (pp, an + bn + 1);
      keep = pp[an + bn];

      mpn_toomMN_mul (pp, ap, an, bp, bn, scratch);
      mpn_mul (refp, ap, an, bp, bn);
      if (pp[an + bn] != keep || mpn_cmp (refp, pp, an + bn) != 0)
	{
	  printf ("ERROR in test %d, an = %d, bn = %d\n",
		  test, (int) an, (int) bn);
	  if (pp[an + bn] != keep)
	    {
	      printf ("pp high:"); mpn_dump (pp + an + bn, 1);
	      printf ("keep:   "); mpn_dump (&keep, 1);
	    }
	  mpn_dump (ap, an);
	  mpn_dump (bp, bn);
	  mpn_dump (pp, an + bn);
	  mpn_dump (refp, an + bn);

	  abort();
	}
    }
  TMP_FREE;
  return 0;
}
