#pragma once

/*!
  * \file SpaceInvader_AC.h
  * \author Alain Casali Marc Laporte
  * \date 7 janvier 2016
  * \brief Fichier d�crivant l'ensemble des signatures vers les fonctions utilis�es dans le jeu
  * \version 1.0
  * \bug Aucun connu
  */

#include "MyType_AC.h"
namespace SpaceInvader_AC
{
    /*!
    * \fn Couleur
     * \param[in] Coul couleur du texte
     * \brief Fonction permettant de changer la couleur du texte.
     */
    void Couleur (const std::string & Coul);

    /*!
     * \fn ClearScreen
     * \brief Fonction effa�ant le contenu de l'�cran
     */
    void ClearScreen ();

    /*!
     * \fn void PutCVPosition (const CVPosition & VPos, char Car, CVString & Space)
     * \brief Permet d'ins�rer le carcact�re pass� en second param�tre �  toutes les positions souhait�es (1er param�tre) de l'espace de jeu (3�me param�tre).
     * \param[in] VPos Vecteur de CPosition
     * \param[in] Car Caract�re �  ins�rer dans l'esapce
     * \param\[in, out] Space Espace de jeu
     */
    void PutCVPosition (const CVPosition & VPos, char Car, CVString & Space);

    /*!
     * \brief Vide l'espace de jeu, puis ins�re tous les objets du jeu.
     * \param Obj [in] Liste des objets �  ins�rer
     * \param Space [in, out] Espace de jeu
     */
    void PutAllObjects (const CAObject & Obj, CVString & Space);

    /*!
     * \brief Permet d'afficher l'espace de jeu.
     * \param [in] Space Espace de jeu
     */
    void DisplaySpace (const CVString & Space);

    /*!
     * \brief Permet d'initialiser l'espace de jeu et de d�finir les coordonn�es des objets �  placer au lancement du jeu.
     * \param Space [out] Espace de jeu
     * \param Obj [ou] Liste des objets �  placer au d�but du jeu
     */
    void InitSpace (CVString & Space, CAObject & Obj);

    /*!
     * \brief Trouve le maximum d'un vecteur de CPosition de la coordon�es en X (abscisse).
     * \param VPos [in] Vecteur de CPosition
     * \param MaxPos [out] Valeur maximale pour X
     */
    void MaxX (const CVPosition & VPos, CPosition & MaxPos);

    /*!
     * \brief Trouve le maximum d'un vecteur de CPosition de la coordon�es en Y (ordonn�e).
     * \param VPos [in] Vecteur de CPosition
     * \param MaxPos [out] Valeur maximale pour Y
     */
    void MaxY (const CVPosition & VPos, CPosition & MaxPos);

    /*!
     * \brief Trouve le minimum d'un vecteur de CPosition de la coordon�es en X (abscisse).
     * \param VPos [in] Vecteur de CPosition
     * \param MinPos [out] Valeur minimale pour X
     */
    void MinX (const CVPosition & VPos, CPosition & MinPos);

    /*!
     * \brief Simule un d�placement gauche en retranchant une unit� de d�placement �  toutes les abscisses des objets en param�tre.
     * \param VPos [in, out] Vecteur de CPosition
     * \return Vrai si la plus petite des abscisses ne vaut pas 0, faux sinon
     */
    bool MoveLeft (CVPosition & VPos);

    /*!
     * \brief Simule un d�placement droit en ajoutant une unit� de d�placement �  toutes les abscisses des objets en param�tre.
     * \param Space [in] Espace de jeu
     * \param VPos [in, out] Vecteur de CPosition
     * \return Vrai si la plus grande des abscisses ne vaut pas n'est pas sur la derni�re case de l'espace de jeu, faux sinon
     */
    bool MoveRight (const CVString & Space, CVPosition & VPos);

    /*!
     * \brief Simule un d�placement bas en ajoutant une unit� de d�placement �  toutes les ordonn�es des objets en param�tre.
     * \param VPos [in, out] Vecteur de CPosition
     */
    void MoveDown (CVPosition & VPos);

    /*!
     * \brief Simule un d�placement haut en ajoutant une unit� de d�placement �  toutes les ordonn�es des objets en param�tre.
     * \param VPos [in, out] Vecteur de CPosition
     */
    void MoveUp (CVPosition & VPos);

