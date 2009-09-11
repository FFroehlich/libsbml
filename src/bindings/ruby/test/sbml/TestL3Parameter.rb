#
# @file    TestL3Parameter.rb
# @brief   L3 Parameter unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestL3Parameter.c
# with the help of conversion sciprt (ctest_converter.pl).
#
#<!---------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2009 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#--------------------------------------------------------------------------->*/
require 'test/unit'
require 'libSBML'

class TestL3Parameter < Test::Unit::TestCase

  def isnan(x)
    return (x != x)
  end
  def setup
    @@p = LibSBML::Parameter.new(3,1)
    if (@@p == nil)
    end
  end

  def teardown
    @@p = nil
  end

  def test_L3_Parameter_constant
    assert( @@p.isSetConstant() == false )
    @@p.setConstant(true)
    assert( @@p.getConstant() == true )
    assert( @@p.isSetConstant() == true )
    @@p.setConstant(false)
    assert( @@p.getConstant() == false )
    assert( @@p.isSetConstant() == true )
  end

  def test_L3_Parameter_create
    assert( @@p.getTypeCode() == LibSBML::SBML_PARAMETER )
    assert( @@p.getMetaId() == "" )
    assert( @@p.getNotes() == nil )
    assert( @@p.getAnnotation() == nil )
    assert( @@p.getId() == "" )
    assert( @@p.getName() == "" )
    assert( @@p.getUnits() == "" )
    assert_equal true, isnan(@@p.getValue())
    assert( @@p.getConstant() == true )
    assert_equal false, @@p.isSetId()
    assert_equal false, @@p.isSetName()
    assert_equal false, @@p.isSetValue()
    assert_equal false, @@p.isSetUnits()
    assert_equal false, @@p.isSetConstant()
  end

  def test_L3_Parameter_createWithNS
    xmlns = LibSBML::XMLNamespaces.new()
    xmlns.add( "http://www.sbml.org", "testsbml")
    sbmlns = LibSBML::SBMLNamespaces.new(3,1)
    sbmlns.addNamespaces(xmlns)
    p = LibSBML::Parameter.new(sbmlns)
    assert( p.getTypeCode() == LibSBML::SBML_PARAMETER )
    assert( p.getMetaId() == "" )
    assert( p.getNotes() == nil )
    assert( p.getAnnotation() == nil )
    assert( p.getLevel() == 3 )
    assert( p.getVersion() == 1 )
    assert( p.getNamespaces() != nil )
    assert( p.getNamespaces().getLength() == 2 )
    assert( p.getId() == "" )
    assert( p.getName() == "" )
    assert( p.getUnits() == "" )
    assert_equal true, isnan(p.getValue())
    assert( p.getConstant() == true )
    assert_equal false, p.isSetId()
    assert_equal false, p.isSetName()
    assert_equal false, p.isSetValue()
    assert_equal false, p.isSetUnits()
    assert_equal false, p.isSetConstant()
    p = nil
  end

  def test_L3_Parameter_free_NULL
  end

  def test_L3_Parameter_hasRequiredAttributes
    p = LibSBML::Parameter.new(3,1)
    assert_equal false, p.hasRequiredAttributes()
    p.setId( "id")
    assert_equal false, p.hasRequiredAttributes()
    p.setConstant(false)
    assert_equal true, p.hasRequiredAttributes()
    p = nil
  end

  def test_L3_Parameter_id
    id =  "mitochondria";
    assert_equal false, @@p.isSetId()
    @@p.setId(id)
    assert (( id == @@p.getId() ))
    assert_equal true, @@p.isSetId()
    if (@@p.getId() == id)
    end
  end

  def test_L3_Parameter_name
    name =  "My_Favorite_Factory";
    assert_equal false, @@p.isSetName()
    @@p.setName(name)
    assert (( name == @@p.getName() ))
    assert_equal true, @@p.isSetName()
    if (@@p.getName() == name)
    end
    @@p.unsetName()
    assert_equal false, @@p.isSetName()
    if (@@p.getName() != nil)
    end
  end

  def test_L3_Parameter_units
    units =  "volume";
    assert_equal false, @@p.isSetUnits()
    @@p.setUnits(units)
    assert (( units == @@p.getUnits() ))
    assert_equal true, @@p.isSetUnits()
    if (@@p.getUnits() == units)
    end
    @@p.unsetUnits()
    assert_equal false, @@p.isSetUnits()
    if (@@p.getUnits() != nil)
    end
  end

  def test_L3_Parameter_value
    assert_equal false, @@p.isSetValue()
    assert_equal true, isnan(@@p.getValue())
    @@p.setValue(1.5)
    assert_equal true, @@p.isSetValue()
    assert( @@p.getValue() == 1.5 )
    @@p.unsetValue()
    assert_equal false, @@p.isSetValue()
    assert_equal true, isnan(@@p.getValue())
  end

end
