// EvalRule.cpp ---
//
// Filename: EvalRule.cpp
// Author: Abhishek Udupa
// Created: Wed Jan 15 14:54:17 2014 (-0500)
//
//
// Copyright (c) 2013, Abhishek Udupa, University of Pennsylvania
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. All advertising materials mentioning features or use of this software
//    must display the following acknowledgement:
//    This product includes software developed by The University of Pennsylvania
// 4. Neither the name of the University of Pennsylvania nor the
//    names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//

// Code:


#include "EvalRule.hpp"
#include "../descriptions/Operators.hpp"
#include "../z3interface/Z3Objects.hpp"
#include "../z3interface/TheoremProver.hpp"
#include "../descriptions/ESType.hpp"

namespace ESolver {

    EvalRule::EvalRule()
        : LHS(NULL), RHS()
    {
        // Nothing here
    }

    EvalRule::EvalRule(const AuxVarOperator* LHS,
                       const Expression& RHS)
        : LHS(LHS), RHS(RHS)
    {
        // Nothing here
    }

    EvalRule::EvalRule(const EvalRule& Other)
        : EvalRule(Other.LHS, Other.RHS)
    {
        // Nothing here
    }

    EvalRule::~EvalRule()
    {
        // Nothing here
    }

    EvalRule& EvalRule::operator = (const EvalRule& Other)
    {
        if(&Other == this) {
            return *this;
        }

        LHS = Other.LHS;
        RHS = Other.RHS;
        return *this;
    }

    const AuxVarOperator* EvalRule::GetLHS() const
    {
        return LHS;
    }

    const Expression& EvalRule::GetRHS() const
    {
        return RHS;
    }

    void EvalRule::Evaluate(ExpSubstMap SubstExps,
                            VariableMap VarMap,
                            ConcreteValueBase* Result) const
    {
        RHS->Evaluate(SubstExps, VarMap, Result);
    }

    SMTExpr EvalRule::ToSMT(TheoremProver* TP, ExpSubstMap SubstExps,
                            const vector<SMTExpr>& BaseExprs,
                            vector<SMTExpr>& Assumptions) const
    {
        auto LHSSMTExpr = TP->CreateVarExpr(LHS->GetName(), LHS->GetEvalType()->GetSMTType());
        return TP->CreateEQExpr(LHSSMTExpr, RHS->ToSMT(TP, SubstExps, BaseExprs, Assumptions));
    }

    string EvalRule::ToString() const
    {
        ostringstream sstr;
        sstr << "EvalRule: " << LHS->GetName() << " = " << RHS->ToString();
        return sstr.str();
    }

    ostream& operator << (ostream& str, const EvalRule& Rule)
    {
        str << Rule.ToString();
        return str;
    }

} /* End namespace */


//
// EvalRule.cpp ends here
