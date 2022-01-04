/*
 * Copyright 2021 The TensorFlow Runtime Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TFRT_BACKENDS_CPU_JIT_TRANSFORMS_CODEGEN_PASSES_H_
#define TFRT_BACKENDS_CPU_JIT_TRANSFORMS_CODEGEN_PASSES_H_

#include <memory>

#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Vector/VectorOps.h"
#include "mlir/Dialect/X86Vector/X86VectorDialect.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Pass/Pass.h"

namespace tfrt {
namespace cpu {
namespace jit {

std::unique_ptr<mlir::FunctionPass> CreateMathOptimizationPass(
    bool enable_avx2 = false);

std::unique_ptr<mlir::FunctionPass> CreateRewriteVectorMultiReductionPass();

#define GEN_PASS_REGISTRATION
#include "tfrt/cpu/jit/transforms/codegen_gen_passes.h.inc"

}  // namespace jit
}  // namespace cpu
}  // namespace tfrt

#endif  // TFRT_BACKENDS_CPU_JIT_TRANSFORMS_CODEGEN_PASSES_H_