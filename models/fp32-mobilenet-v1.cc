// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <xnnpack.h>

#include <array>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <random>

#include <xnnpack/cache.h>
#include <xnnpack/common.h>
#include <xnnpack/memory.h>
#include <xnnpack/models.h>

namespace models {

ExecutionPlan FP32MobileNetV1(bool use_jit, pthreadpool_t threadpool) {
  alignas(16) static std::array<float, 150528 + XNN_EXTRA_BYTES / sizeof(float)> v0;
  alignas(16) static std::array<float, 401408 + XNN_EXTRA_BYTES / sizeof(float)> v1;
  alignas(16) static std::array<float, 401408 + XNN_EXTRA_BYTES / sizeof(float)> v2;
  alignas(16) static std::array<float, 802816 + XNN_EXTRA_BYTES / sizeof(float)> v3;
  alignas(16) static std::array<float, 200704 + XNN_EXTRA_BYTES / sizeof(float)> v4;
  alignas(16) static std::array<float, 401408 + XNN_EXTRA_BYTES / sizeof(float)> v5;
  alignas(16) static std::array<float, 401408 + XNN_EXTRA_BYTES / sizeof(float)> v6;
  alignas(16) static std::array<float, 401408 + XNN_EXTRA_BYTES / sizeof(float)> v7;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v8;
  alignas(16) static std::array<float, 200704 + XNN_EXTRA_BYTES / sizeof(float)> v9;
  alignas(16) static std::array<float, 200704 + XNN_EXTRA_BYTES / sizeof(float)> v10;
  alignas(16) static std::array<float, 200704 + XNN_EXTRA_BYTES / sizeof(float)> v11;
  alignas(16) static std::array<float, 50176 + XNN_EXTRA_BYTES / sizeof(float)> v12;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v13;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v14;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v15;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v16;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v17;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v18;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v19;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v20;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v21;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v22;
  alignas(16) static std::array<float, 100352 + XNN_EXTRA_BYTES / sizeof(float)> v23;
  alignas(16) static std::array<float, 25088 + XNN_EXTRA_BYTES / sizeof(float)> v24;
  alignas(16) static std::array<float, 50176 + XNN_EXTRA_BYTES / sizeof(float)> v25;
  alignas(16) static std::array<float, 50176 + XNN_EXTRA_BYTES / sizeof(float)> v26;
  alignas(16) static std::array<float, 50176 + XNN_EXTRA_BYTES / sizeof(float)> v27;
  alignas(16) static std::array<float, 1024 + XNN_EXTRA_BYTES / sizeof(float)> v28;
  alignas(16) static std::array<float, 1001 + XNN_EXTRA_BYTES / sizeof(float)> v29;
  alignas(16) static std::array<float, 864 + XNN_EXTRA_BYTES / sizeof(float)> w30;
  alignas(16) static std::array<float, 32 + XNN_EXTRA_BYTES / sizeof(float)> w31;
  alignas(16) static std::array<float, 288 + XNN_EXTRA_BYTES / sizeof(float)> w32;
  alignas(16) static std::array<float, 32 + XNN_EXTRA_BYTES / sizeof(float)> w33;
  alignas(16) static std::array<float, 2048 + XNN_EXTRA_BYTES / sizeof(float)> w34;
  alignas(16) static std::array<float, 64 + XNN_EXTRA_BYTES / sizeof(float)> w35;
  alignas(16) static std::array<float, 576 + XNN_EXTRA_BYTES / sizeof(float)> w36;
  alignas(16) static std::array<float, 64 + XNN_EXTRA_BYTES / sizeof(float)> w37;
  alignas(16) static std::array<float, 8192 + XNN_EXTRA_BYTES / sizeof(float)> w38;
  alignas(16) static std::array<float, 128 + XNN_EXTRA_BYTES / sizeof(float)> w39;
  alignas(16) static std::array<float, 1152 + XNN_EXTRA_BYTES / sizeof(float)> w40;
  alignas(16) static std::array<float, 128 + XNN_EXTRA_BYTES / sizeof(float)> w41;
  alignas(16) static std::array<float, 16384 + XNN_EXTRA_BYTES / sizeof(float)> w42;
  alignas(16) static std::array<float, 128 + XNN_EXTRA_BYTES / sizeof(float)> w43;
  alignas(16) static std::array<float, 1152 + XNN_EXTRA_BYTES / sizeof(float)> w44;
  alignas(16) static std::array<float, 128 + XNN_EXTRA_BYTES / sizeof(float)> w45;
  alignas(16) static std::array<float, 32768 + XNN_EXTRA_BYTES / sizeof(float)> w46;
  alignas(16) static std::array<float, 256 + XNN_EXTRA_BYTES / sizeof(float)> w47;
  alignas(16) static std::array<float, 2304 + XNN_EXTRA_BYTES / sizeof(float)> w48;
  alignas(16) static std::array<float, 256 + XNN_EXTRA_BYTES / sizeof(float)> w49;
  alignas(16) static std::array<float, 65536 + XNN_EXTRA_BYTES / sizeof(float)> w50;
  alignas(16) static std::array<float, 256 + XNN_EXTRA_BYTES / sizeof(float)> w51;
  alignas(16) static std::array<float, 2304 + XNN_EXTRA_BYTES / sizeof(float)> w52;
  alignas(16) static std::array<float, 256 + XNN_EXTRA_BYTES / sizeof(float)> w53;
  alignas(16) static std::array<float, 131072 + XNN_EXTRA_BYTES / sizeof(float)> w54;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w55;
  alignas(16) static std::array<float, 4608 + XNN_EXTRA_BYTES / sizeof(float)> w56;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w57;
  alignas(16) static std::array<float, 262144 + XNN_EXTRA_BYTES / sizeof(float)> w58;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w59;
  alignas(16) static std::array<float, 4608 + XNN_EXTRA_BYTES / sizeof(float)> w60;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w61;
  alignas(16) static std::array<float, 262144 + XNN_EXTRA_BYTES / sizeof(float)> w62;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w63;
  alignas(16) static std::array<float, 4608 + XNN_EXTRA_BYTES / sizeof(float)> w64;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w65;
  alignas(16) static std::array<float, 262144 + XNN_EXTRA_BYTES / sizeof(float)> w66;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w67;
  alignas(16) static std::array<float, 4608 + XNN_EXTRA_BYTES / sizeof(float)> w68;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w69;
  alignas(16) static std::array<float, 262144 + XNN_EXTRA_BYTES / sizeof(float)> w70;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w71;
  alignas(16) static std::array<float, 4608 + XNN_EXTRA_BYTES / sizeof(float)> w72;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w73;
  alignas(16) static std::array<float, 262144 + XNN_EXTRA_BYTES / sizeof(float)> w74;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w75;
  alignas(16) static std::array<float, 4608 + XNN_EXTRA_BYTES / sizeof(float)> w76;
  alignas(16) static std::array<float, 512 + XNN_EXTRA_BYTES / sizeof(float)> w77;
  alignas(16) static std::array<float, 524288 + XNN_EXTRA_BYTES / sizeof(float)> w78;
  alignas(16) static std::array<float, 1024 + XNN_EXTRA_BYTES / sizeof(float)> w79;
  alignas(16) static std::array<float, 9216 + XNN_EXTRA_BYTES / sizeof(float)> w80;
  alignas(16) static std::array<float, 1024 + XNN_EXTRA_BYTES / sizeof(float)> w81;
  alignas(16) static std::array<float, 1048576 + XNN_EXTRA_BYTES / sizeof(float)> w82;
  alignas(16) static std::array<float, 1024 + XNN_EXTRA_BYTES / sizeof(float)> w83;
  alignas(16) static std::array<float, 1025024 + XNN_EXTRA_BYTES / sizeof(float)> w84;
  alignas(16) static std::array<float, 1001 + XNN_EXTRA_BYTES / sizeof(float)> w85;

  std::random_device random_device;
  auto rng = std::mt19937(random_device());
  auto f32rng = std::bind(std::uniform_real_distribution<float>(-1.0f, +1.0f), std::ref(rng));
  std::generate(v0.begin(), v0.end(), std::ref(f32rng));
  std::generate(v1.begin(), v1.end(), std::ref(f32rng));
  std::generate(v2.begin(), v2.end(), std::ref(f32rng));
  std::generate(v3.begin(), v3.end(), std::ref(f32rng));
  std::generate(v4.begin(), v4.end(), std::ref(f32rng));
  std::generate(v5.begin(), v5.end(), std::ref(f32rng));
  std::generate(v6.begin(), v6.end(), std::ref(f32rng));
  std::generate(v7.begin(), v7.end(), std::ref(f32rng));
  std::generate(v8.begin(), v8.end(), std::ref(f32rng));
  std::generate(v9.begin(), v9.end(), std::ref(f32rng));
  std::generate(v10.begin(), v10.end(), std::ref(f32rng));
  std::generate(v11.begin(), v11.end(), std::ref(f32rng));
  std::generate(v12.begin(), v12.end(), std::ref(f32rng));
  std::generate(v13.begin(), v13.end(), std::ref(f32rng));
  std::generate(v14.begin(), v14.end(), std::ref(f32rng));
  std::generate(v15.begin(), v15.end(), std::ref(f32rng));
  std::generate(v16.begin(), v16.end(), std::ref(f32rng));
  std::generate(v17.begin(), v17.end(), std::ref(f32rng));
  std::generate(v18.begin(), v18.end(), std::ref(f32rng));
  std::generate(v19.begin(), v19.end(), std::ref(f32rng));
  std::generate(v20.begin(), v20.end(), std::ref(f32rng));
  std::generate(v21.begin(), v21.end(), std::ref(f32rng));
  std::generate(v22.begin(), v22.end(), std::ref(f32rng));
  std::generate(v23.begin(), v23.end(), std::ref(f32rng));
  std::generate(v24.begin(), v24.end(), std::ref(f32rng));
  std::generate(v25.begin(), v25.end(), std::ref(f32rng));
  std::generate(v26.begin(), v26.end(), std::ref(f32rng));
  std::generate(v27.begin(), v27.end(), std::ref(f32rng));
  std::generate(v28.begin(), v28.end(), std::ref(f32rng));
  std::generate(v29.begin(), v29.end(), std::ref(f32rng));
  std::generate(w30.begin(), w30.end(), std::ref(f32rng));
  std::generate(w31.begin(), w31.end(), std::ref(f32rng));
  std::generate(w32.begin(), w32.end(), std::ref(f32rng));
  std::generate(w33.begin(), w33.end(), std::ref(f32rng));
  std::generate(w34.begin(), w34.end(), std::ref(f32rng));
  std::generate(w35.begin(), w35.end(), std::ref(f32rng));
  std::generate(w36.begin(), w36.end(), std::ref(f32rng));
  std::generate(w37.begin(), w37.end(), std::ref(f32rng));
  std::generate(w38.begin(), w38.end(), std::ref(f32rng));
  std::generate(w39.begin(), w39.end(), std::ref(f32rng));
  std::generate(w40.begin(), w40.end(), std::ref(f32rng));
  std::generate(w41.begin(), w41.end(), std::ref(f32rng));
  std::generate(w42.begin(), w42.end(), std::ref(f32rng));
  std::generate(w43.begin(), w43.end(), std::ref(f32rng));
  std::generate(w44.begin(), w44.end(), std::ref(f32rng));
  std::generate(w45.begin(), w45.end(), std::ref(f32rng));
  std::generate(w46.begin(), w46.end(), std::ref(f32rng));
  std::generate(w47.begin(), w47.end(), std::ref(f32rng));
  std::generate(w48.begin(), w48.end(), std::ref(f32rng));
  std::generate(w49.begin(), w49.end(), std::ref(f32rng));
  std::generate(w50.begin(), w50.end(), std::ref(f32rng));
  std::generate(w51.begin(), w51.end(), std::ref(f32rng));
  std::generate(w52.begin(), w52.end(), std::ref(f32rng));
  std::generate(w53.begin(), w53.end(), std::ref(f32rng));
  std::generate(w54.begin(), w54.end(), std::ref(f32rng));
  std::generate(w55.begin(), w55.end(), std::ref(f32rng));
  std::generate(w56.begin(), w56.end(), std::ref(f32rng));
  std::generate(w57.begin(), w57.end(), std::ref(f32rng));
  std::generate(w58.begin(), w58.end(), std::ref(f32rng));
  std::generate(w59.begin(), w59.end(), std::ref(f32rng));
  std::generate(w60.begin(), w60.end(), std::ref(f32rng));
  std::generate(w61.begin(), w61.end(), std::ref(f32rng));
  std::generate(w62.begin(), w62.end(), std::ref(f32rng));
  std::generate(w63.begin(), w63.end(), std::ref(f32rng));
  std::generate(w64.begin(), w64.end(), std::ref(f32rng));
  std::generate(w65.begin(), w65.end(), std::ref(f32rng));
  std::generate(w66.begin(), w66.end(), std::ref(f32rng));
  std::generate(w67.begin(), w67.end(), std::ref(f32rng));
  std::generate(w68.begin(), w68.end(), std::ref(f32rng));
  std::generate(w69.begin(), w69.end(), std::ref(f32rng));
  std::generate(w70.begin(), w70.end(), std::ref(f32rng));
  std::generate(w71.begin(), w71.end(), std::ref(f32rng));
  std::generate(w72.begin(), w72.end(), std::ref(f32rng));
  std::generate(w73.begin(), w73.end(), std::ref(f32rng));
  std::generate(w74.begin(), w74.end(), std::ref(f32rng));
  std::generate(w75.begin(), w75.end(), std::ref(f32rng));
  std::generate(w76.begin(), w76.end(), std::ref(f32rng));
  std::generate(w77.begin(), w77.end(), std::ref(f32rng));
  std::generate(w78.begin(), w78.end(), std::ref(f32rng));
  std::generate(w79.begin(), w79.end(), std::ref(f32rng));
  std::generate(w80.begin(), w80.end(), std::ref(f32rng));
  std::generate(w81.begin(), w81.end(), std::ref(f32rng));
  std::generate(w82.begin(), w82.end(), std::ref(f32rng));
  std::generate(w83.begin(), w83.end(), std::ref(f32rng));
  std::generate(w84.begin(), w84.end(), std::ref(f32rng));
  std::generate(w85.begin(), w85.end(), std::ref(f32rng));

  ExecutionPlan operators;
  xnn_status status;
  xnn_code_cache* code_cache_ptr = nullptr;
#if XNN_PLATFORM_JIT
  xnn_code_cache code_cache;
  if (use_jit) {
    status = xnn_init_code_cache(&code_cache);
    if (status != xnn_status_success) {
      std::cerr << "failed to initialize code cache" << std::endl;
      return ExecutionPlan();
    }
    code_cache_ptr = &code_cache;
  }
#endif  // XNN_PLATFORM_JIT

  xnn_operator_t op0 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 0 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    2 /* subsampling height */, 2 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    3 /* input channels per group */,
    32 /* output_channels_per_group */,
    3 /* input pixel stride */,
    32 /* output pixel stride */,
    w30.data(), w31.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op0);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #0" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op0, xnn_delete_operator);

