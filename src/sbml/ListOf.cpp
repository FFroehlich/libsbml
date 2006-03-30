/**
 * \file    ListOf.cpp
 * \brief   Wraps List and inherits from SBase
 * \author  Ben Bornstein
 *
 * $Id$
 * $Source$
 */
/* Copyright 2002 California Institute of Technology and Japan Science and
 * Technology Corporation.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is
 * provided in the file named "LICENSE.txt" included with this software
 * distribution.  It is also available online at
 * http://sbml.org/software/libsbml/license.html
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */


#include <algorithm>
#include <functional>

#include "SBMLVisitor.h"
#include "ListOf.h"


using namespace std;


/**
 * Creates a new ListOf items.
 */
ListOf::ListOf ()
{
}


/**
 * Used by the Copy Constructor to clone each item in mItems.
 */
struct Clone : public unary_function<SBase*, SBase*>
{
  SBase* operator() (SBase* sb) { return sb->clone(); }
};


/**
 * Copies this ListOf items.
 */
ListOf::ListOf (const ListOf& rhs)
{
  mItems.reserve( rhs.size() );
  transform( rhs.mItems.begin(), rhs.mItems.end(), mItems.begin(), Clone() );
}


/**
 * Used by the Destructor to delete each item in mItems.
 */
struct Delete : public unary_function<SBase*, void>
{
  void operator() (SBase* sb) { delete sb; }
};


/**
 * Destroys the given ListOf and its constituent items.
 */
ListOf::~ListOf ()
{
  for_each( mItems.begin(), mItems.end(), Delete() );
}


/**
 * Accepts the given SBMLVisitor.
 */
bool
ListOf::accept (SBMLVisitor& v) const
{
  v.visit(*this, getItemTypeCode() );
  for (unsigned int n = 0 ; n < mItems.size() && mItems[n]->accept(v); ++n) ;
  v.leave(*this, getItemTypeCode() );

  return true;
}


/**
 * @return a (deep) copy of this ListOf items.
 */
SBase*
ListOf::clone () const
{
  return new ListOf(*this);
}


/**
 * Adds item to the end of this ListOf items.
 */
void
ListOf::append (const SBase* item)
{
  if (item) mItems.push_back( item->clone() );
}


/**
 * Adds item to the end of this ListOf items.  This ListOf items assumes
 * ownership of item and will delete it.
 */
void
ListOf::appendAndOwn (SBase* item)
{
  if (item) mItems.push_back( item );
}


/**
 * @return the nth item in this ListOf items.
 */
const SBase*
ListOf::get (unsigned int n) const
{
  return mItems[n];
}


/**
 * @return the nth item in this ListOf items.
 */
SBase*
ListOf::get (unsigned int n)
{
  return const_cast<SBase*>( static_cast<const ListOf&>(*this).get(n) );
}


/**
 * Used by ListOf::get() to lookup an SBase based by its id.
 */
struct IdEq : public unary_function<SBase*, bool>
{
  const string& id;

  IdEq (const string& id) : id(id) { }
  bool operator() (SBase* sb) { return sb->getId() == id; }
};


/**
 * @return item in this ListOf items with the given id or NULL if no such
 * item exists.
 */
const SBase*
ListOf::get (const string& sid) const
{
  vector<SBase*>::const_iterator result;

  result = find_if( mItems.begin(), mItems.end(), IdEq(sid) );
  return (result == mItems.end()) ? 0 : *result;
}


/**
 * @return item in this ListOf items with the given id or NULL if no such
 * item exists.
 */
SBase*
ListOf::get (const string& sid)
{
  return const_cast<SBase*>( static_cast<const ListOf&>(*this).get(sid) );
}


/**
 * Removes the nth item from this ListOf items and returns a pointer to
 * it.  The caller owns the returned item and is responsible for deleting
 * it.
 */
SBase*
ListOf::remove (unsigned int n)
{
  SBase* item = get(n);
  if (item) mItems.erase( mItems.begin() + n );
  return item;
}


/**
 * Removes item in this ListOf items with the given id or NULL if no such
 * item exists.  The caller owns the returned item and is repsonsible for
 * deleting it.
 */