    /*!
     * \brief Simule le jeu du joueur. C'est ici que le joueur choisit ce qu'il fait. S'il d�cide de tirer, une tropille est lanc�e, d'une position au hasard, au dessus d'une de ses positions.
     * \param Space [in] Espace de jeu
     * \param Obj [in, out] Liste des objets du jeu
     */
    void ManageMe (const CVString & Space, CAObject &Obj);

    /*!
     * \brief ManageInvaders Simule le jeu de l'envahisseur.
     * \param Space [in] Espace de jeu
     * \param Obj [in, out] Liste des objets du jeu
     * \param Direction [in, out] Sens de d�placement de l'envahisseur
     * \param WhatInvaderDo [in, out] Ce que doit faire l'envahisseur (se d�placer ou lancer un missile, d'une position au hasard, au dessous d'une de ses positions).
     */
    void ManageInvaders (const CVString & Space, CAObject &Obj, unsigned & Direction, unsigned & WhatInvaderDo);

    /*!
     * \brief G�re les collisions entre les objets et les vaisseaux. Si une collision est d�t�ct�e (m�me coordon�es pour un objet et une partie d'un vaisseau), l'objet et la partie du vaisseau diparaissent
     * \param Objects [in, out] Vecteur des positions des objects �  traiter
     * \param StarShips [in, out] Vecteur des positions des vaisseaux �  traiter
     */
    void CollisionBetweenObjectsAndShips (CVPosition & Objects, CVPosition & StarShips);

    /*!
     * \brief G�re les collisions (multiples) entre les missiles et les tropilles
     * \param Missiles [in, out] Vecteur des positions des missiles
     * \param Torpedos [in, out] Vecteur des positions des torpilles
     */
    void CollisionBetweenMissilesAndTorpedos (CVPosition & Missiles, CVPosition & Torpedos);

    /*!
     * \brief G�re toutes les collisions du jeu
     * \param [in, out] Obj Liste des objets du jeu
     */
    void ManageCollisions (CAObject & Obj);

    /*!
     * \brief Teste si l'envahisseur ou si le joueur ont gagn�.
     * \param Space [in] Espace de jeu
     * \param Obj [in] Liste des objets du jeu
     * \return 0 si ni l'envahisseur ou le joueur ont gagn�, 1 si c'est l'envahiseur et 2 si c'est le joueur
     */
    unsigned Victory (const CVString & Space, const CAObject & Obj);

    /*!
     * \brief Supprime les missiles qui sortent de l'espace de jeu.
     * \param [in] Space Espace de jeu
     * \param Missiles [in, out] Vecteur des positions des missiles
     */
    void DeleteMissiles (const CVString & Space, CVPosition & Missiles);

    /*!
     * \brief Supprime les tropilles qui sortent de l'espace de jeu.
     * \param Torpedos [in, out] Vecteur des positions des torpilles
     */
    void DeleteTorpedos (CVPosition & Torpedos);

    /*!
     * \brief Fonction principale du jeu sans option.
     */
    unsigned SpaceInvaders (void);

    /*!
     * \fn void ShowFile (const string & FileName)
     * \brief Permet d'afficher le contenu d'un fichier �  l'�cran.
     * \param FileName [in] Chemin vers le fichier �  afficher
     */
    void ShowFile (const std::string & FileName);

    /*!
     * \fn void set_input_mode (void)
     * \brief Permet d'activer la saisie �  la vol�e. Utile pour g�rer les d�placement du joueur sans appuyer sur la touche entr�e.
     * si le joueur ne joue pas pendant 3 10�me de seconde, alors il pert une action. <br><br>
     * voir : http://www.gnu.org/software/libc/manual/html_node/Noncanon-Example.html et http://man7.org/linux/man-pages/man3/termios.3.html
     */
    void set_input_mode (void);

    /*!
     * \fn int ppal()
     * \brief Fonction principale du jeu.
     * <ol>
     *  <li> Initilalise la graine du g�n�rateur al�atoire,
     *  <li> active la saisie �  la vol�e,
     *  <li> lance le jeu et
     *  <li> affiche le r�sultat
     * </ol>
     */
    int ppal (const std::string & Path);

}//namespace
