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

namespace SpaceInvader_AC
{
    /*!
     * \typedef CVString
     * \brief   Alias vers le type de l'�cran (l'espace, la matrice).
     */
    typedef std::vector <std::string> CVString;    // c'est le type de l'�cran (l'espace, la matrice)


    /*!
     * \typedef CPosition
     * \brief Alias vers une coordonn�e de la matrice. Le premier �l�ment de la paire d�signe une ordonn�e (axe Y),
     *          le second une abscisse (axe X).
     */
    typedef std::pair <unsigned, unsigned> CPosition; //une coordonnee de la matrice

    /*!
     * \typedef CVPosition
     * \brief Alias vers un vecteur de coordonnees.
     */
    typedef std::vector<CPosition> CVPosition; //un vecteur de coordonnees

    /*!
     * \typedef CAObject
     * \brief Alias vers un tableau de 4 vecteurs de coordonnees.
     * <ul>
     *  <li>indice 0 : les positions de l'envahisseur
     *  <li>indice 1 : les positions des missiles
     *  <li>indice 2 : les positions de mon vaisseau
     *  <li>indice 3 : les positions de mes torpilles
     * </ul>
     */
    //un tableau de 4 vecteurs de coordonnees
    //indice 0 : les positions de l'envahisseur
    //indice 1 : les positions des missiles
    //indice 2 : les posotions de mon vaisseau
    //indice 3 : les positions de mes torpilles
    typedef std::array <CVPosition, 4> CAObject;
}//namesapce
