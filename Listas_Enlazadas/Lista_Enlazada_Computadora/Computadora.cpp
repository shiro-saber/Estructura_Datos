#include "Computadora.h"

namespace vcn 
{    
    std::ostream & operator <<(std::ostream & os, vcn::Computadora & c)
    {
        os << "Display : " << c.pantalla << " pixeles"<< std::endl;
        os << "RAM     : " << c.ram << " GB" << std::endl;
        os << "CPU     : " << c.frecuencia << " GHz" << std::endl;
    
        return os;
    }
}