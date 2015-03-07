#include "Persona.h"

ostream & operator << (ostream & os, Persona persona)
{
	os << "Nombre: " << persona.nombre << std::endl;
	os << "Apellidos: " << persona.apellidos << std::endl;
	os << "Edad: " << persona.edad << std::endl;
	os << "Fecha de nacimiento: " << persona.dia << "/" << persona.mes << "/" << persona.ano << std::endl;
	return os;
}

bool Persona::operator <(Persona persona)
{
	if (apellidos == persona.getApellidos())
	{
		if (nombre > persona.nombre)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (apellidos > persona.getApellidos())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Persona::operator >(Persona persona)
{
	if (apellidos == persona.getApellidos())
	{
		if (nombre < persona.nombre)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (apellidos < persona.getApellidos())
	{
		return true;
	}
	else
	{
		return false;
	}
}

