/**
 * @file    ASTNodeType.h
 * @brief   Enumeration for Abstract Syntax Tree (AST).
 * @author  Sarah M Keating
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#ifndef ASTNodeType_h
#define ASTNodeType_h


#include <sbml/common/libsbml-namespace.h>
#include <sbml/common/extern.h>


LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

typedef enum
{
  EM_L3V2        /*!< Extended math added in l3v2 */
  , EM_DISTRIB   /*!< Extended math added by the 'distrib' package */
  , EM_ARRAYS    /*!< Extended math added by the 'arrays' package */
  , EM_REMAINING /*!< Extended math not added by any other package */

  , EM_UNKNOWN /*!< Unknown node:  will not produce any MathML */
} ExtendedMathType_t;

typedef enum
{
  ALLOWED_CHILDREN_ANY       /*!< Any number of children (0+) are allowed */
  , ALLOWED_CHILDREN_ATLEAST  /*!< Any number of children above some minimum are allowed */

  , ALLOWED_CHILDREN_EXACTLY /*!< Only specific number(s) of children are allowed */
  , ALLOWED_CHILDREN_UNKNOWN
} AllowedChildrenType_t;

/**
 * @enum  ASTNodeType_t
 * @brief ASTNodeType_t is the enumeration of possible
 * @if conly ASTNode_t @else ASTNode @endif types.
 *
 * @copydetails doc_astnode_types
 * 
 * @see @if conly ASTNode_getType() @else ASTNode::getType() @endif
 * @see @if conly ASTNode_canonicalize() @else ASTNode::canonicalize() @endif
 */
