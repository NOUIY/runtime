/*
 * Copyright 2022 The TensorFlow Runtime Authors
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

#ifndef TFRT_BACKENDS_JITRT_CUSTOM_CALLS_CUSTOM_CALLS_TESTLIB_H_
#define TFRT_BACKENDS_JITRT_CUSTOM_CALLS_CUSTOM_CALLS_TESTLIB_H_

#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/Mangling.h"
#include "mlir/IR/Dialect.h"

// clang-format off
#include "tfrt/jitrt/custom_calls/custom_call_testlib_enums.h.inc"
// clang-format on

#define GET_ATTRDEF_CLASSES
#include "tfrt/jitrt/custom_calls/custom_call_testlib_attrs.h.inc"

namespace tfrt {
namespace jitrt {

class CustomCallAttrEncodingSet;

class TestlibDialect : public mlir::Dialect {
 public:
  explicit TestlibDialect(mlir::MLIRContext *context);

  static llvm::StringRef getDialectNamespace() { return "testlib"; }

  // Parses an attribute registered to this dialect.
  mlir::Attribute parseAttribute(mlir::DialectAsmParser &parser,
                                 mlir::Type type) const override;

  // Prints an attribute registered to this dialect.
  void printAttribute(mlir::Attribute attr,
                      mlir::DialectAsmPrinter &os) const override;
};

llvm::orc::SymbolMap CustomCallsTestlibSymbolMap(
    llvm::orc::MangleAndInterner mangle);

// Declare runtime enums corresponding to compile time enums to test
// attributes enum conversion.
enum class RuntimeEnumType : uint32_t { kFoo, kBar, kBaz };

// Populate encoding for custom dialect attributes (enums and structs).
void PopulateCustomCallAttrEncoding(CustomCallAttrEncodingSet &encoding);

}  // namespace jitrt
}  // namespace tfrt

#endif  // TFRT_BACKENDS_JITRT_CUSTOM_CALLS_CUSTOM_CALLS_TESTLIB_H_
