/* Intel Goldmont/32 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 2019 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#define GMP_LIMB_BITS 32
#define GMP_LIMB_BYTES 4

/* 2200 MHz Intel Atom C3758 Goldmont/Denverton */
/* FFT tuning limit = 0.5 M */
/* Generated by tuneup.c, 2019-09-26, gcc 8.3 */

#define MOD_1_NORM_THRESHOLD                 7
#define MOD_1_UNNORM_THRESHOLD              12
#define MOD_1N_TO_MOD_1_1_THRESHOLD          9
#define MOD_1U_TO_MOD_1_1_THRESHOLD          7
#define MOD_1_1_TO_MOD_1_2_THRESHOLD        10
#define MOD_1_2_TO_MOD_1_4_THRESHOLD         0  /* never mpn_mod_1s_2p */
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD     12
#define USE_PREINV_DIVREM_1                  1  /* native */
#define DIV_QR_1N_PI1_METHOD                 1  /* 33.52% faster than 2 */
#define DIV_QR_1_NORM_THRESHOLD             32
#define DIV_QR_1_UNNORM_THRESHOLD        MP_SIZE_T_MAX  /* never */
#define DIV_QR_2_PI2_THRESHOLD           MP_SIZE_T_MAX  /* never */
#define DIVEXACT_1_THRESHOLD                 0  /* always (native) */
#define BMOD_1_TO_MOD_1_THRESHOLD           23

#define DIV_1_VS_MUL_1_PERCENT             228

#define MUL_TOOM22_THRESHOLD                18
#define MUL_TOOM33_THRESHOLD               138
#define MUL_TOOM44_THRESHOLD               193
#define MUL_TOOM6H_THRESHOLD               292
#define MUL_TOOM8H_THRESHOLD               387

#define MUL_TOOM32_TO_TOOM43_THRESHOLD     129
#define MUL_TOOM32_TO_TOOM53_THRESHOLD     141
#define MUL_TOOM42_TO_TOOM53_THRESHOLD     132
#define MUL_TOOM42_TO_TOOM63_THRESHOLD     138
#define MUL_TOOM43_TO_TOOM54_THRESHOLD     185

#define SQR_BASECASE_THRESHOLD               0  /* always (native) */
#define SQR_TOOM2_THRESHOLD                 32
#define SQR_TOOM3_THRESHOLD                157
#define SQR_TOOM4_THRESHOLD                298
#define SQR_TOOM6_THRESHOLD                399
#define SQR_TOOM8_THRESHOLD                527

#define MULMID_TOOM42_THRESHOLD             60

#define MULMOD_BNM1_THRESHOLD               13
#define SQRMOD_BNM1_THRESHOLD               15

#define MUL_FFT_MODF_THRESHOLD             376  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    376, 5}, {     21, 6}, {     11, 5}, {     23, 6}, \
    {     21, 7}, {     11, 6}, {     25, 7}, {     13, 6}, \
    {     27, 7}, {     15, 6}, {     31, 7}, {     19, 6}, \
    {     39, 7}, {     21, 8}, {     11, 7}, {     27, 8}, \
    {     15, 7}, {     33, 8}, {     19, 7}, {     39, 8}, \
    {     23, 7}, {     47, 8}, {     27, 9}, {     15, 8}, \
    {     39, 9}, {     23, 8}, {     47,10}, {     15, 9}, \
    {     31, 8}, {     63, 9}, {     39, 8}, {     79, 9}, \
    {     47,10}, {     31, 9}, {     79,10}, {     47, 9}, \
    {     95,11}, {     31,10}, {     63, 9}, {    135,10}, \
    {     79, 9}, {    159,10}, {     95, 9}, {    191,10}, \
    {    111,11}, {     63,10}, {    127, 9}, {    255, 8}, \
    {    511,10}, {    143, 9}, {    287, 8}, {    575, 9}, \
    {    303,10}, {    159, 9}, {    319,11}, {     95,10}, \
    {    191,12}, {     63,11}, {    127,10}, {    255, 9}, \
    {    511,10}, {    271, 9}, {    543,10}, {    287, 9}, \
    {    575,10}, {    303, 9}, {    607,11}, {    159,10}, \
    {    319, 9}, {    639,10}, {    351, 9}, {    703,11}, \
    {    191,10}, {    383, 9}, {    767,10}, {    415, 9}, \
    {    831,11}, {    223,10}, {    447,12}, {   4096,13}, \
    {   8192,14}, {  16384,15}, {  32768,16} }
