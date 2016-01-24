#pragma once

/*!
  * \file MyConst_AC.h
  * \author Alain Casali Marc Laporte
  * \date 7 janvier 2016
  * \brief Fichier d�crivant l'ensemble des constantes utilis�es dans le jeu
  * \version 1.0
  * \bug Aucun connu
  */

#include "MyType_AC.h"

namespace SpaceInvader_AC
{
    //Constantes de couleur
    /*!
     * \brief Alias remetant la couleur du texte du terminal �  sa valeur par d�faut.
     */
    const std::string KReset   ("0");

    /*!
     * \brief Alias mettant en noir la couleur du texte du terminal.
     */
    const std::string KNoir    ("30");
    /*!
     * \brief Alias mettant en rouge la couleur du texte du terminal.
     */
    const std::string KRouge   ("31");

    /*!
     * \brief Alias mettant en vert la couleur du texte du terminal.
     */
    const std::string KVert    ("32");

    /*!
     * \brief Alias mettant en jaune la couleur du texte du terminal.
     */
    const std::string KJaune   ("33");

    /*!
     * \brief Alias mettant en bleu la couleur du texte du terminal.
     */
    const std::string KBleu    ("34");

    /*!
     * \brief Alias mettant en mangenta la couleur du texte du terminal.
     */
    const std::string KMAgenta ("35");

    /*!
     * \brief Alias mettant en cyan la couleur du texte du terminal.
     */
    const std::string KCyan    ("36");

    // Constantes pour les touches
    /*!
     * \brief Alias vers la touche servant �  se d�placer �  droite.
     */
    const char KRight               = 'x';  // d�placement vers la droite

    /*!
     * \brief Alias vers la touche servant �  se d�placer �  gauche.
     */
    const char KLeft                = 'w';  // D�placement vers la gauche

    /*!
     * \brief Alias vers la touche servant �  lancer une torpille.
     */
    const char KShoot               = ' ';  // Lancer de torpille

    //  Constantes li�es �  l'envahisseur
    /*!
     * \brief Couleur de l'envahisseur.
     */
    const std::string KInvadersColor (KJaune);  // Couleur de l'envahisseur

    /*!
     * \brief Caract�rere formant l'envahisseur.
     */
    const char KInsideInvader       = 'W';  // caract�rere formant l'envahisseur

    /*!
     * \brief Caract�rere formant le missile.
     */
    const char KMissile             = 'T';  // missile

    /*!
     * \brief Nombre de caract�res qui forment l'envahisseur.
     */
    const unsigned KInvadersSize    =  5;   // nombre de caract�res qui forment l'envahisseur

    /*!
     * \brief Nombre de fois o� l'envahisseur tire un missile par rapport �  son d�placement.
     */
    const unsigned KMissileRatio = 2; // nombre de fois o� l'envahisseur tire un missile par rapport �  son d�placement

    // Constantes li�es au joueur
    /*!
     * \brief Couleur li�e �  mes objets (vaisseaux et tropilles).
     */
    const std::string KMyColor (KVert); // Ma couleur

    /*!
     * \brief Caract�rere formant mon vaisseau.
     */
    const char KInsideMe            = 'A'; // caract�rere formant mon vaisseau

    /*!
     * \brief Caract�rere formant ma torpille.
     */
    const char KTorpedo             = '|'; // caract�rere formant ma torpille

    /*!
     * \brief Nombre de caract�res qui forment mon vaisseau.
     */
    const unsigned KMySize          = 4; //  nombre de caract�res qui forment mon vaisseau


    /*!
     * \brief Nombre de fois o� c'est le tour du joueur pour un tour de l'envahisseur.
     */
    const unsigned KRatioMeInvaders = 4;    // Nombre de fois o� c'est le tour du joueur pour un tour de l'envahisseur


    // Constantes li�es �  l'eapace (l'�cran)
    /*!
     * \brief Alias vers une case vide �  l'�cran.
     */
    const char KEmpty               = ' ';  // case vide de l'�cran
    /*!
     * \brief Nombre de lignes de l'�cran (de l'espace).
     */
    const unsigned KSizeLine   = 10;   // Nombre de lignes de l'�cran (de l'espace)

    /*!
     * \brief Nombre de colonnes de l'�cran (de l'espace).
     */
    const unsigned KSizeSpace  = 10;   // Nombre de colonnes de l'�cran (de l'espace)

    /*!
     * \brief Num�ro de colonne o� commence l'envahisseur.
     */
    const unsigned KBegInvader = 0;    // Num�ro de colonne o� commence l'envahisseur

    /*!
     * \brief Num�ro de colonne o� commence le joueur.
     */
    const unsigned KBegMe      = KSizeLine / 2;  // Num�ro de colonne o� commence le joueur

    /*!
     * \brief Alias vers une ligne vide de l'esapce.
     */
    const std::string KEmptyLine (KSizeLine, KEmpty);  // Une ligne vide de la matrice
}//namespace
