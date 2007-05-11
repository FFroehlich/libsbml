/**
 * @file    Species.h
 * @brief   SBML Species
 * @author  Ben Bornstein
 *
 * $Id$
 * $Source$
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2005-2007 California Institute of Technology.
 * Copyright 2002-2005 California Institute of Technology and
 *                     Japan Science and Technology Corporation.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *----------------------------------------------------------------------- -->*/

#ifndef Species_h
#define Species_h


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>


#ifdef __cplusplus


#include <string>

#include <sbml/SBase.h>
#include <sbml/ListOf.h>


class SBMLVisitor;


class LIBSBML_EXTERN Species : public SBase
{
public:

  /**
   * Creates a new Species, optionally with its id and name attributes set.
   */
  Species (const std::string& id = "", const std::string& name = "");

  /**
   * Destroys this Species.
   */
  virtual ~Species ();


  /**
  * Copy constructor. Creates a copy of this Species.
  */
  Species(const Species& orig);


  /**
   * Assignment operator.
   */
  Species& operator=(const Species& orig);

  /**
   * Accepts the given SBMLVisitor.
   *
   * @return the result of calling <code>v.visit()</code>, which indicates
   * whether or not the Visitor would like to visit the Model's next
   * Species (if available).
   */
  virtual bool accept (SBMLVisitor& v) const;

  /**
   * @return a (deep) copy of this Species.
   */
  virtual SBase* clone () const;

  /**
   * Initializes the fields of this Species to their defaults:
   *
   *   - boundaryCondition     = false
   *   - constant              = false  (L2 only)
   *   - hasOnlySubstanceUnits = false  (L2 only)
   */
  void initDefaults ();


  /**
   * @return the speciesType of this Species.
   */
  const std::string& getSpeciesType () const;

  /**
   * @return the compartment of this Species.
   */
  const std::string& getCompartment () const;

  /**
   * @return the initialAmount of this Species.
   */
  double getInitialAmount () const;

  /**
   * @return the initialConcentration of this Species.
   */
  double getInitialConcentration () const;

  /**
   * @return the substanceUnits of this Species.
   */
  const std::string& getSubstanceUnits () const;

  /**
   * @return the spatialSizeUnits of this Species.
   */
  const std::string& getSpatialSizeUnits () const;

  /**
   * @return the units of this Species (L1 only).
   */
  const std::string& getUnits () const;

  /**
   * @return true if this Species hasOnlySubstanceUnits, false otherwise.
   */
  bool getHasOnlySubstanceUnits () const;

  /**
   * @return true if this Species has boundaryCondition
   * true, false otherwise.
   */
  bool getBoundaryCondition () const;

  /**
   * @return the charge of this Species.
   */
  int getCharge () const;

  /**
   * @return true if this Species is constant, false otherwise.
   */
  bool getConstant () const;


  /**
   * @return true if the speciesType of this Species has been set, false
   * otherwise.
   */
  bool isSetSpeciesType () const;

  /**
   * @return true if the compartment of this Species has been set, false
   * otherwise.
   */
  bool isSetCompartment () const;

  /**
   * @return true if the initialAmount of this Species has been set, false
   * otherwise.
   *
   * In SBML L1, a Species initialAmount is required and therefore
   * <b>should always be set</b>.  In L2, initialAmount is optional and as
   * such may or may not be set.
   */
  bool isSetInitialAmount () const;

  /**
   * @return true if the initialConcentration of this Species has been set,
   * false otherwise.
   */
  bool isSetInitialConcentration () const;

  /**
   * @return true if the substanceUnits of this Species has been set, false
   * otherwise.
   */
  bool isSetSubstanceUnits () const;

  /**
   * @return true if the spatialSizeUnits of this Species has been set,
   * false otherwise.
   */
  bool isSetSpatialSizeUnits () const;

  /**
   * @return true if the units of this Species has been set, false
   * otherwise (L1 only).
   */
  bool isSetUnits () const;

  /**
   * @return true if the charge of this Species has been set, false
   * otherwise.
   */
  bool isSetCharge () const;


  /**
   * Sets the speciesType field of this Species to a copy of sid.
   */
  void setSpeciesType (const std::string& sid);

  /**
   * Sets the compartment of this Species to a copy of sid.
   */
  void setCompartment (const std::string& sid);

  /**
   * Sets the initialAmount of this Species to value and marks the field as
   * set.  This method also unsets the initialConcentration field.
   */
  void setInitialAmount (double value);

