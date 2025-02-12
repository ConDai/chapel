/*
 * Copyright 2021-2022 Hewlett Packard Enterprise Development LP
 * Other additional copyright holders may be indicated within.
 *
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CHPL_UAST_ERRONEOUSEXPRESSION_H
#define CHPL_UAST_ERRONEOUSEXPRESSION_H

#include "chpl/uast/Expression.h"
#include "chpl/queries/Location.h"

namespace chpl {
namespace uast {


/**
  This class represents some missing AST due to an error.
 */
class ErroneousExpression final : public Expression {
 private:
  ErroneousExpression()
    : Expression(asttags::ErroneousExpression) {
  }
  bool contentsMatchInner(const ASTNode* other) const override {
    const ErroneousExpression* lhs = this;
    const ErroneousExpression* rhs = (const ErroneousExpression*) other;
    return lhs->expressionContentsMatchInner(rhs);
  }
  void markUniqueStringsInner(Context* context) const override {
    expressionMarkUniqueStringsInner(context);
  }

 public:
  ~ErroneousExpression() = default;
  static owned<ErroneousExpression> build(Builder* builder, Location loc);
};


} // end namespace uast
} // end namespace chpl

#endif