  xnn_operator_t op1 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    32 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    32 /* input pixel stride */,
    32 /* output pixel stride */,
    w32.data(), w33.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op1);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #1" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op1, xnn_delete_operator);

  xnn_operator_t op2 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    32 /* input channels per group */,
    64 /* output_channels_per_group */,
    32 /* input pixel stride */,
    64 /* output pixel stride */,
    w34.data(), w35.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op2);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #2" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op2, xnn_delete_operator);

  xnn_operator_t op3 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 0 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    2 /* subsampling height */, 2 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    64 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    64 /* input pixel stride */,
    64 /* output pixel stride */,
    w36.data(), w37.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op3);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #3" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op3, xnn_delete_operator);

  xnn_operator_t op4 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    64 /* input channels per group */,
    128 /* output_channels_per_group */,
    64 /* input pixel stride */,
    128 /* output pixel stride */,
    w38.data(), w39.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op4);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #4" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op4, xnn_delete_operator);

  xnn_operator_t op5 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    128 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    128 /* input pixel stride */,
    128 /* output pixel stride */,
    w40.data(), w41.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op5);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #5" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op5, xnn_delete_operator);

  xnn_operator_t op6 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    128 /* input channels per group */,
    128 /* output_channels_per_group */,
    128 /* input pixel stride */,
    128 /* output pixel stride */,
    w42.data(), w43.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op6);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #6" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op6, xnn_delete_operator);

  xnn_operator_t op7 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 0 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    2 /* subsampling height */, 2 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    128 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    128 /* input pixel stride */,
    128 /* output pixel stride */,
    w44.data(), w45.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op7);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #7" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op7, xnn_delete_operator);

  xnn_operator_t op8 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    128 /* input channels per group */,
    256 /* output_channels_per_group */,
    128 /* input pixel stride */,
    256 /* output pixel stride */,
    w46.data(), w47.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op8);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #8" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op8, xnn_delete_operator);

  xnn_operator_t op9 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    256 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    256 /* input pixel stride */,
    256 /* output pixel stride */,
    w48.data(), w49.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op9);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #9" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op9, xnn_delete_operator);

  xnn_operator_t op10 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    256 /* input channels per group */,
    256 /* output_channels_per_group */,
    256 /* input pixel stride */,
    256 /* output pixel stride */,
    w50.data(), w51.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op10);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #10" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op10, xnn_delete_operator);

  xnn_operator_t op11 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 0 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    2 /* subsampling height */, 2 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    256 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    256 /* input pixel stride */,
    256 /* output pixel stride */,
    w52.data(), w53.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op11);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #11" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op11, xnn_delete_operator);

  xnn_operator_t op12 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    256 /* input channels per group */,
    512 /* output_channels_per_group */,
    256 /* input pixel stride */,
    512 /* output pixel stride */,
    w54.data(), w55.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op12);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #12" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op12, xnn_delete_operator);

  xnn_operator_t op13 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    512 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w56.data(), w57.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op13);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #13" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op13, xnn_delete_operator);

  xnn_operator_t op14 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    512 /* input channels per group */,
    512 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w58.data(), w59.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op14);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #14" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op14, xnn_delete_operator);

  xnn_operator_t op15 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    512 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w60.data(), w61.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op15);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #15" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op15, xnn_delete_operator);

  xnn_operator_t op16 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    512 /* input channels per group */,
    512 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w62.data(), w63.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op16);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #16" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op16, xnn_delete_operator);

  xnn_operator_t op17 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    512 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w64.data(), w65.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op17);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #17" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op17, xnn_delete_operator);

  xnn_operator_t op18 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    512 /* input channels per group */,
    512 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w66.data(), w67.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op18);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #18" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op18, xnn_delete_operator);

  xnn_operator_t op19 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    512 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w68.data(), w69.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op19);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #19" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op19, xnn_delete_operator);

  xnn_operator_t op20 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    512 /* input channels per group */,
    512 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w70.data(), w71.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op20);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #20" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op20, xnn_delete_operator);

  xnn_operator_t op21 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    512 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w72.data(), w73.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op21);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #21" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op21, xnn_delete_operator);

  xnn_operator_t op22 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    512 /* input channels per group */,
    512 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w74.data(), w75.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op22);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #22" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op22, xnn_delete_operator);

  xnn_operator_t op23 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 0 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    2 /* subsampling height */, 2 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    512 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    512 /* input pixel stride */,
    512 /* output pixel stride */,
    w76.data(), w77.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op23);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #23" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op23, xnn_delete_operator);

  xnn_operator_t op24 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    512 /* input channels per group */,
    1024 /* output_channels_per_group */,
    512 /* input pixel stride */,
    1024 /* output pixel stride */,
    w78.data(), w79.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op24);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #24" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op24, xnn_delete_operator);

  xnn_operator_t op25 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    1 /* top padding */, 1 /* right padding */,
    1 /* bottom padding */, 1 /* left padding */,
    3 /* kernel height */, 3 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1024 /* groups */,
    1 /* input channels per group */,
    1 /* output_channels_per_group */,
    1024 /* input pixel stride */,
    1024 /* output pixel stride */,
    w80.data(), w81.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op25);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #25" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op25, xnn_delete_operator);

  xnn_operator_t op26 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    1024 /* input channels per group */,
    1024 /* output_channels_per_group */,
    1024 /* input pixel stride */,
    1024 /* output pixel stride */,
    w82.data(), w83.data(),
    0.0f /* output min */, 6.0f /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op26);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #26" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op26, xnn_delete_operator);

  xnn_operator_t op27 = nullptr;
  status = xnn_create_global_average_pooling_nwc_f32(
    1024 /* channels */, 1024 /* input stride */, 1024 /* output stride */,
    -std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(),
    0 /* flags */,
    &op27);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #27" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op27, xnn_delete_operator);

  xnn_operator_t op28 = nullptr;
  status = xnn_create_convolution2d_nhwc_f32(
    0 /* top padding */, 0 /* right padding */,
    0 /* bottom padding */, 0 /* left padding */,
    1 /* kernel height */, 1 /* kernel width */,
    1 /* subsampling height */, 1 /* subsampling width */,
    1 /* dilation_height */, 1 /* dilation_width */,
    1 /* groups */,
    1024 /* input channels per group */,
    1001 /* output_channels_per_group */,
    1024 /* input pixel stride */,
    1001 /* output pixel stride */,
    w84.data(), w85.data(),
    -std::numeric_limits<float>::infinity() /* output min */, std::numeric_limits<float>::infinity() /* output max */,
    0 /* flags */,
    code_cache_ptr,
    nullptr,
    &op28);
  if (status != xnn_status_success) {
    std::cerr << "failed to create operation #28" << std::endl;
    return ExecutionPlan();
  }
  operators.emplace_back(op28, xnn_delete_operator);

