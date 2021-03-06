#include "../include/pow.hpp"

namespace m_math
{
    pow::pow(const function& lop, const function& rop):pow{lop.clone(), rop.clone()}
    {

    }

    pow::pow(function * lop, function * rop):function{}, two_operands{lop, rop}
    {

    }

    function * pow::clone() const
    {
        return new pow{this->left_operand()->clone(), this->right_operand()->clone()};
    }

    std::string pow::derivate(std::string var) const
    {
        try
        {
            return std::string{"("}+this->right_operand()->to_string()+std::string{"*"}+this->left_operand()->to_string()+std::string{")^"}+std::to_string(std::stod(this->right_operand()->to_string(), nullptr)-1)+std::string{"*"}+this->left_operand()->derivate(var);
        }
        catch(std::invalid_argument e)
        {
            return this->right_operand()->to_string()+std::string{"*("}+this->left_operand()->to_string()+std::string{")^("}+this->right_operand()->to_string()+std::string{"-1)*"}+this->left_operand()->derivate(var);
        }

    }

    std::string pow::to_string() const
    {
        return this->left_operand()->to_string()+std::string{"^"}+this->right_operand()->to_string();
    }
}