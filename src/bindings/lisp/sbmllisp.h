/**
 * \file    sbmllisp.h
 * \brief   preprocess with gcc -I../.. -E sbmllisp.h > sbmllisp-pre.h
 * \author  Martin Ginkel <mginkel@mpi-mageburg.mpg.de>
 *
 * $Id$
 * $Source$
 *
 * Copyright 2004 Max-Planck-Institute Magdeburg
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * any later version.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


/**
 * This is a dummy definition, which doesn't matter, since only *FILE is
 * used
 */
typedef struct
{
  int dummy;
} FILE;


#define	_BITS_TYPES_H	1  /*  avoid inclusion of bits/types.h  */
#define _STDIO_H	1      /*  avoid inclusion of stdio.h       */


#include <sbml/SBMLConvert.h>
#include <sbml/SBMLReader.h>
#include <sbml/SBMLWriter.h>
#include <math/FormulaParser.h>
#include <math/FormulaFormatter.h>