#if XNN_PLATFORM_JIT
  if (use_jit) {
    xnn_finalize_code_memory(&code_cache.cache.code);
  }
#endif  // XNN_PLATFORM_JIT

  size_t workspace_size, workspace_alignment;
  status = xnn_reshape_convolution2d_nhwc_f32(
    op0,
    /*batch_size=*/1, /*input_height=*/224, /*input_width=*/224,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #0" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op1,
    /*batch_size=*/1, /*input_height=*/112, /*input_width=*/112,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #1" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op2,
    /*batch_size=*/1, /*input_height=*/112, /*input_width=*/112,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #2" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op3,
    /*batch_size=*/1, /*input_height=*/112, /*input_width=*/112,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #3" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op4,
    /*batch_size=*/1, /*input_height=*/56, /*input_width=*/56,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #4" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op5,
    /*batch_size=*/1, /*input_height=*/56, /*input_width=*/56,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #5" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op6,
    /*batch_size=*/1, /*input_height=*/56, /*input_width=*/56,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #6" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op7,
    /*batch_size=*/1, /*input_height=*/56, /*input_width=*/56,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #7" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op8,
    /*batch_size=*/1, /*input_height=*/28, /*input_width=*/28,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #8" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op9,
    /*batch_size=*/1, /*input_height=*/28, /*input_width=*/28,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #9" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op10,
    /*batch_size=*/1, /*input_height=*/28, /*input_width=*/28,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #10" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op11,
    /*batch_size=*/1, /*input_height=*/28, /*input_width=*/28,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #11" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op12,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #12" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op13,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #13" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op14,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #14" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op15,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #15" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op16,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #16" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op17,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #17" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op18,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #18" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op19,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #19" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op20,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #20" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op21,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #21" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op22,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #22" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op23,
    /*batch_size=*/1, /*input_height=*/14, /*input_width=*/14,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #23" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op24,
    /*batch_size=*/1, /*input_height=*/7, /*input_width=*/7,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #24" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op25,
    /*batch_size=*/1, /*input_height=*/7, /*input_width=*/7,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #25" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op26,
    /*batch_size=*/1, /*input_height=*/7, /*input_width=*/7,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #26" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_global_average_pooling_nwc_f32(
    op27,
    /*batch_size=*/1, 49 /* width */,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #27" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_reshape_convolution2d_nhwc_f32(
    op28,
    /*batch_size=*/1, /*input_height=*/1, /*input_width=*/1,
    /*output_height_out=*/nullptr, /*output_width_out=*/nullptr,
    &workspace_size, &workspace_alignment,
    /*threadpool=*/threadpool);
  if (status != xnn_status_success) {
    std::cerr << "failed to reshape operation #28" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op0,
    /*workspace=*/nullptr, /*input=*/v0.data(), /*output=*/v1.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #0" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op1,
    /*workspace=*/nullptr, /*input=*/v1.data(), /*output=*/v2.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #1" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op2,
    /*workspace=*/nullptr, /*input=*/v2.data(), /*output=*/v3.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #2" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op3,
    /*workspace=*/nullptr, /*input=*/v3.data(), /*output=*/v4.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #3" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op4,
    /*workspace=*/nullptr, /*input=*/v4.data(), /*output=*/v5.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #4" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op5,
    /*workspace=*/nullptr, /*input=*/v5.data(), /*output=*/v6.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #5" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op6,
    /*workspace=*/nullptr, /*input=*/v6.data(), /*output=*/v7.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #6" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op7,
    /*workspace=*/nullptr, /*input=*/v7.data(), /*output=*/v8.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #7" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op8,
    /*workspace=*/nullptr, /*input=*/v8.data(), /*output=*/v9.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #8" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op9,
    /*workspace=*/nullptr, /*input=*/v9.data(), /*output=*/v10.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #9" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op10,
    /*workspace=*/nullptr, /*input=*/v10.data(), /*output=*/v11.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #10" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op11,
    /*workspace=*/nullptr, /*input=*/v11.data(), /*output=*/v12.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #11" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op12,
    /*workspace=*/nullptr, /*input=*/v12.data(), /*output=*/v13.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #12" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op13,
    /*workspace=*/nullptr, /*input=*/v13.data(), /*output=*/v14.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #13" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op14,
    /*workspace=*/nullptr, /*input=*/v14.data(), /*output=*/v15.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #14" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op15,
    /*workspace=*/nullptr, /*input=*/v15.data(), /*output=*/v16.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #15" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op16,
    /*workspace=*/nullptr, /*input=*/v16.data(), /*output=*/v17.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #16" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op17,
    /*workspace=*/nullptr, /*input=*/v17.data(), /*output=*/v18.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #17" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op18,
    /*workspace=*/nullptr, /*input=*/v18.data(), /*output=*/v19.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #18" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op19,
    /*workspace=*/nullptr, /*input=*/v19.data(), /*output=*/v20.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #19" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op20,
    /*workspace=*/nullptr, /*input=*/v20.data(), /*output=*/v21.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #20" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op21,
    /*workspace=*/nullptr, /*input=*/v21.data(), /*output=*/v22.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #21" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op22,
    /*workspace=*/nullptr, /*input=*/v22.data(), /*output=*/v23.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #22" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op23,
    /*workspace=*/nullptr, /*input=*/v23.data(), /*output=*/v24.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #23" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op24,
    /*workspace=*/nullptr, /*input=*/v24.data(), /*output=*/v25.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #24" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op25,
    /*workspace=*/nullptr, /*input=*/v25.data(), /*output=*/v26.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #25" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op26,
    /*workspace=*/nullptr, /*input=*/v26.data(), /*output=*/v27.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #26" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_global_average_pooling_nwc_f32(
    op27,
    /*input=*/v27.data(), /*output=*/v28.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #27" << std::endl;
    return ExecutionPlan();
  }

  status = xnn_setup_convolution2d_nhwc_f32(
    op28,
    /*workspace=*/nullptr, /*input=*/v28.data(), /*output=*/v29.data());
  if (status != xnn_status_success) {
    std::cerr << "failed to setup operation #28" << std::endl;
    return ExecutionPlan();
  }

  XNN_PRAGMA_CLANG("clang diagnostic push")
  XNN_PRAGMA_CLANG("clang diagnostic ignored \"-Wpessimizing-move\"")
  return operators;
  XNN_PRAGMA_CLANG("clang diagnostic pop")
}

ExecutionPlan FP32MobileNetV1(pthreadpool_t threadpool) {
  return FP32MobileNetV1(false, threadpool);
}

ExecutionPlan FP32MobileNetV1Jit(pthreadpool_t threadpool) {
  return FP32MobileNetV1(true, threadpool);
}

}  // namespace models