  /**
   * Sets the initialConcentration of this Species to value and marks the
   * field as set.  This method also unsets the initialAmount field.
   */
  void setInitialConcentration (double value);

  /**
   * Sets the substanceUnits of this Species to a copy of sid.
   */
  void setSubstanceUnits (const std::string& sid);

  /**
   * Sets the spatialSizeUnits of this Species to a copy of sid.
   */
  void setSpatialSizeUnits (const std::string& sid);

  /**
   * Sets the units of this Species to a copy of sname (L1 only).
   */
  void setUnits (const std::string& sname);

  /**
   * Sets the hasOnlySubstanceUnits field of this Species to value.
   */
  void setHasOnlySubstanceUnits (bool value);

  /**
   * Sets the boundaryCondition of this Species to value.
   */
  void setBoundaryCondition (bool value);

  /**
   * Sets the charge of this Species to value and marks the field as set.
   */
  void setCharge (int value);

  /**
   * Sets the constant field of this Species to value.
   */
  void setConstant (bool value);


  /**
   * Unsets the speciesType of this Species.
   */
  void unsetSpeciesType ();

  /**
   * Unsets the initialAmount of this Species.
   */
  void unsetInitialAmount ();

  /**
   * Unsets the initialConcentration of this Species.
   */
  void unsetInitialConcentration ();

  /**
   * Unsets the substanceUnits of this Species.
   */
  void unsetSubstanceUnits ();

  /**
   * Unsets the spatialSizeUnits of this Species.
   */
  void unsetSpatialSizeUnits ();

  /**
   * Unsets the units of this Species (L1 only).
   */
  void unsetUnits ();

  /**
   * Unsets the charge of this Species.
   */
  void unsetCharge ();


  /**
   * @return the SBMLTypeCode_t of this SBML object or SBML_UNKNOWN
   * (default).
   *
   * @see getElementName()
   */
  virtual SBMLTypeCode_t getTypeCode () const;

  /**
   * @return the name of this element ie "specie" (L1) or "species" (L2).
   */
  virtual const std::string& getElementName () const;


protected:
  /** @cond doxygen-libsbml-internal */

  /**
   * Subclasses should override this method to read (and store) XHTML,
   * MathML, etc. directly from the XMLInputStream.
   *
   * @return true if the subclass read from the stream, false otherwise.
   */
  virtual bool readOtherXML (XMLInputStream& stream);

  /**
   * Subclasses should override this method to read values from the given
   * XMLAttributes set into their specific fields.  Be sure to call your
   * parents implementation of this method as well.
   */
  virtual void readAttributes (const XMLAttributes& attributes);

  /**
   * Subclasses should override this method to write their XML attributes
   * to the XMLOutputStream.  Be sure to call your parents implementation
   * of this method as well.
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;


  std::string  mSpeciesType;
  std::string  mCompartment;

  double  mInitialAmount;
  double  mInitialConcentration;

  std::string  mSubstanceUnits;
  std::string  mSpatialSizeUnits;

  bool  mHasOnlySubstanceUnits;
  bool  mBoundaryCondition;
  int   mCharge;
  bool  mConstant;

  bool  mIsSetInitialAmount;
  bool  mIsSetInitialConcentration;
  bool  mIsSetCharge;

  /** @endcond doxygen-libsbml-internal */
};



class LIBSBML_EXTERN ListOfSpecies : public ListOf
{
public:

  /**
   * @return a (deep) copy of this ListOfSpecies.
   */
  virtual SBase* clone () const;

  /**
   * Returns the libSBML type code for this %SBML object.
   * 
   * @return the SBMLTypeCode_t of this object or SBML_UNKNOWN (default).
   *
   * @see getElementName()
   */
  virtual SBMLTypeCode_t getTypeCode () const { return SBML_LISTOF_SPECIES; };


  /**
   * @return the SBMLTypeCode_t of SBML objects contained in this ListOf or
   * SBML_UNKNOWN (default).
   */
  virtual SBMLTypeCode_t getItemTypeCode () const;

  /**
 * @return the name of this element ie "listOfSpecies".
   */
  virtual const std::string& getElementName () const;


  /** @cond doxygen-libsbml-internal */

  /**
   * @return the ordinal position of the element with respect to its
   * siblings or -1 (default) to indicate the position is not significant.
   */
  virtual int getElementPosition () const;

  /** @endcond doxygen-libsbml-internal */


protected:
  /** @cond doxygen-libsbml-internal */