typedef enum
{
    AST_PLUS    = 43 /*!< Plus (MathML <code>&lt;plus&gt;</code>) */
  , AST_MINUS   = 45 /*!< Minus (MathML <code>&lt;minus&gt;</code>) */
  , AST_TIMES   = 42 /*!< Times (MathML <code>&lt;times&gt;</code>) */
  , AST_DIVIDE  = 47 /*!< Divide (MathML <code>&lt;divide&gt;</code>) */
  , AST_POWER   = 94 /*!< Power (MathML <code>&lt;power&gt;</code>) */

  , AST_INTEGER = 256 /*!< Integer (MathML <code>&lt;cn type="integer"&gt;</code>) */
  , AST_REAL /*!< Real (MathML <code>&lt;cn&gt;</code>) */
  , AST_REAL_E /*!< Real number with e-notation (MathML <code>&lt;cn type="e-notation"&gt; [number] &lt;sep/&gt; [number] &lt;/cn&gt;</code>) */
  , AST_RATIONAL /*!< Rational (MathML <code>&lt;cn type="rational"&gt; [number] &lt;sep/&gt; [number] &lt;cn&gt;</code>) */

  , AST_NAME /*!< A named node (MathML <code>&lt;ci&gt;</code>) */
  , AST_NAME_AVOGADRO /*!< Avogadro (MathML <code>&lt;ci encoding="text" definitionURL="http://www.sbml.org/sbml/symbols/avogadro"&gt;</code>) */
  , AST_NAME_TIME /*!< Time (MathML <code>&lt;ci encoding="text" definitionURL="http://www.sbml.org/sbml/symbols/time"&gt;</code>) */

  , AST_CONSTANT_E /*!< Exponential E (MathML <code>&lt;exponentiale&gt;</code>) */
  , AST_CONSTANT_FALSE /*!< False (MathML <code>&lt;false&gt;</code>) */
  , AST_CONSTANT_PI /*!< Pi (MathML <code>&lt;pi&gt;</code>) */
  , AST_CONSTANT_TRUE /*!< True (MathML <code>&lt;true&gt;</code>) */

  , AST_LAMBDA /*!< Lambda (MathML <code>&lt;lambda&gt;</code>) */

  , AST_FUNCTION /*!< User-defined function (MathML <code>&lt;apply&gt;</code>) */
  , AST_FUNCTION_ABS /*!< Absolute value (MathML <code>&lt;abs&gt;</code>) */
  , AST_FUNCTION_ARCCOS /*!< Arccosine (MathML <code>&lt;arccos&gt;</code>) */
  , AST_FUNCTION_ARCCOSH /*!< Hyperbolic arccosine (MathML <code>&lt;arccosh&gt;</code>) */
  , AST_FUNCTION_ARCCOT /*!< Arccotangent (MathML <code>&lt;arccot&gt;</code>) */
  , AST_FUNCTION_ARCCOTH /*!< Hyperbolic arccotangent (MathML <code>&lt;arccoth&gt;</code>) */
  , AST_FUNCTION_ARCCSC /*!< Arccosecant (MathML <code>&lt;arccsc&gt;</code>) */
  , AST_FUNCTION_ARCCSCH /*!< Hyperbolic arccosecant (MathML <code>&lt;arccsch&gt;</code>) */
  , AST_FUNCTION_ARCSEC /*!< Arcsecant (MathML <code>&lt;arcsec&gt;</code>) */
  , AST_FUNCTION_ARCSECH /*!< Hyperbolic arcsecant (MathML <code>&lt;arcsech&gt;</code>) */
  , AST_FUNCTION_ARCSIN /*!< Arcsine (MathML <code>&lt;arcsin&gt;</code>) */
  , AST_FUNCTION_ARCSINH /*!< Hyperbolic arcsine (MathML <code>&lt;arcsinh&gt;</code>) */
  , AST_FUNCTION_ARCTAN /*!< Arctangent (MathML <code>&lt;arctan&gt;</code>) */
  , AST_FUNCTION_ARCTANH /*!< Hyperbolic arctangent (MathML <code>&lt;arctanh&gt;</code>) */
  , AST_FUNCTION_CEILING /*!< Ceiling (MathML <code>&lt;ceiling&gt;</code>) */
  , AST_FUNCTION_COS /*!< Cosine (MathML <code>&lt;cosine&gt;</code>) */
  , AST_FUNCTION_COSH /*!< Hyperbolic cosine (MathML <code>&lt;cosh&gt;</code>) */
  , AST_FUNCTION_COT /*!< Cotangent (MathML <code>&lt;cot&gt;</code>) */
  , AST_FUNCTION_COTH /*!< Hyperbolic cotangent (MathML <code>&lt;coth&gt;</code>) */
  , AST_FUNCTION_CSC /*!< Cosecant (MathML <code>&lt;csc&gt;</code>) */
  , AST_FUNCTION_CSCH /*!< Hyperbolic cosecant (MathML <code>&lt;csch&gt;</code>) */
  , AST_FUNCTION_DELAY /*!< %Delay (MathML <code>&lt;csymbol encoding="text" definitionURL="http://www.sbml.org/sbml/symbols/delay"&gt;</code>) */
  , AST_FUNCTION_EXP /*!< Exponential (MathML <code>&lt;exp&gt;</code>) */
  , AST_FUNCTION_FACTORIAL /*!< Factorial (MathML <code>&lt;factorial&gt;</code>) */
  , AST_FUNCTION_FLOOR /*!< Floor (MathML <code>&lt;floor&gt;</code>) */
  , AST_FUNCTION_LN /*!< Natural Log (MathML <code>&lt;ln&gt;</code>) */
  , AST_FUNCTION_LOG /*!< Log (MathML <code>&lt;log&gt;</code>) */
  , AST_FUNCTION_PIECEWISE /*!< Piecewise (MathML <code>&lt;piecewise&gt;</code>) */
  , AST_FUNCTION_POWER /*!< Power (MathML <code>&lt;power&gt;</code>) */
  , AST_FUNCTION_ROOT /*!< Root (MathML <code>&lt;root&gt;</code>) */
  , AST_FUNCTION_SEC /*!< Secant (MathML <code>&lt;sec&gt;</code>) */
  , AST_FUNCTION_SECH /*!< Hyperbolic secant (MathML <code>&lt;sech&gt;</code>) */
  , AST_FUNCTION_SIN /*!< Sine (MathML <code>&lt;sin&gt;</code>) */
  , AST_FUNCTION_SINH /*!< Hyperbolic sine (MathML <code>&lt;sinh&gt;</code>) */
  , AST_FUNCTION_TAN /*!< Tangent (MathML <code>&lt;tan&gt;</code>) */
  , AST_FUNCTION_TANH /*!< Hyperbolic tangent (MathML <code>&lt;tanh&gt;</code>) */

  , AST_LOGICAL_AND /*!< Logical and (MathML <code>&lt;and&gt;</code>) */
  , AST_LOGICAL_NOT /*!< Logical not (MathML <code>&lt;not&gt;</code>) */
  , AST_LOGICAL_OR /*!< Logical or (MathML <code>&lt;or&gt;</code>) */
  , AST_LOGICAL_XOR /*!< Logical exclusive or (MathML <code>&lt;xor&gt;</code>) */

  , AST_RELATIONAL_EQ /*!< Equal (MathML <code>&lt;eq&gt;</code>) */
  , AST_RELATIONAL_GEQ /*!< Greater than or equal (MathML <code>&lt;geq&gt;</code>) */
  , AST_RELATIONAL_GT /*!< Greater than (MathML <code>&lt;gt&gt;</code>) */
  , AST_RELATIONAL_LEQ /*!< Less than or equal (MathML <code>&lt;leq&gt;</code>) */
  , AST_RELATIONAL_LT /*!< Less than (MathML <code>&lt;lt&gt;</code>) */
  , AST_RELATIONAL_NEQ /*!< Not equal (MathML <code>&lt;neq&gt;</code>) */

  , AST_END_OF_CORE = 315
  /* L3V2 */
  , AST_FUNCTION_MAX = 320
  , AST_FUNCTION_MIN
  , AST_FUNCTION_QUOTIENT
  , AST_FUNCTION_RATE_OF
  , AST_FUNCTION_REM
  , AST_LOGICAL_IMPLIES

  /* generic to facilitate non sbml libraries*/
  , AST_CSYMBOL_FUNCTION = 400

  /* Distrib */
  , AST_DISTRIB_FUNCTION_NORMAL = 500
  , AST_DISTRIB_FUNCTION_UNIFORM
  , AST_DISTRIB_FUNCTION_BERNOULLI
  , AST_DISTRIB_FUNCTION_BINOMIAL
  , AST_DISTRIB_FUNCTION_CAUCHY
  , AST_DISTRIB_FUNCTION_CHISQUARE
  , AST_DISTRIB_FUNCTION_EXPONENTIAL
  , AST_DISTRIB_FUNCTION_GAMMA
  , AST_DISTRIB_FUNCTION_LAPLACE
  , AST_DISTRIB_FUNCTION_LOGNORMAL
  , AST_DISTRIB_FUNCTION_POISSON
  , AST_DISTRIB_FUNCTION_RAYLEIGH

  /* Arrays */
  , AST_LINEAR_ALGEBRA_VECTOR = 600
  , AST_LINEAR_ALGEBRA_SELECTOR

  /* Other linear algebra elements that are not (yet?) in the 'arrays' package */
  , AST_LINEAR_ALGEBRA_MATRIX
  , AST_LINEAR_ALGEBRA_MATRIXROW
  , AST_LINEAR_ALGEBRA_DETERMINANT
  , AST_LINEAR_ALGEBRA_TRANSPOSE
  , AST_LINEAR_ALGEBRA_VECTOR_PRODUCT
  , AST_LINEAR_ALGEBRA_SCALAR_PRODUCT
  , AST_LINEAR_ALGEBRA_OUTER_PRODUCT

  /* Arithmetic logic */
  , AST_LOGICAL_EXISTS = 700
  , AST_LOGICAL_FORALL

  /* Statistics*/
  , AST_STATISTICS_MEAN = 800
  , AST_STATISTICS_MEDIAN
  , AST_STATISTICS_MODE
  , AST_STATISTICS_MOMENT
  , AST_STATISTICS_SDEV
  , AST_STATISTICS_VARIANCE
  , AST_STATISTICS_MOMENTABOUT

  /* Sequences and Series*/
  , AST_SERIES_PRODUCT = 900
  , AST_SERIES_SUM
  , AST_SERIES_LIMIT
  , AST_SERIES_TENDSTO

  /* Arithmetic algebra */
  , AST_ALGEBRA_GCD = 1000
  , AST_ALGEBRA_CONJUGATE
  , AST_ALGEBRA_ARG
  , AST_ALGEBRA_REAL
  , AST_ALGEBRA_IMAGINARY
  , AST_ALGEBRA_LCM

  /* Relations */
  , AST_RELATIONS_EQUIVALENT = 1100
  , AST_RELATIONS_APPROX
  , AST_RELATIONS_FACTOROF

  /* Calculus and vector calculus*/
  , AST_CALCULUS_INT = 1200
  , AST_CALCULUS_DIFF
  , AST_CALCULUS_PARTIALDIFF
  , AST_CALCULUS_LOWLIMIT
  , AST_CALCULUS_UPLIMIT
  , AST_CALCULUS_DIVERGENCE
  , AST_CALCULUS_GRAD
  , AST_CALCULUS_CURL
  , AST_CALCULUS_LAPLACIAN

  /* Set Theory */
  , AST_SET_THEORY_SET = 1300
  , AST_SET_THEORY_LIST
  , AST_SET_THEORY_UNION
  , AST_SET_THEORY_INTERSECT
  , AST_SET_THEORY_IN
  , AST_SET_THEORY_NOTIN
  , AST_SET_THEORY_SUBSET
  , AST_SET_THEORY_PRSUBSET
  , AST_SET_THEORY_NOTSUBSET
  , AST_SET_THEORY_NOTPRSUBSET
  , AST_SET_THEORY_SETDIFF
  , AST_SET_THEORY_CARD
  , AST_SET_THEORY_CARTESIANPRODUCT

  /* Constants and symbol elements*/
  , AST_CONSTANT_IMAGINARYI = 1400
  , AST_CONSTANTS_INTEGERS
  , AST_CONSTANTS_REALS
  , AST_CONSTANTS_RATIONALS
  , AST_CONSTANTS_NATURALNUMBERS
  , AST_CONSTANTS_COMPLEXES
  , AST_CONSTANTS_PRIMES
  , AST_CONSTANTS_EMPTYSET
  , AST_CONSTANTS_EULERGAMMA

  /* Basic MathML Content elements*/
  , AST_BASIC_CONTENT_INTERVAL = 1500
  , AST_BASIC_CONTENT_INVERSE
  , AST_BASIC_CONTENT_CONDITION
  , AST_BASIC_CONTENT_DECLARE
  , AST_BASIC_CONTENT_COMPOSE
  , AST_BASIC_CONTENT_IDENT
  , AST_BASIC_CONTENT_DOMAIN
  , AST_BASIC_CONTENT_CODOMAIN
  , AST_BASIC_CONTENT_IMAGE
  , AST_BASIC_CONTENT_DOMAINOFAPPLICATION

  , AST_UNKNOWN  = 9999/*!< Unknown node:  will not produce any MathML */
} ASTNodeType_t;

END_C_DECLS
LIBSBML_CPP_NAMESPACE_END


#endif  /* ASTNodeType_h */

