#
# @file    TestL3Compartment.rb
# @brief   L3 Compartment unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestL3Compartment.c
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

class TestL3Compartment < Test::Unit::TestCase

  def isnan(x)
    return (x != x)
  end
  def setup
    @@c = LibSBML::Compartment.new(3,1)
    if (@@c == nil)
    end
  end

  def teardown
    @@c = nil
  end

  def test_L3_Compartment_constant
    assert( @@c.isSetConstant() == false )
    @@c.setConstant(true)
    assert( @@c.getConstant() == true )
    assert( @@c.isSetConstant() == true )
    @@c.setConstant(false)
    assert( @@c.getConstant() == false )
    assert( @@c.isSetConstant() == true )
  end

  def test_L3_Compartment_create
    assert( @@c.getTypeCode() == LibSBML::SBML_COMPARTMENT )
    assert( @@c.getMetaId() == "" )
    assert( @@c.getNotes() == nil )
    assert( @@c.getAnnotation() == nil )
    assert( @@c.getId() == "" )
    assert( @@c.getName() == "" )
    assert( @@c.getUnits() == "" )
    assert( @@c.getOutside() == "" )
    assert_equal true, isnan(@@c.getSpatialDimensionsAsDouble())
    assert_equal true, isnan(@@c.getVolume())
    assert( @@c.getConstant() == true )
    assert_equal false, @@c.isSetId()
    assert_equal false, @@c.isSetSpatialDimensions()
    assert_equal false, @@c.isSetName()
    assert_equal false, @@c.isSetSize()
    assert_equal false, @@c.isSetVolume()
    assert_equal false, @@c.isSetUnits()
    assert_equal false, @@c.isSetOutside()
    assert_equal false, @@c.isSetConstant()
  end

  def test_L3_Compartment_createWithNS
    xmlns = LibSBML::XMLNamespaces.new()
    xmlns.add( "http://www.sbml.org", "testsbml")
    sbmlns = LibSBML::SBMLNamespaces.new(3,1)
    sbmlns.addNamespaces(xmlns)
    c = LibSBML::Compartment.new(sbmlns)
    assert( c.getTypeCode() == LibSBML::SBML_COMPARTMENT )
    assert( c.getMetaId() == "" )
    assert( c.getNotes() == nil )
    assert( c.getAnnotation() == nil )
    assert( c.getLevel() == 3 )
    assert( c.getVersion() == 1 )
    assert( c.getNamespaces() != nil )
    assert( c.getNamespaces().getLength() == 2 )
    assert( c.getId() == "" )
    assert( c.getName() == "" )
    assert( c.getUnits() == "" )
    assert( c.getOutside() == "" )
    assert_equal true, isnan(c.getSpatialDimensionsAsDouble())
    assert_equal true, isnan(c.getVolume())
    assert( c.getConstant() == true )
    assert_equal false, c.isSetId()
    assert_equal false, c.isSetSpatialDimensions()
    assert_equal false, c.isSetName()
    assert_equal false, c.isSetSize()
    assert_equal false, c.isSetVolume()
    assert_equal false, c.isSetUnits()
    assert_equal false, c.isSetOutside()
    assert_equal false, c.isSetConstant()
    c = nil
  end

  def test_L3_Compartment_free_NULL
  end

  def test_L3_Compartment_hasRequiredAttributes
    c = LibSBML::Compartment.new(3,1)
    assert_equal false, c.hasRequiredAttributes()
    c.setId( "id")
    assert_equal false, c.hasRequiredAttributes()
    c.setConstant(false)
    assert_equal true, c.hasRequiredAttributes()
    c = nil
  end

  def test_L3_Compartment_id
    id =  "mitochondria";
    assert_equal false, @@c.isSetId()
    @@c.setId(id)
    assert (( id == @@c.getId() ))
    assert_equal true, @@c.isSetId()
    if (@@c.getId() == id)
    end
  end

  def test_L3_Compartment_name
    name =  "My_Favorite_Factory";
    assert_equal false, @@c.isSetName()
    @@c.setName(name)
    assert (( name == @@c.getName() ))
    assert_equal true, @@c.isSetName()
    if (@@c.getName() == name)
    end
    @@c.unsetName()
    assert_equal false, @@c.isSetName()
    if (@@c.getName() != nil)
    end
  end

  def test_L3_Compartment_size
    size = 0.2
    assert_equal false, @@c.isSetSize()
    assert_equal true, isnan(@@c.getSize())
    @@c.setSize(size)
    assert( @@c.getSize() == size )
    assert_equal true, @@c.isSetSize()
    @@c.unsetSize()
    assert_equal false, @@c.isSetSize()
    assert_equal true, isnan(@@c.getSize())
  end

  def test_L3_Compartment_spatialDimensions
    assert_equal false, @@c.isSetSpatialDimensions()
    assert_equal true, isnan(@@c.getSpatialDimensionsAsDouble())
    @@c.setSpatialDimensions(1.5)
    assert_equal true, @@c.isSetSpatialDimensions()
    assert( @@c.getSpatialDimensionsAsDouble() == 1.5 )
    @@c.unsetSpatialDimensions()
    assert_equal false, @@c.isSetSpatialDimensions()
    assert_equal true, isnan(@@c.getSpatialDimensionsAsDouble())
  end

  def test_L3_Compartment_units
    units =  "volume";
    assert_equal false, @@c.isSetUnits()
    @@c.setUnits(units)
    assert (( units == @@c.getUnits() ))
    assert_equal true, @@c.isSetUnits()
    if (@@c.getUnits() == units)
    end
    @@c.unsetUnits()
    assert_equal false, @@c.isSetUnits()
    if (@@c.getUnits() != nil)
    end
  end

end
