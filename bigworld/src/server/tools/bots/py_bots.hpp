/******************************************************************************
BigWorld Technology
Copyright BigWorld Pty, Ltd.
All Rights Reserved. Commercial in confidence.

WARNING: This computer program is protected by copyright law and international
treaties. Unauthorized use, reproduction or distribution of this program, or
any portion of this program, may result in the imposition of civil and
criminal penalties as provided by law.
******************************************************************************/

#ifndef PY_BOTS_HPP
#define PY_BOTS_HPP

#include "pyscript/pyobject_plus.hpp"

/**
 *	This class is used to expose the collection of bots to scripting.
 */
class PyBots : public PyObjectPlus
{
	Py_Header( PyBots, PyObjectPlus )

	public:
		PyBots( PyTypePlus * pType = &PyBots::s_type_ );

		PyObject * 			pyGetAttribute( const char * attr );

		PyObject * 			subscript( PyObject * entityID );
		int					length();

		PY_METHOD_DECLARE( py_has_key )
		PY_METHOD_DECLARE( py_keys )
		PY_METHOD_DECLARE( py_values )
		PY_METHOD_DECLARE( py_items )

		static PyObject * 	s_subscript( PyObject * self, PyObject * entityID );
		static Py_ssize_t	s_length( PyObject * self );
};

#endif // PY_BOTS_HPP
