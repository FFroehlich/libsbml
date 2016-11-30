/**
 * @file TransformationComponents.h
 * @brief Definition of the TransformationComponents class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class TransformationComponents
 * @sbmlbrief{spatial} TODO:Definition of the TransformationComponents class.
 */


#ifndef TransformationComponents_H__
#define TransformationComponents_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/spatial/common/spatialfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/spatial/extension/SpatialExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN TransformationComponents : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  double* mComponents;
  int mComponentsLength;
  bool mIsSetComponentsLength;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new TransformationComponents using the given SBML Level, Version
   * and &ldquo;spatial&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * TransformationComponents.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * TransformationComponents.
   *
   * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
   * this TransformationComponents.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  TransformationComponents(
                           unsigned int level =
                             SpatialExtension::getDefaultLevel(),
                           unsigned int version =
                             SpatialExtension::getDefaultVersion(),
                           unsigned int pkgVersion =
                             SpatialExtension::getDefaultPackageVersion());


  /**
   * Creates a new TransformationComponents using the given
   * SpatialPkgNamespaces object.
   *
   * @param spatialns the SpatialPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  TransformationComponents(SpatialPkgNamespaces *spatialns);


  /**
   * Copy constructor for TransformationComponents.
   *
   * @param orig the TransformationComponents instance to copy.
   */
  TransformationComponents(const TransformationComponents& orig);


  /**
   * Assignment operator for TransformationComponents.
   *
   * @param rhs the TransformationComponents object whose values are to be used
   * as the basis of the assignment.
   */
  TransformationComponents& operator=(const TransformationComponents& rhs);


  /**
   * Creates and returns a deep copy of this TransformationComponents object.
   *
   * @return a (deep) copy of this TransformationComponents object.
   */
  virtual TransformationComponents* clone() const;


  /**
   * Destructor for TransformationComponents.
   */
  virtual ~TransformationComponents();


  /**
   * Returns the value of the "components" attribute of this
   * TransformationComponents.
   *
   * @param outArray double* array that will be used to return the value of the
   * "components" attribute of this TransformationComponents.
   *
   * @note the value of the "components" attribute of this
   * TransformationComponents is returned in the argument array.
   */
  void getComponents(double* outArray) const;


  /**
   * Returns the value of the "componentsLength" attribute of this
   * TransformationComponents.
   *
   * @return the value of the "componentsLength" attribute of this
   * TransformationComponents as a integer.
   */
  int getComponentsLength() const;


  /**
   * Predicate returning @c true if this TransformationComponents's
   * "components" attribute is set.
   *
   * @return @c true if this TransformationComponents's "components" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetComponents() const;


  /**
   * Predicate returning @c true if this TransformationComponents's
   * "componentsLength" attribute is set.
   *
   * @return @c true if this TransformationComponents's "componentsLength"
   * attribute has been set, otherwise @c false is returned.
   */
  bool isSetComponentsLength() const;


  /**
   * Sets the value of the "components" attribute of this
   * TransformationComponents.
   *
   * @param inArray double* array value of the "components" attribute to be
   * set.
   *
   * @param arrayLength int value for the length of the "components" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setComponents(double* inArray, int arrayLength);


  /**
   * Sets the value of the "componentsLength" attribute of this
   * TransformationComponents.
   *
   * @param componentsLength int value of the "componentsLength" attribute to
   * be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setComponentsLength(int componentsLength);


  /**
   * Unsets the value of the "components" attribute of this
   * TransformationComponents.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetComponents();


  /**
   * Unsets the value of the "componentsLength" attribute of this
   * TransformationComponents.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetComponentsLength();


  /**
   * Returns the XML element name of this TransformationComponents object.
   *
   * For TransformationComponents, the XML element name is always @c
   * "transformationComponents".
   *
   * @return the name of this element, i.e. @c "transformationComponents".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the XML name of this TransformationComponents object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBML type code for this TransformationComponents object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_SPATIAL_TRANSFORMATIONCOMPONENTS,
   * SBMLSpatialTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * TransformationComponents object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * TransformationComponents have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the TransformationComponents object are:
   * @li "components"
   * @li "componentsLength"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * used to write arrays
   */
  virtual void write(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           const char* value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this TransformationComponents's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this TransformationComponents's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, const char*
    value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this
   * TransformationComponents.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the array data as a text element
   */
  virtual void setElementText(const std::string& text);

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new TransformationComponents_t using the given SBML Level, Version
 * and &ldquo;spatial&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * TransformationComponents_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * TransformationComponents_t.
 *
 * @param pkgVersion an unsigned int, the SBML Spatial Version to assign to
 * this TransformationComponents_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
TransformationComponents_t *
TransformationComponents_create(
                                unsigned int level =
                                  SpatialExtension::getDefaultLevel(),
                                unsigned int version =
                                  SpatialExtension::getDefaultVersion(),
                                unsigned int pkgVersion =
                                  SpatialExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this TransformationComponents_t object.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @return a (deep) copy of this TransformationComponents_t object.
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
TransformationComponents_t*
TransformationComponents_clone(const TransformationComponents_t* tc);


/**
 * Frees this TransformationComponents_t object.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
void
TransformationComponents_free(TransformationComponents_t* tc);


/**
 * Returns the value of the "componentsLength" attribute of this
 * TransformationComponents_t.
 *
 * @param tc the TransformationComponents_t structure whose componentsLength is
 * sought.
 *
 * @return the value of the "componentsLength" attribute of this
 * TransformationComponents_t as a integer.
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
int
TransformationComponents_getComponentsLength(const TransformationComponents_t *
  tc);


/**
 * Predicate returning @c 1 if this TransformationComponents_t's "components"
 * attribute is set.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @return @c 1 if this TransformationComponents_t's "components" attribute has
 * been set, otherwise @c 0 is returned.
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
int
TransformationComponents_isSetComponents(const TransformationComponents_t *
  tc);


/**
 * Predicate returning @c 1 if this TransformationComponents_t's
 * "componentsLength" attribute is set.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @return @c 1 if this TransformationComponents_t's "componentsLength"
 * attribute has been set, otherwise @c 0 is returned.
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
int
TransformationComponents_isSetComponentsLength(const TransformationComponents_t
  * tc);


/**
 * Sets the value of the "components" attribute of this
 * TransformationComponents_t.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @param components pointer value of the "components" attribute to be set.
 *
 * @param arrayLength int value for the length of the "components" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
int
TransformationComponents_setComponents(TransformationComponents_t* tc,
                                       double* components,
                                       int arrayLength);


/**
 * Sets the value of the "componentsLength" attribute of this
 * TransformationComponents_t.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @param componentsLength int value of the "componentsLength" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
int
TransformationComponents_setComponentsLength(TransformationComponents_t * tc,
                                             int componentsLength);


/**
 * Unsets the value of the "components" attribute of this
 * TransformationComponents_t.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
int
TransformationComponents_unsetComponents(TransformationComponents_t * tc);


/**
 * Unsets the value of the "componentsLength" attribute of this
 * TransformationComponents_t.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
int
TransformationComponents_unsetComponentsLength(TransformationComponents_t *
  tc);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * TransformationComponents_t object have been set.
 *
 * @param tc the TransformationComponents_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * TransformationComponents_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the TransformationComponents_t object are:
 * @li "components"
 * @li "componentsLength"
 *
 * @memberof TransformationComponents_t
 */
LIBSBML_EXTERN
int
TransformationComponents_hasRequiredAttributes(const TransformationComponents_t
  * tc);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !TransformationComponents_H__ */


