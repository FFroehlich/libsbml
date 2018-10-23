/**
 * \file   TestValidator.cpp
 * \brief  Validator unit tests
 * \author Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 * 
 * Copyright 2011-2012 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#ifndef TestValidator_h
#define TestValidator_h


#ifdef __cplusplus


#include <vector>
#include <sbml/validator/Validator.h>

LIBSBML_CPP_NAMESPACE_USE

class TestFile;

class TestValidator
{
public:

   TestValidator (Validator& v);
  ~TestValidator ();

  /**
   * @return true if the Validator behaved as expected when validating
   * TestFile, false otherwise.
   */
  bool test (const TestFile& file);


private:

  /**
   * @return true if the all Validator messages for the given Constraint id
   * test cases should be printed, false otherwise.
   */
  bool isVerbose (unsigned int id);

  /**
   * Reads the environment variable 'LIBSBML_TEST_VALIDATOR_VERBOSE' and
   * sets the internal verbose state accordingly.
   *
   * LIBSBML_TEST_VALIDATOR_VERBOSE may either be set to 'all' (case
   * sensitive) or a space separated list of constraint ids.
   */
  void readVerboseFromEnvironment ();


  Validator& mValidator;

  bool                      mVerboseAll;
  std::vector<unsigned int> mVerboseConstraintIds;
};


#endif  /* __cplusplus */
#endif  /* TestValidator_h */
