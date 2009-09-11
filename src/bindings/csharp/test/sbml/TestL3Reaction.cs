/// 
///  @file    TestL3Reaction.cs
///  @brief   L3 Reaction unit tests
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
///  $Id$
///  $HeadURL$
/// 
///  This test file was converted from src/sbml/test/TestL3Reaction.c
///  with the help of conversion sciprt (ctest_converter.pl).
/// 
/// <!---------------------------------------------------------------------------
///  This file is part of libSBML.  Please visit http://sbml.org for more
///  information about SBML, and the latest version of libSBML.
/// 
///  Copyright 2005-2009 California Institute of Technology.
///  Copyright 2002-2005 California Institute of Technology and
///                      Japan Science and Technology Corporation.
///  
///  This library is free software; you can redistribute it and/or modify it
///  under the terms of the GNU Lesser General Public License as published by
///  the Free Software Foundation.  A copy of the license agreement is provided
///  in the file named "LICENSE.txt" included with this software distribution
///  and also available online as http://sbml.org/software/libsbml/license.html
/// --------------------------------------------------------------------------->*/


namespace LibSBMLCSTest {

  using libsbml;

  using  System.IO;

  public class TestL3Reaction {
    public class AssertionError : System.Exception 
    {
      public AssertionError() : base()
      {
        
      }
    }


    static void assertTrue(bool condition)
    {
      if (condition == true)
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertEquals(object a, object b)
    {
      if ( (a == null) && (b == null) )
      {
        return;
      }
      else if ( (a == null) || (b == null) )
      {
        throw new AssertionError();
      }
      else if (a.Equals(b))
      {
        return;
      }
  
      throw new AssertionError();
    }

    static void assertNotEquals(object a, object b)
    {
      if ( (a == null) && (b == null) )
      {
        throw new AssertionError();
      }
      else if ( (a == null) || (b == null) )
      {
        return;
      }
      else if (a.Equals(b))
      {
        throw new AssertionError();
      }
    }

    static void assertEquals(bool a, bool b)
    {
      if ( a == b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertNotEquals(bool a, bool b)
    {
      if ( a != b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertEquals(int a, int b)
    {
      if ( a == b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertNotEquals(int a, int b)
    {
      if ( a != b )
      {
        return;
      }
      throw new AssertionError();
    }

    private Reaction R;

    public void setUp()
    {
      R = new  Reaction(3,1);
      if (R == null);
      {
      }
    }

    public void tearDown()
    {
      R = null;
    }

    public void test_L3_Reaction_compartment()
    {
      string compartment =  "cell";;
      assertEquals( false, R.isSetCompartment() );
      R.setCompartment(compartment);
      assertTrue(( compartment == R.getCompartment() ));
      assertEquals( true, R.isSetCompartment() );
      if (R.getCompartment() == compartment);
      {
      }
      R.unsetCompartment();
      assertEquals( false, R.isSetCompartment() );
      if (R.getCompartment() != null);
      {
      }
    }

    public void test_L3_Reaction_create()
    {
      assertTrue( R.getTypeCode() == libsbml.SBML_REACTION );
      assertTrue( R.getMetaId() == "" );
      assertTrue( R.getNotes() == null );
      assertTrue( R.getAnnotation() == null );
      assertTrue( R.getId() == "" );
      assertTrue( R.getName() == "" );
      assertTrue( R.getCompartment() == "" );
      assertTrue( R.getFast() == false );
      assertTrue( R.getReversible() == true );
      assertEquals( false, R.isSetId() );
      assertEquals( false, R.isSetName() );
      assertEquals( false, R.isSetCompartment() );
      assertEquals( false, R.isSetFast() );
      assertEquals( false, R.isSetReversible() );
    }

    public void test_L3_Reaction_createWithNS()
    {
      XMLNamespaces xmlns = new  XMLNamespaces();
      xmlns.add( "http://www.sbml.org", "testsbml");
      SBMLNamespaces sbmlns = new  SBMLNamespaces(3,1);
      sbmlns.addNamespaces(xmlns);
      Reaction r = new  Reaction(sbmlns);
      assertTrue( r.getTypeCode() == libsbml.SBML_REACTION );
      assertTrue( r.getMetaId() == "" );
      assertTrue( r.getNotes() == null );
      assertTrue( r.getAnnotation() == null );
      assertTrue( r.getLevel() == 3 );
      assertTrue( r.getVersion() == 1 );
      assertTrue( r.getNamespaces() != null );
      assertTrue( r.getNamespaces().getLength() == 2 );
      assertTrue( r.getId() == "" );
      assertTrue( r.getName() == "" );
      assertTrue( r.getCompartment() == "" );
      assertTrue( r.getFast() == false );
      assertTrue( r.getReversible() == true );
      assertEquals( false, r.isSetId() );
      assertEquals( false, r.isSetName() );
      assertEquals( false, r.isSetCompartment() );
      assertEquals( false, r.isSetFast() );
      assertEquals( false, r.isSetReversible() );
      r = null;
    }

    public void test_L3_Reaction_fast()
    {
      assertTrue( R.isSetFast() == false );
      R.setFast(true);
      assertTrue( R.getFast() == true );
      assertTrue( R.isSetFast() == true );
      R.setFast(false);
      assertTrue( R.getFast() == false );
      assertTrue( R.isSetFast() == true );
    }

    public void test_L3_Reaction_free_NULL()
    {
    }

    public void test_L3_Reaction_hasRequiredAttributes()
    {
      Reaction r = new  Reaction(3,1);
      assertEquals( false, r.hasRequiredAttributes() );
      r.setId( "id");
      assertEquals( false, r.hasRequiredAttributes() );
      r.setFast(false);
      assertEquals( false, r.hasRequiredAttributes() );
      r.setReversible(false);
      assertEquals( true, r.hasRequiredAttributes() );
      r = null;
    }

    public void test_L3_Reaction_id()
    {
      string id =  "mitochondria";;
      assertEquals( false, R.isSetId() );
      R.setId(id);
      assertTrue(( id == R.getId() ));
      assertEquals( true, R.isSetId() );
      if (R.getId() == id);
      {
      }
    }

    public void test_L3_Reaction_name()
    {
      string name =  "My_Favorite_Factory";;
      assertEquals( false, R.isSetName() );
      R.setName(name);
      assertTrue(( name == R.getName() ));
      assertEquals( true, R.isSetName() );
      if (R.getName() == name);
      {
      }
      R.unsetName();
      assertEquals( false, R.isSetName() );
      if (R.getName() != null);
      {
      }
    }

    public void test_L3_Reaction_reversible()
    {
      assertTrue( R.isSetReversible() == false );
      R.setReversible(true);
      assertTrue( R.getReversible() == true );
      assertTrue( R.isSetReversible() == true );
      R.setReversible(false);
      assertTrue( R.getReversible() == false );
      assertTrue( R.isSetReversible() == true );
    }

  }
}
