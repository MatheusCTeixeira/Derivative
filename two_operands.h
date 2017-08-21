#include "function.h"

#ifndef _TWO_OPERANDS_
#define _TWO_OPERANDS_

namespace m_math
{
    class two_operands
    {
    public:
        two_operands(function * lop, function * rop);
        
        void set_left_operand(function * lop);
        function * left_operand() const;

        void set_right_operand(function * rop);
        function * right_operand() const;

        ~two_operands();
    private:
        function * m_lop;
        function * m_rop;       

    };
}

#endif