// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stdint.h>
#include <stddef.h>

#include <xnnpack/common.h>
#include <xnnpack/microparams.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                \
      size_t g,                                             \
      size_t nc,                                            \
      size_t kc,                                            \
      size_t nr,                                            \
      size_t kr,                                            \
      size_t sr,                                            \
      const int8_t* weights,                                \
      const uint32_t* bias,                                 \
      const void* scale,                                    \
      int8_t* packed_weights,                               \
      size_t extra_bytes,                                   \
      const void* params);                                  \

DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x2__scalar_int_x2)
DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x4__scalar_int_x2)
DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x8__scalar_int_x2)
DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x16__scalar_int_x2)
DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x32__scalar_int_x2)

DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x2__scalar_int_x4)
DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x4__scalar_int_x4)
DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x8__scalar_int_x4)
DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x16__scalar_int_x4)
DECLARE_X8_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x8_packw_gemm_goi_ukernel_x32__scalar_int_x4)

#define DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                 \
      size_t g,                                              \
      size_t nc,                                             \
      size_t kc,                                             \
      size_t nr,                                             \
      size_t kr,                                             \
      size_t sr,                                             \
      const uint16_t* weights,                               \
      const uint16_t* bias,                                  \
      const void* scale,                                     \
      uint16_t* packed_weights,                              \
      size_t extra_bytes,                                    \
      const void* params);                                   \

DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__scalar_int_x4)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__scalar_int_x4)

DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__neon_ld4lane_x4)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__neon_ld4lane_x4_prfm)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__neon_ld4lane_x8)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__neon_ld4lane_x8_prfm)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__neon_ld4lane_x12)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__neon_ld4lane_x12_prfm)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__neon_ld4lane_x16)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__neon_ld4lane_x16_prfm)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_x4)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_x4_prfm)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_x8)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_x8_prfm)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_x12)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_x12_prfm)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_x16)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_x16_prfm)

DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__avx2_x16)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x8__avx2_x16_prfm)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__avx2_x16)
DECLARE_X16_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x16_packw_gemm_goi_ukernel_x16__avx2_x16_prfm)

#define DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                 \
      size_t g,                                              \
      size_t nc,                                             \
      size_t kc,                                             \
      size_t nr,                                             \
      size_t kr,                                             \
      size_t sr,                                             \
      const uint32_t* weights,                               \
      const uint32_t* bias,                                  \
      const void* scale,                                     \
      uint32_t* packed_weights,                              \
      size_t extra_bytes,                                    \
      const void* params);                                   \

DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x2__scalar_float_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x2__scalar_int_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x3__scalar_float_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x3__scalar_int_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x4__scalar_float_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x4__scalar_int_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__scalar_float_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__scalar_int_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__scalar_float_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__scalar_int_x4)

DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x2__neon_ld2lane_x2)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x2__neon_ld2lane_x2_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__neon_ld4lane_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__neon_ld4lane_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__neon_ld4lane_x8)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__neon_ld4lane_x8_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__neon_ld4lane_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__neon_ld4lane_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__neon_ld4lane_x8)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__neon_ld4lane_x8_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x12__neon_ld4lane_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x12__neon_ld4lane_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x12__neon_ld4lane_x8)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x12__neon_ld4lane_x8_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__neon_ld4lane_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__neon_ld4lane_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__neon_ld4lane_x8)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__neon_ld4lane_x8_prfm)

DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x2c4__sse2_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x2c4__sse2_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__sse2_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__sse2_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__sse2_x8)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__sse2_x8_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__sse2_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__sse2_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__sse2_x8)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__sse2_x8_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__sse2_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__sse2_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__sse2_x8)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__sse2_x8_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16s4__sse2_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16s4__sse2_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16s4__sse2_x8)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16s4__sse2_x8_prfm)

DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__avx_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__avx_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__avx_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__avx_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__avx_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__avx_x4_prfm)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16s4__avx_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16s4__avx_x4_prfm)

DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__avx512f_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x16__avx512f_x4_prfm)

DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x2c4__wasmsimd_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8__wasmsimd_x4)
DECLARE_X32_PACKW_GEMM_GOI_UKERNEL_FUNCTION(xnn_x32_packw_gemm_goi_ukernel_x8s4__wasmsimd_x4)

#ifdef __cplusplus
}  // extern "C"
#endif