#define MUL_FFT_TABLE3_SIZE 83
#define MUL_FFT_THRESHOLD                 3712

#define SQR_FFT_MODF_THRESHOLD             340  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    340, 5}, {     21, 6}, {     11, 5}, {     23, 6}, \
    {     12, 5}, {     25, 6}, {     21, 7}, {     11, 6}, \
    {     25, 7}, {     13, 6}, {     27, 7}, {     15, 6}, \
    {     31, 7}, {     21, 8}, {     11, 7}, {     27, 8}, \
    {     15, 7}, {     33, 8}, {     19, 7}, {     39, 8}, \
    {     23, 7}, {     47, 8}, {     27, 9}, {     15, 8}, \
    {     39, 9}, {     23, 8}, {     47,10}, {     15, 9}, \
    {     31, 8}, {     67, 9}, {     39, 8}, {     79, 9}, \
    {     47,10}, {     31, 9}, {     79,10}, {     47, 9}, \
    {     95,11}, {     31,10}, {     63, 9}, {    127, 8}, \
    {    255,10}, {     79, 8}, {    319,10}, {     95, 9}, \
    {    191,11}, {     63,10}, {    127, 9}, {    255, 8}, \
    {    511, 9}, {    271, 8}, {    543,10}, {    143, 9}, \
    {    287, 8}, {    575, 9}, {    303, 8}, {    607,10}, \
    {    159, 9}, {    319,11}, {     95,10}, {    191,12}, \
    {     63,11}, {    127,10}, {    255, 9}, {    511,10}, \
    {    271, 9}, {    543,10}, {    287, 9}, {    575,10}, \
    {    303, 9}, {    607,11}, {    159,10}, {    319, 9}, \
    {    639,10}, {    335, 9}, {    671,10}, {    351, 9}, \
    {    703,11}, {    191,10}, {    383, 9}, {    767,10}, \
    {    415, 9}, {    831,11}, {    223,10}, {    479,12}, \
    {   4096,13}, {   8192,14}, {  16384,15}, {  32768,16} }
#define SQR_FFT_TABLE3_SIZE 88
#define SQR_FFT_THRESHOLD                 3264

#define MULLO_BASECASE_THRESHOLD             5
#define MULLO_DC_THRESHOLD                  53
#define MULLO_MUL_N_THRESHOLD             6633
#define SQRLO_BASECASE_THRESHOLD             0  /* always */
#define SQRLO_DC_THRESHOLD                  97
#define SQRLO_SQR_THRESHOLD               6440

#define DC_DIV_QR_THRESHOLD                 75
#define DC_DIVAPPR_Q_THRESHOLD             200
#define DC_BDIV_QR_THRESHOLD                69
#define DC_BDIV_Q_THRESHOLD                134

#define INV_MULMOD_BNM1_THRESHOLD           34
#define INV_NEWTON_THRESHOLD               276
#define INV_APPR_THRESHOLD                 230

#define BINV_NEWTON_THRESHOLD              327
#define REDC_1_TO_REDC_N_THRESHOLD          72

#define MU_DIV_QR_THRESHOLD               1470
#define MU_DIVAPPR_Q_THRESHOLD            1589
#define MUPI_DIV_QR_THRESHOLD              146
#define MU_BDIV_QR_THRESHOLD              1334
#define MU_BDIV_Q_THRESHOLD               1589

#define POWM_SEC_TABLE  1,16,96,386,1420

#define GET_STR_DC_THRESHOLD                14
#define GET_STR_PRECOMPUTE_THRESHOLD        21
#define SET_STR_DC_THRESHOLD               818
#define SET_STR_PRECOMPUTE_THRESHOLD      1647

#define FAC_DSC_THRESHOLD                  106
#define FAC_ODD_THRESHOLD                   29

#define MATRIX22_STRASSEN_THRESHOLD         21
#define HGCD2_DIV1_METHOD                    1  /* 5.72% faster than 3 */
#define HGCD_THRESHOLD                     174
#define HGCD_APPR_THRESHOLD                214
#define HGCD_REDUCE_THRESHOLD             2479
#define GCD_DC_THRESHOLD                   618
#define GCDEXT_DC_THRESHOLD                440
#define JACOBI_BASE_METHOD                   4  /* 6.14% faster than 3 */
