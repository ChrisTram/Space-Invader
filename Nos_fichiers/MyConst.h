#pragma once

/*!
  * \file MyConst_AC.h
  * \author Alain Casali Marc Laporte
  * \date 7 janvier 2016
  * \brief Fichier d�crivant l'ensemble des constantes utilis�es dans le jeu
  * \version 1.0
  * \bug Aucun connu
  */

#include "MyType.h"
#include "readconfig.h"

namespace SpaceInvader
{
    //Constantes de couleur
    /*!
     * \brief Alias remetant la couleur du texte du terminal �  sa valeur par défaut.
     */
    const std::string KReset   ="\033[0m";

    /*!
     * \brief Alias mettant en noir la couleur du texte du terminal.
     */
    const unsigned KNoir    = 0;
    /*!
     * \brief Alias mettant en rouge la couleur du texte du terminal.
     */
    const unsigned KRouge   = 1;

    /*!
     * \brief Alias mettant en vert la couleur du texte du terminal.
     */
    const unsigned KVert    = 2;

    /*!
     * \brief Alias mettant en jaune la couleur du texte du terminal.
     */
    const unsigned KJaune   = 3;

    /*!
     * \brief Alias mettant en bleu la couleur du texte du terminal.
     */
    const unsigned KBleu    = 4;

    /*!
     * \brief Alias mettant en mangenta la couleur du texte du terminal.
     */
    const unsigned KMAgenta = 5;

    /*!
     * \brief Alias mettant en cyan la couleur du texte du terminal.
     */
    const unsigned KCyan    = 6;

    // Constantes pour les touches
    /*!
     * \brief Alias vers la touche servant �  se déplacer �  droite.
     */
    const char KRight               = GetValueChar("KRight", "config.yaml", 'x');  // déplacement vers la droite

    /*!
     * \brief Alias vers la touche servant �  se déplacer �  gauche.
     */
    const char KLeft                = GetValueChar("KLeft", "config.yaml", 'w');  // Déplacement vers la gauche

    /*!
     * \brief Alias vers la touche servant �  lancer une torpille.
     */
    const char KShoot               = GetValueChar("KShoot", "config.yaml", ' ');  // Lancer de torpille

    //  Constantes liées �  l'envahisseur
    /*!
     * \brief Couleur de l'envahisseur.
     */
    const unsigned KInvadersColor = GetValueInt("KInvadersColor", "config.yaml", KJaune);  // Couleur de l'envahisseur

    /*!
     * \brief Caractèrere formant l'envahisseur.
     */
    const char KInsideInvader       = GetValueChar("KInsideInvader", "config.yaml", 'W');  // caract�rere formant l'envahisseur

    /*!
     * \brief Caractèrere formant le missile.
     */
    const char KMissile             = GetValueChar("KMissile", "config.yaml", 'T');  // missile

    const unsigned KFireWait    =  GetValueInt("KFireWait","config.yaml", 4);   // nombre de caract�res qui forment l'envahisseur

    /*!
     * \brief Nombre de caractères qui forment l'envahisseur.
     */
    const unsigned KInvadersSize    =  GetValueInt("KInvadersSize","config.yaml", 5);   // nombre de caract�res qui forment l'envahisseur

    /*!
     * \brief Nombre de fois o� l'envahisseur tire un missile par rapport �  son d�placement.
     */
    const unsigned KMissileRatio =  GetValueInt("KMissileRatio","config.yaml", 2); // nombre de fois o� l'envahisseur tire un missile par rapport �  son d�placement

    // Constantes liées au joueur
    /*!
     * \brief Couleur liée �  mes objets (vaisseaux et tropilles).
     */
    const unsigned KMyColor = GetValueInt("KMyColor", "config.yaml", KVert); // Ma couleur

    /*!
     * \brief Caractèrere formant mon vaisseau.
     */
    const char KInsideMe            = GetValueChar("KInsideMe", "config.yaml", 'A'); // caract�rere formant mon vaisseau

    /*!
     * \brief Caractèrere formant ma torpille.
     */
    const char KTorpedo             = GetValueChar("KTorpedo", "config.yaml", '|'); // caract�rere formant ma torpille

    /*!
     * \brief Nombre de caractères qui forment mon vaisseau.
     */
    const unsigned KMyLife          =  GetValueInt("KMySize","config.yaml", 4); //  nombre de caract�res qui forment mon vaisseau


    /*!
     * \brief Nombre de fois où c'est le tour du joueur pour un tour de l'envahisseur.
     */
    const unsigned KRatioMeInvaders =  GetValueInt("KRatioMeInvaders","config.yaml", 4);    // Nombre de fois o� c'est le tour du joueur pour un tour de l'envahisseur


    // Constantes liées �  l'eapace (l'écran)
    /*!
     * \brief Alias vers une case vide �  l'écran.
     */
    const char KEmpty               =  GetValueChar("KEmpty","config.yaml", ' ');  // case vide de l'�cran
    /*!
     * \brief Nombre de lignes de l'écran (de l'espace).
     */
    const unsigned KSizeLine   =  GetValueInt("KSizeLine","config.yaml", 10);   // Nombre de lignes de l'�cran (de l'espace)

    /*!
     * \brief Nombre de colonnes de l'écran (de l'espace).
     */
    const unsigned KSizeSpace  =  GetValueInt("KSizeSpace","config.yaml", 10);   // Nombre de colonnes de l'�cran (de l'espace)

    /*!
     * \brief Numéro de colonne où commence l'envahisseur.
     */
    const unsigned KBegInvader =  GetValueInt("KBegInvader","config.yaml", 0);    // Numéro de colonne o� commence l'envahisseur

    /*!
     * \brief Numéro de colonne où commence le joueur.
     */
    const unsigned KBegMe      =  GetValueInt("KBegMe","config.yaml", 5);  // Numéro de colonne o� commence le joueur

    const char KBonus = GetValueChar("KBonus","config.yaml", '*')!=KEmpty ? GetValueChar("KBonus","config.yaml", '*') : '*';
}//namespace