SBase*
ListOf::remove (const std::string& sid)
{
  SBase* item = 0;
  vector<SBase*>::iterator result;

  result = find_if( mItems.begin(), mItems.end(), IdEq(sid) );

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return item;
}


/**
 * @return the number of items in this ListOf items.
 */
unsigned int
ListOf::size () const
{
  return mItems.size();
}


/**
 * @return the SBMLTypeCode_t of this SBML object or SBML_UNKNOWN
 * (default).
 */
SBMLTypeCode_t
ListOf::getTypeCode () const
{
  return SBML_LIST_OF;
}


/**
 * @return the SBMLTypeCode_t of SBML objects contained in this ListOf or
 * SBML_UNKNOWN (default).
 */
SBMLTypeCode_t
ListOf::getItemTypeCode () const
{
  return SBML_UNKNOWN;
}


/**
 * Subclasses should override this method to return XML element name of
 * this SBML object.
 */
const string&
ListOf::getElementName () const
{
  static const string name = "listOf";
  return name;
}


/**
 * Used by ListOf::writeElements().
 */
struct Write : public unary_function<SBase*, void>
{
  XMLOutputStream& stream;

  Write (XMLOutputStream& s) : stream(s) { }
  void operator() (SBase* sbase) { sbase->write(stream); }
};


/**
 * Subclasses should override this method to write out their contained
 * SBML objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
ListOf::writeElements (XMLOutputStream& stream)
{
  SBase::writeElements(stream);
  for_each( mItems.begin(), mItems.end(), Write(stream) );
}




/**
 * Creates a new ListOf and returns a pointer to it.
 */
LIBSBML_EXTERN
ListOf_t *
ListOf_create ()
{
  return new(nothrow) ListOf;
}


/**
 * Frees the given ListOf and its constituent items.
 *
 * This function assumes each item in the list is derived from SBase.
 */
LIBSBML_EXTERN
void
ListOf_free (ListOf_t *lo)
{
  delete lo;
}


/**
 * @return a (deep) copy of this ListOf items.
 */
LIBSBML_EXTERN
ListOf_t *
ListOf_clone (const ListOf_t *lo)
{
  return static_cast<ListOf_t*>( lo->clone() );
}


/**
 * Adds a copy of item to the end of this ListOf items.
 */
LIBSBML_EXTERN
void
ListOf_append (ListOf_t *lo, const SBase *item)
{
  lo->append(item);
}


/**
 * Returns the nth item in this ListOf items.
 */
LIBSBML_EXTERN
SBase *
ListOf_get (ListOf_t *lo, unsigned int n)
{
  return lo->get(n);
}


/**
 * @return item in this ListOf items with the given id or NULL if no such
 * item exists.
 */
LIBSBML_EXTERN
SBase *
ListOf_getById (ListOf_t *lo, const char *sid)
{
  return (sid != NULL) ? lo->get(sid) : NULL;
}


/**
 * Removes the nth item from this ListOf items and returns a pointer to
 * it.  The caller owns the returned item and is responsible for deleting
 * it.
 */
LIBSBML_EXTERN
SBase *
ListOf_remove (ListOf_t *lo, unsigned int n)
{
  return lo->remove(n);
}


/**
 * Removes item in this ListOf items with the given id or NULL if no such
 * item exists.  The caller owns the returned item and is repsonsible for
 * deleting it.
 */
LIBSBML_EXTERN
SBase *
ListOf_removeById (ListOf_t *lo, const char *sid)
{
  return (sid != NULL) ? lo->remove(sid) : NULL;
}


/**
 * Returns the number of items in this ListOf items.
 */
LIBSBML_EXTERN
unsigned int
ListOf_size (const ListOf_t *lo)
{
  return lo->size();
}


/**
 * @return the SBMLTypeCode_t of SBML objects contained in this ListOf or
 * SBML_UNKNOWN (default).
 */
LIBSBML_EXTERN
SBMLTypeCode_t
ListOf_getItemTypeCode (const ListOf_t *lo)
{
  return lo->getItemTypeCode();
}
