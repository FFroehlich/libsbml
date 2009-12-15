/*
 *
 * @file    TestWriteL3SBML.java
 * @brief   Write SBML unit tests
 *
 * @author  Akiya Jouraku (Java conversion)
 * @author  Sarah Keating 
 *
 * $Id$
 * $HeadURL$
 *
 * This test file was converted from src/sbml/test/TestWriteL3SBML.cpp
 * with the help of conversion sciprt (ctest_converter.pl).
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2005-2009 California Institute of Technology.
 * Copyright 2002-2005 California Institute of Technology and
 *                     Japan Science and Technology Corporation.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *--------------------------------------------------------------------------->*/


package org.sbml.libsbml.test.sbml;

import org.sbml.libsbml.*;

import java.io.File;
import java.lang.AssertionError;

public class TestWriteL3SBML {

  static void assertTrue(boolean condition) throws AssertionError
  {
    if (condition == true)
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertEquals(Object a, Object b) throws AssertionError
  {
    if ( (a == null) && (b == null) )
    {
      return;
    }
    else if ( (a == null) || (b == null) )
    {
      throw new AssertionError();
    }
    else if (a.equals(b))
    {
      return;
    }

    throw new AssertionError();
  }

  static void assertNotEquals(Object a, Object b) throws AssertionError
  {
    if ( (a == null) && (b == null) )
    {
      throw new AssertionError();
    }
    else if ( (a == null) || (b == null) )
    {
      return;
    }
    else if (a.equals(b))
    {
      throw new AssertionError();
    }
  }

  static void assertEquals(boolean a, boolean b) throws AssertionError
  {
    if ( a == b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertNotEquals(boolean a, boolean b) throws AssertionError
  {
    if ( a != b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertEquals(int a, int b) throws AssertionError
  {
    if ( a == b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertNotEquals(int a, int b) throws AssertionError
  {
    if ( a != b )
    {
      return;
    }
    throw new AssertionError();
  }
  private SBMLDocument D;
  private String S;

  public String LV_L3v1()
  {
    return "level=\"3\" version=\"1\">\n";
  }

  public String NS_L3v1()
  {
    return "xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" ";
  }

  public String SBML_END()
  {
    return "</sbml>\n";
  }

  public String SBML_START()
  {
    return "<sbml ";
  }

  public String XML_START()
  {
    return "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
  }

  public String wrapSBML_L3v1(String s)
  {
    String r = XML_START();
    r += SBML_START();
    r += NS_L3v1();
    r += LV_L3v1();
    r += s;
    r += SBML_END();
    return r;
  }

  public String wrapXML(String s)
  {
    String r = XML_START();
    r += s;
    return r;
  }


  public double util_NaN()
  {
    double z = 0.0;
    return 0.0/z;
  }

  public double util_PosInf()
  {
    double z = 0.0;
    return 1.0/z;
  }

  public double util_NegInf()
  {
    double z = 0.0;
    return -1.0/z;
  }

  public boolean equals(String s1, String s2)
  {
    return s1.equals(s2);
  }

  protected void setUp() throws Exception
  {
    D = new SBMLDocument();
    D.setLevelAndVersion(3,1);
    S = null;
  }

  protected void tearDown() throws Exception
  {
    S = null;
  }

  public void test_SBMLWriter_L3_create()
  {
    SBMLWriter w = new  SBMLWriter();
    assertTrue( w != null );
    w = null;
  }

  public void test_SBMLWriter_L3_setProgramName()
  {
    SBMLWriter w = new  SBMLWriter();
    assertTrue( w != null );
    long i = w.setProgramName( "sss");
    assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
    i = w.setProgramName("");
    assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
    w = null;
  }

  public void test_SBMLWriter_L3_setProgramVersion()
  {
    SBMLWriter w = new  SBMLWriter();
    assertTrue( w != null );
    long i = w.setProgramVersion( "sss");
    assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
    i = w.setProgramVersion("");
    assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
    w = null;
  }

  public void test_WriteL3SBML_Compartment()
  {
    String expected =  "<compartment id=\"A\" constant=\"true\"/>";;
    Compartment c = D.createModel().createCompartment();
    c.setId("A");
    c.setConstant(true);
    assertEquals( true, equals(expected,c.toSBML()) );
  }

  public void test_WriteL3SBML_Compartment_spatialDimensions()
  {
    String expected = "<compartment id=\"A\" spatialDimensions=\"2.1\" " + "constant=\"false\"/>";;
    String expected1 =  "<compartment id=\"A\" constant=\"false\"/>";;
    Compartment c = D.createModel().createCompartment();
    c.setId("A");
    c.setConstant(false);
    c.setSpatialDimensions(2.1);
    assertEquals( true, equals(expected,c.toSBML()) );
    c.unsetSpatialDimensions();
    assertEquals( true, equals(expected1,c.toSBML()) );
  }

  public void test_WriteL3SBML_Event()
  {
    String expected =  "<event id=\"e\"/>";;
    Event e = D.createModel().createEvent();
    e.setId("e");
    e.setUseValuesFromTriggerTime(true);
    assertEquals( true, equals(expected,e.toSBML()) );
  }

  public void test_WriteL3SBML_Event_useValues()
  {
    String expected = "<event id=\"e\" useValuesFromTriggerTime=\"false\">\n" + 
    "  <delay/>\n" + 
    "</event>";
    Event e = D.createModel().createEvent();
    e.setId("e");
    e.setUseValuesFromTriggerTime(false);
    e.createDelay();
    assertEquals( true, equals(expected,e.toSBML()) );
  }

  public void test_WriteL3SBML_INF()
  {
    String expected = "<parameter id=\"p\" value=\"INF\"" + " constant=\"true\"/>";;
    Parameter p = D.createModel().createParameter();
    p.setId("p");
    p.setValue(util_PosInf());
    assertEquals( true, equals(expected,p.toSBML()) );
  }

  public void test_WriteL3SBML_KineticLaw_ListOfParameters()
  {
    String expected = "<kineticLaw>\n" + 
    "  <listOfLocalParameters>\n" + 
    "    <localParameter id=\"n\" value=\"1.2\"/>\n" + 
    "  </listOfLocalParameters>\n" + 
    "</kineticLaw>";
    KineticLaw kl = D.createModel().createReaction().createKineticLaw();
    LocalParameter p = kl.createLocalParameter();
    p.setId("n");
    p.setValue(1.2);
    assertEquals( true, equals(expected,kl.toSBML()) );
  }

  public void test_WriteL3SBML_Model()
  {
    String expected = wrapSBML_L3v1("  <model/>\n"  
    );
    Model m = D.createModel("");
    S = libsbml.writeSBMLToString(D);
    assertEquals( true, equals(expected,S) );
  }

  public void test_WriteL3SBML_Model_conversionFactor()
  {
    String expected = wrapSBML_L3v1("  <model conversionFactor=\"p\"/>\n"  
    );
    Model m = D.createModel("");
    m.setConversionFactor("p");
    S = libsbml.writeSBMLToString(D);
    assertEquals( true, equals(expected,S) );
  }

  public void test_WriteL3SBML_Model_otherUnits()
  {
    String expected = wrapSBML_L3v1("  <model volumeUnits=\"litre\" areaUnits=\"area\" lengthUnits=\"metre\"/>\n"  
    );
    Model m = D.createModel("");
    m.setVolumeUnits("litre");
    m.setAreaUnits("area");
    m.setLengthUnits("metre");
    S = libsbml.writeSBMLToString(D);
    assertEquals( true, equals(expected,S) );
  }

  public void test_WriteL3SBML_Model_substanceUnits()
  {
    String expected = wrapSBML_L3v1("  <model substanceUnits=\"mole\"/>\n"  
    );
    Model m = D.createModel("");
    m.setSubstanceUnits("mole");
    S = libsbml.writeSBMLToString(D);
    assertEquals( true, equals(expected,S) );
  }

  public void test_WriteL3SBML_Model_timeUnits()
  {
    String expected = wrapSBML_L3v1("  <model timeUnits=\"second\"/>\n"  
    );
    Model m = D.createModel("");
    m.setTimeUnits("second");
    S = libsbml.writeSBMLToString(D);
    assertEquals( true, equals(expected,S) );
  }

  public void test_WriteL3SBML_NaN()
  {
    String expected = "<parameter id=\"p\" value=\"NaN\"" + " constant=\"true\"/>";;
    Parameter p = D.createModel().createParameter();
    p.setId("p");
    p.setValue(util_NaN());
    assertEquals( true, equals(expected,p.toSBML()) );
  }

  public void test_WriteL3SBML_NegINF()
  {
    String expected = "<parameter id=\"p\" value=\"-INF\"" + " constant=\"true\"/>";;
    Parameter p = D.createModel().createParameter();
    p.setId("p");
    p.setValue(util_NegInf());
    assertEquals( true, equals(expected,p.toSBML()) );
  }

  public void test_WriteL3SBML_Parameter()
  {
    String expected = "<parameter id=\"Km1\" value=\"2.3\"" + " units=\"second\" constant=\"true\"/>";;
    Parameter p = D.createModel().createParameter();
    p.setId("Km1");
    p.setValue(2.3);
    p.setUnits("second");
    p.setConstant(true);
    assertEquals( true, equals(expected,p.toSBML()) );
  }

  public void test_WriteL3SBML_Reaction()
  {
    String expected = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\"/>";;
    Reaction r = D.createModel().createReaction();
    r.setId("r");
    r.setReversible(false);
    r.setFast(true);
    assertEquals( true, equals(expected,r.toSBML()) );
  }

  public void test_WriteL3SBML_Reaction_compartment()
  {
    String expected = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\" compartment=\"c\"/>";;
    String expected1 = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\"/>";;
    Reaction r = D.createModel().createReaction();
    r.setId("r");
    r.setReversible(false);
    r.setFast(true);
    r.setCompartment("c");
    assertEquals( true, equals(expected,r.toSBML()) );
    r.unsetCompartment();
    assertEquals( true, equals(expected1,r.toSBML()) );
  }

  public void test_WriteL3SBML_Reaction_full()
  {
    String expected = "<reaction id=\"v1\" reversible=\"true\" fast=\"false\">\n" + 
    "  <listOfReactants>\n" + 
    "    <speciesReference species=\"x0\" constant=\"false\"/>\n" + 
    "  </listOfReactants>\n" + 
    "  <listOfProducts>\n" + 
    "    <speciesReference species=\"s1\" constant=\"false\"/>\n" + 
    "  </listOfProducts>\n" + 
    "  <listOfModifiers>\n" + 
    "    <modifierSpeciesReference species=\"m1\"/>\n" + 
    "  </listOfModifiers>\n" + 
    "  <kineticLaw>\n" + 
    "    <math xmlns=\"http://www.w3.org/1998/Math/MathML\">\n" + 
    "      <apply>\n" + 
    "        <divide/>\n" + 
    "        <apply>\n" + 
    "          <times/>\n" + 
    "          <ci> vm </ci>\n" + 
    "          <ci> s1 </ci>\n" + 
    "        </apply>\n" + 
    "        <apply>\n" + 
    "          <plus/>\n" + 
    "          <ci> km </ci>\n" + 
    "          <ci> s1 </ci>\n" + 
    "        </apply>\n" + 
    "      </apply>\n" + 
    "    </math>\n" + 
    "  </kineticLaw>\n" + 
    "</reaction>";
    D.createModel();
    Reaction r = D.getModel().createReaction();
    r.setId("v1");
    r.setReversible(true);
    r.createReactant().setSpecies("x0");
    r.createProduct().setSpecies("s1");
    r.createModifier().setSpecies("m1");
    r.createKineticLaw().setFormula("(vm * s1)/(km + s1)");
    assertEquals( true, equals(expected,r.toSBML()) );
  }

  public void test_WriteL3SBML_SBMLDocument_L3v1()
  {
    String expected = wrapXML("<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" " + "level=\"3\" version=\"1\"/>\n");
    S = libsbml.writeSBMLToString(D);
    assertEquals( true, equals(expected,S) );
  }

  public void test_WriteL3SBML_Species()
  {
    String expected = "<species id=\"Ca2\" compartment=\"cell\" initialAmount=\"0.7\"" + 
    " substanceUnits=\"mole\" hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"/>";
    Species s = D.createModel().createSpecies();
    s.setId("Ca2");
    s.setCompartment("cell");
    s.setInitialAmount(0.7);
    s.setUnits("mole");
    s.setBoundaryCondition(true);
    s.setHasOnlySubstanceUnits(false);
    s.setConstant(true);
    assertEquals( true, equals(expected,s.toSBML()) );
  }

  public void test_WriteL3SBML_SpeciesReference()
  {
    String expected = "<speciesReference species=\"s\"" + " stoichiometry=\"3\" constant=\"true\"/>";;
    SpeciesReference sr = D.createModel().createReaction().createReactant();
    sr.setSpecies("s");
    sr.setStoichiometry(3);
    sr.setConstant(true);
    assertEquals( true, equals(expected,sr.toSBML()) );
  }

  public void test_WriteL3SBML_Species_conversionFactor()
  {
    String expected = "<species id=\"Ca2\" compartment=\"cell\"" + 
    " hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"" + 
    " conversionFactor=\"p\"/>";
    String expected1 = "<species id=\"Ca2\" compartment=\"cell\"" + 
    " hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"/>";
    Species s = D.createModel().createSpecies();
    s.setId("Ca2");
    s.setCompartment("cell");
    s.setBoundaryCondition(true);
    s.setHasOnlySubstanceUnits(false);
    s.setConstant(true);
    s.setConversionFactor("p");
    assertEquals( true, equals(expected,s.toSBML()) );
    s.unsetConversionFactor();
    assertEquals( true, equals(expected1,s.toSBML()) );
  }

  public void test_WriteL3SBML_Unit()
  {
    String expected = "<unit kind=\"kilogram\" exponent=\"0.2\"" + " scale=\"-3\" multiplier=\"3.2\"/>";;
    Unit u = D.createModel().createUnitDefinition().createUnit();
    u.setKind(libsbml.UNIT_KIND_KILOGRAM);
    double exp = 0.2;
    u.setExponent(exp);
    u.setScale(-3);
    u.setMultiplier(3.2);
    assertEquals( true, equals(expected,u.toSBML()) );
  }

  public void test_WriteL3SBML_UnitDefinition()
  {
    String expected = "<unitDefinition id=\"myUnit\">\n" + 
    "  <listOfUnits>\n" + 
    "    <unit kind=\"mole\" exponent=\"1\" scale=\"0\" multiplier=\"1.8\"/>\n" + 
    "  </listOfUnits>\n" + 
    "</unitDefinition>";
    UnitDefinition ud = D.createModel().createUnitDefinition();
    ud.setId("myUnit");
    Unit u1 = ud.createUnit();
    u1.setKind(libsbml.UnitKind_forName("mole"));
    u1.setMultiplier(1.8);
    u1.setScale(0);
    u1.setExponent(1);
    assertEquals( true, equals(expected,ud.toSBML()) );
  }

  public void test_WriteL3SBML_Unit_noValues()
  {
    String expected = "<unit kind=\"(Invalid UnitKind)\" exponent=\"NaN\"" + " scale=\"2147483647\" multiplier=\"NaN\"/>";;
    Unit u = D.createModel().createUnitDefinition().createUnit();
    assertEquals( true, equals(expected,u.toSBML()) );
  }

  public void test_WriteL3SBML_bzip2()
  {
    int filenum = 12;
    String file[] = {
                        "../../../examples/sample-models/from-spec/level-3/algebraicrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/assignmentrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/boundarycondition.xml",
                        "../../../examples/sample-models/from-spec/level-3/delay.xml",
                        "../../../examples/sample-models/from-spec/level-3/dimerization.xml",
                        "../../../examples/sample-models/from-spec/level-3/enzymekinetics.xml",
                        "../../../examples/sample-models/from-spec/level-3/events.xml",
                        "../../../examples/sample-models/from-spec/level-3/functiondef.xml",
                        "../../../examples/sample-models/from-spec/level-3/multicomp.xml",
                        "../../../examples/sample-models/from-spec/level-3/overdetermined.xml",
                        "../../../examples/sample-models/from-spec/level-3/twodimensional.xml",
                        "../../../examples/sample-models/from-spec/level-3/units.xml"
    };
    String bz2file = "test.xml.bz2";
    for(int i = 0; i < filenum; i++)
    {
      SBMLDocument d = libsbml.readSBML(file[i]);
      assertTrue( d != null );
      if (! SBMLWriter.hasBzip2())
      {
        assertTrue( libsbml.writeSBML(d, bz2file) == 0 );
        d = null;
          continue;
      }
      boolean result = (libsbml.writeSBML(d, bz2file) != 0);
      assertEquals( true, result );
      SBMLDocument dg = libsbml.readSBML(bz2file);
      assertTrue( dg != null );
      assertTrue( !d.toSBML().equals(dg.toSBML()) == false );
      d = null;
      dg = null;
    }
  }


  public void test_WriteL3SBML_elements()
  {
    String expected = wrapSBML_L3v1("  <model>\n" + 
    "    <listOfFunctionDefinitions>\n" + 
    "      <functionDefinition/>\n" + 
    "    </listOfFunctionDefinitions>\n" + 
    "    <listOfUnitDefinitions>\n" + 
    "      <unitDefinition/>\n" + 
    "    </listOfUnitDefinitions>\n" + 
    "    <listOfCompartments>\n" + 
    "      <compartment constant=\"true\"/>\n" + 
    "    </listOfCompartments>\n" + 
    "    <listOfSpecies>\n" + 
    "      <species hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"false\" constant=\"false\"/>\n" + 
    "    </listOfSpecies>\n" + 
    "    <listOfParameters>\n" + 
    "      <parameter constant=\"true\"/>\n" + 
    "    </listOfParameters>\n" + 
    "    <listOfInitialAssignments>\n" + 
    "      <initialAssignment/>\n" + 
    "    </listOfInitialAssignments>\n" + 
    "    <listOfRules>\n" + 
    "      <algebraicRule/>\n" + 
    "    </listOfRules>\n" + 
    "    <listOfConstraints>\n" + 
    "      <constraint/>\n" + 
    "    </listOfConstraints>\n" + 
    "    <listOfReactions>\n" + 
    "      <reaction reversible=\"true\" fast=\"false\"/>\n" + 
    "    </listOfReactions>\n" + 
    "    <listOfEvents>\n" + 
    "      <event/>\n" + 
    "    </listOfEvents>\n" + 
    "  </model>\n");
    Model m = D.createModel();
    m.createUnitDefinition();
    m.createFunctionDefinition();
    m.createCompartment();
    m.createEvent();
    m.createParameter();
    m.createAlgebraicRule();
    m.createInitialAssignment();
    m.createConstraint();
    m.createReaction();
    m.createSpecies();
    S = libsbml.writeSBMLToString(D);
    assertEquals( true, equals(expected,S) );
  }

  public void test_WriteL3SBML_error()
  {
    SBMLDocument d = new SBMLDocument();
    SBMLWriter w = new SBMLWriter();
    assertEquals( false, w.writeSBML(d, "/tmp/impossible/path/should/fail") );
    assertTrue( d.getNumErrors() == 1 );
    assertTrue( d.getError(0).getErrorId() == libsbml.XMLFileUnwritable );
    d = null;
    w = null;
  }

  public void test_WriteL3SBML_gzip()
  {
    int filenum = 12;
    String file[] = {
                        "../../../examples/sample-models/from-spec/level-3/algebraicrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/assignmentrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/boundarycondition.xml",
                        "../../../examples/sample-models/from-spec/level-3/delay.xml",
                        "../../../examples/sample-models/from-spec/level-3/dimerization.xml",
                        "../../../examples/sample-models/from-spec/level-3/enzymekinetics.xml",
                        "../../../examples/sample-models/from-spec/level-3/events.xml",
                        "../../../examples/sample-models/from-spec/level-3/functiondef.xml",
                        "../../../examples/sample-models/from-spec/level-3/multicomp.xml",
                        "../../../examples/sample-models/from-spec/level-3/overdetermined.xml",
                        "../../../examples/sample-models/from-spec/level-3/twodimensional.xml",
                        "../../../examples/sample-models/from-spec/level-3/units.xml"
    };
    String gzfile = "test.xml.gz";
    for(int i = 0; i < filenum; i++)
    {
      SBMLDocument d = libsbml.readSBML(file[i]);
      assertTrue( d != null );
      if (! SBMLWriter.hasZlib())
      {
        assertTrue( libsbml.writeSBML(d, gzfile) == 0 );
        d = null;
          continue;
      }
      boolean result = (libsbml.writeSBML(d, gzfile) != 0);
      assertEquals( true, result );
      SBMLDocument dg = libsbml.readSBML(gzfile);
      assertTrue( dg != null );
      assertTrue( !d.toSBML().equals(dg.toSBML()) == false );
      d = null;
      dg = null;
    }
  }


  public void test_WriteL3SBML_locale()
  {
    String expected = "<parameter id=\"p\" value=\"3.31\"" + " constant=\"true\"/>";;
    Parameter p = D.createModel().createParameter();
    p.setId("p");
    p.setValue(3.31);
    assertEquals( true, equals(expected,p.toSBML()) );
  }

  public void test_WriteL3SBML_zip()
  {
    int filenum = 12;
    String file[] = {
                        "../../../examples/sample-models/from-spec/level-3/algebraicrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/assignmentrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/boundarycondition.xml",
                        "../../../examples/sample-models/from-spec/level-3/delay.xml",
                        "../../../examples/sample-models/from-spec/level-3/dimerization.xml",
                        "../../../examples/sample-models/from-spec/level-3/enzymekinetics.xml",
                        "../../../examples/sample-models/from-spec/level-3/events.xml",
                        "../../../examples/sample-models/from-spec/level-3/functiondef.xml",
                        "../../../examples/sample-models/from-spec/level-3/multicomp.xml",
                        "../../../examples/sample-models/from-spec/level-3/overdetermined.xml",
                        "../../../examples/sample-models/from-spec/level-3/twodimensional.xml",
                        "../../../examples/sample-models/from-spec/level-3/units.xml"
    };
    String zipfile = "test.xml.zip";
    for(int i = 0; i < filenum; i++)
    {
      SBMLDocument d = libsbml.readSBML(file[i]);
      assertTrue( d != null );
      if (! SBMLWriter.hasZlib())
      {
        assertTrue( libsbml.writeSBML(d, zipfile) == 0 );
        d = null;
          continue;
      }
      boolean result = (libsbml.writeSBML(d, zipfile) != 0);
      assertEquals( true, result );
      SBMLDocument dg = libsbml.readSBML(zipfile);
      assertTrue( dg != null );
      assertTrue( !d.toSBML().equals(dg.toSBML()) == false );
      d = null;
      dg = null;
    }
  }


  /**
   * Loads the SWIG-generated libSBML Java module when this class is
   * loaded, or reports a sensible diagnostic message about why it failed.
   */
  static
  {
    String varname;
    String shlibname;

    if (System.getProperty("mrj.version") != null)
    {
      varname = "DYLD_LIBRARY_PATH";    // We're on a Mac.
      shlibname = "libsbmlj.jnilib and/or libsbml.dylib";
    }
    else
    {
      varname = "LD_LIBRARY_PATH";      // We're not on a Mac.
      shlibname = "libsbmlj.so and/or libsbml.so";
    }

    try
    {
      System.loadLibrary("sbmlj");
      // For extra safety, check that the jar file is in the classpath.
      Class.forName("org.sbml.libsbml.libsbml");
    }
    catch (SecurityException e)
    {
      e.printStackTrace();
      System.err.println("Could not load the libSBML library files due to a"+
                         " security exception.\n");
      System.exit(1);
    }
    catch (UnsatisfiedLinkError e)
    {
      e.printStackTrace();
      System.err.println("Error: could not link with the libSBML library files."+
                         " It is likely\nyour " + varname +
                         " environment variable does not include the directories\n"+
                         "containing the " + shlibname + " library files.\n");
      System.exit(1);
    }
    catch (ClassNotFoundException e)
    {
      e.printStackTrace();
      System.err.println("Error: unable to load the file libsbmlj.jar."+
                         " It is likely\nyour -classpath option and CLASSPATH" +
                         " environment variable\n"+
                         "do not include the path to libsbmlj.jar.\n");
      System.exit(1);
    }
  }
}
