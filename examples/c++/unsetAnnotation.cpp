/**
 * @file    unsetAnnotation.cpp
 * @brief   unset annotation for each element
 * @author  Akiya Jouraku
 *
 * <!--------------------------------------------------------------------------
 * This sample program is distributed under a different license than the rest
 * of libSBML.  This program uses the open-source MIT license, as follows:
 *
 * Copyright (c) 2013-2018 by the California Institute of Technology
 * (California, USA), the European Bioinformatics Institute (EMBL-EBI, UK)
 * and the University of Heidelberg (Germany), with support from the National
 * Institutes of Health (USA) under grant R01GM070923.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Neither the name of the California Institute of Technology (Caltech), nor
 * of the European Bioinformatics Institute (EMBL-EBI), nor of the University
 * of Heidelberg, nor the names of any contributors, may be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 * ------------------------------------------------------------------------ -->
 */


#include <iostream>

#include <sbml/SBMLTypes.h>
#include "util.h"


using namespace std;
LIBSBML_CPP_NAMESPACE_USE

int
main (int argc, char* argv[])
{
  if (argc != 3)
  {
    cout << endl << "Usage: unsetAnnotation <input-filename> <output-filename>" << endl << endl;
    return 1;
  }

  unsigned int i,j;
  const char* filename   = argv[1];
  SBMLDocument* document;
  SBMLReader reader;

  document = reader.readSBML(filename);

  unsigned int errors = document->getNumErrors();

  if(errors > 0)
  {
    document->printErrors(cerr);
    delete document;

    return errors;
  }

  Model* m = document->getModel();
  m->unsetAnnotation();

  for(i=0; i < m->getNumReactions(); i++)
  {
    Reaction* re = m->getReaction(i);
    re->unsetAnnotation();

    for(j=0; j < re->getNumReactants(); j++)
    {
      SpeciesReference* rt = re->getReactant(j);
      rt->unsetAnnotation();
    }

    for(j=0; j < re->getNumProducts(); j++)
    {
      SpeciesReference* rt = re->getProduct(j);
      rt->unsetAnnotation();
    }

    for(j=0; j < re->getNumModifiers(); j++)
    {
      ModifierSpeciesReference* md = re->getModifier(j);
      md->unsetAnnotation();
    }

    if(re->isSetKineticLaw())
    {
      KineticLaw* kl = re->getKineticLaw();
      kl->unsetAnnotation();

      for(j=0; j < kl->getNumParameters(); j++)
      {
        Parameter* pa = kl->getParameter(j);
        pa->unsetAnnotation();
      }
    }

  }

  for(i=0; i < m->getNumSpecies(); i++)
  {
    Species* sp = m->getSpecies(i);
    sp->unsetAnnotation();
  }

  for(i=0; i < m->getNumCompartments(); i++)
  {
    Compartment* sp = m->getCompartment(i);
    sp->unsetAnnotation();
  }

  for(i=0; i < m->getNumFunctionDefinitions(); i++)
  {
    FunctionDefinition* sp = m->getFunctionDefinition(i);
    sp->unsetAnnotation();
  }

  for(i=0; i < m->getNumUnitDefinitions(); i++)
  {
    UnitDefinition* sp = m->getUnitDefinition(i);
    sp->unsetAnnotation();
  }

  for(i=0; i < m->getNumParameters(); i++)
  {
    Parameter* sp = m->getParameter(i);
    sp->unsetAnnotation();
  }

  for(i=0; i < m->getNumRules(); i++)
  {
    Rule* sp = m->getRule(i);
    sp->unsetAnnotation();
  }

  for(i=0; i < m->getNumInitialAssignments(); i++)
  {
    InitialAssignment* sp = m->getInitialAssignment(i);
    sp->unsetAnnotation();
  }

  for(i=0; i < m->getNumEvents(); i++)
  {
    Event* sp = m->getEvent(i);
    sp->unsetAnnotation();

    for(j=0; j < sp->getNumEventAssignments(); j++)
    {
      EventAssignment* ea = sp->getEventAssignment(j);
      ea->unsetAnnotation();
    }
  }

  for(i=0; i < m->getNumSpeciesTypes(); i++)
  {
    SpeciesType* sp = m->getSpeciesType(i);
    sp->unsetAnnotation();
  }

  for(i=0; i < m->getNumConstraints(); i++)
  {
    Constraint* sp = m->getConstraint(i);
    sp->unsetAnnotation();
  }

  writeSBML(document, argv[2]);

  delete document;
  return errors;
}