  /**
   * @return the SBML object corresponding to next XMLToken in the
   * XMLInputStream or NULL if the token was not recognized.
   */
  virtual SBase* createObject (XMLInputStream& stream);

  /** @endcond doxygen-libsbml-internal */
};


#endif  /* __cplusplus */


#ifndef SWIG


BEGIN_C_DECLS

/*-----------------------------------------------------------------------------
 * See the .cpp file for the documentation of the following functions.
 *---------------------------------------------------------------------------*/


LIBSBML_EXTERN
Species_t *
Species_create (void);


LIBSBML_EXTERN
Species_t *
Species_createWith (const char *sid, const char *name);


LIBSBML_EXTERN
void
Species_free (Species_t *s);


LIBSBML_EXTERN
Species_t *
Species_clone (const Species_t *s);


LIBSBML_EXTERN
void
Species_initDefaults (Species_t *s);


LIBSBML_EXTERN
const char *
Species_getId (const Species_t *s);


LIBSBML_EXTERN
const char *
Species_getName (const Species_t *s);


LIBSBML_EXTERN
const char *
Species_getSpeciesType (const Species_t *s);


LIBSBML_EXTERN
const char *
Species_getCompartment (const Species_t *s);


LIBSBML_EXTERN
double
Species_getInitialAmount (const Species_t *s);


LIBSBML_EXTERN
double
Species_getInitialConcentration (const Species_t *s);


LIBSBML_EXTERN
const char *
Species_getSubstanceUnits (const Species_t *s);


LIBSBML_EXTERN
const char *
Species_getSpatialSizeUnits (const Species_t *s);


LIBSBML_EXTERN
const char *
Species_getUnits (const Species_t *s);


LIBSBML_EXTERN
int
Species_getHasOnlySubstanceUnits (const Species_t *s);


LIBSBML_EXTERN
int
Species_getBoundaryCondition (const Species_t *s);


LIBSBML_EXTERN
int
Species_getCharge (const Species_t *s);


LIBSBML_EXTERN
int
Species_getConstant (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetId (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetName (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetSpeciesType (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetCompartment (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetInitialAmount (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetInitialConcentration (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetSubstanceUnits (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetSpatialSizeUnits (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetUnits (const Species_t *s);


LIBSBML_EXTERN
int
Species_isSetCharge (const Species_t *s);


LIBSBML_EXTERN
void
Species_setId (Species_t *s, const char *sid);


LIBSBML_EXTERN
void
Species_setName (Species_t *s, const char *string);


LIBSBML_EXTERN
void
Species_setSpeciesType (Species_t *s, const char *sid);


LIBSBML_EXTERN
void
Species_setCompartment (Species_t *s, const char *sid);


LIBSBML_EXTERN
void
Species_setInitialAmount (Species_t *s, double value);


LIBSBML_EXTERN
void
Species_setInitialConcentration (Species_t *s, double value);


LIBSBML_EXTERN
void
Species_setSubstanceUnits (Species_t *s, const char *sid);


LIBSBML_EXTERN
void
Species_setSpatialSizeUnits (Species_t *s, const char *sid);


LIBSBML_EXTERN
void
Species_setUnits (Species_t *s, const char *sname);


LIBSBML_EXTERN
void
Species_setHasOnlySubstanceUnits (Species_t *s, int value);


LIBSBML_EXTERN
void
Species_setBoundaryCondition (Species_t *s, int value);


LIBSBML_EXTERN
void
Species_setCharge (Species_t *s, int value);


LIBSBML_EXTERN
void
Species_setConstant (Species_t *s, int value);


LIBSBML_EXTERN
void
Species_unsetName (Species_t *s);


LIBSBML_EXTERN
void
Species_unsetSpeciesType (Species_t *s);


LIBSBML_EXTERN
void
Species_unsetInitialAmount (Species_t *s);


LIBSBML_EXTERN
void
Species_unsetInitialConcentration (Species_t *s);


LIBSBML_EXTERN
void
Species_unsetSubstanceUnits (Species_t *s);


LIBSBML_EXTERN
void
Species_unsetSpatialSizeUnits (Species_t *s);


LIBSBML_EXTERN
void
Species_unsetUnits (Species_t *s);


LIBSBML_EXTERN
void
Species_unsetCharge (Species_t *s);


END_C_DECLS


#endif  /* !SWIG */
#endif  /* Species_h */
