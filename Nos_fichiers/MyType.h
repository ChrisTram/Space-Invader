#pragma once

/*!
  * \file MyType_AC.h
  * \author Alain Casali Marc Laporte
  * \date 7 janvier 2016
  * \brief Fichier d�crivant l'ensemble des alias vers les types utilis�s dans le jeu
  * \version 1.0
  * \bug Aucun connu
  */


#include <vector>
#include <utility> //pair
#include <array> //array
#include <map>

namespace SpaceInvader
{
    /*!
     * \typedef CVString
     * \brief   Alias vers le type de l'�cran (l'espace, la matrice, le saint graal).
     */
    typedef std::vector <std::string> CVString;    // c'est le type de l'�cran (l'espace, la matrice, @le saint graal)
}//namesapce
