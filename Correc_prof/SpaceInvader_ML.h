#pragma once

#include "MyType_ML.h"
namespace SpaceInvaderML
{
    /*!
    * \fn Colour
     * \param[in] Coul couleur du texte
     * \brief Fonction permettant de changer la couleur du texte.
     */
    void Colour (const std::string & Coul);

    /*!
     * \fn ClearScreen
     * \brief Fonction effa�ant le contenu de l'�cran
     */
    void ClearScreen ();

    /*!
     * \brief Descend l'envahisseur d'une ligne dans l'espace
     * \param [in, out] Space �tat de l'espace
     * \param [in] CurrentLine ligne sur laquelle se trouve l'e bellig�rant concern�'envahisseur.
     */
    void DownShift (CVString & Space, Size_t CurrentLine);

    /*!
     * \brief Renvoie vrai si le bellig�rant meurt.
     * \param [in] Space �tat de l'espace
     * \param [in] Line ligne sur laquelle se trouve le bellig�rant concern�.
     * \param [in] Column colonne sur laquelle se trouve le bellig�rant concern�.
     * \param [in, out] Who qui est concern�.
     */
    bool IsDead (const CVString & Space, Size_t Line, Size_t Column, char Who);

    /*!
     * \brief Simule le tir d'un bellig�rant. Renvoie vrai si le bellig�rant a gagn� (faux sinon).
     * \param [in, out] Space �tat de l'espace
     * \param [in] Line ligne sur laquelle se trouve le tireur.
     * \param [in] Middle colonne du tir.
     * \param [in] Projectile projectile �  lancer (torpille ou missile).
     * \param [in] Who qui tire.
     */
    bool Shoot (CVString & Space, Size_t Line, Size_t Middle,
                char Projectile, char Who);

    /*!
     * \brief Simule le jeu de l'envahisseur. C'est ici que l'envahisseur joue. En bout de ligne l'envahisseur descend d'une ligne et change de sens.
     * Il tire �galement une fois sur 2. Renvoie vrai si l'envahisseur a gagn� (faux sinon).
     * \param [in, out] Increment -1 ou 1 suivant que l'nvahisseur va �  gauche ou �  droite
     * \param [in, out] CurrentLine ligne sur laquelle se d�place l'envahisseur.
     * \param [in, out] Beg colonne o� est positionn� l'envahisseur.
     * \param [in, out] ToShoot indique si l'envahisseur doit tirer.
     * \param [in, out] Win indique si le joueur a gagn�.
     * \param [in, out] Space �tat de l'espace
     */
    bool ManageInvader (int & Increment, Size_t & CurrentLine,
                        Size_t & Beg, bool & ToShoot,
                        bool & Win, CVString & Space);

    /*!
    * \brief enl�ve de l'espace le bellig�rant qui a perdu.
    * \param [in, out] Space Espace de jeu
    * \param [in] Line indique la ligne sur laquelle se trouve le bellig�rant �  supprimer
    * \param [in] Column indique la colonne �  partir de laquelle il faut supprimer
    */
    void Remove (CVString & Space, Size_t Line, Size_t Column);

    /*!
     * \brief recalcule l'espace (d�placement des torpilles et des missiles) �  chaque fois qu'un bellig�rant a jou�.
     * \param [in, out] Space Espace de jeu
     * \param [in, out] Win  indique si le joueur a gagn�
     * \param [in, out] Lost  indique si le joueur a perdu
     */
    void RecomputeSpace (CVString & Space, bool & Win, bool & Lost);


    /*!
     * \brief Permet d'afficher l'espace de jeu.
     * \param [in] Space Espace de jeu
     */
    void DisplaySpace (const CVString & Space);

    /*!
     * \brief Simule le jeu du joueur. C'est ici que le joueur choisit ce qu'il fait. S'il d�cide de tirer, une tropille est lanc�e, d'une position au hasard,
     * au dessus d'une de ses positions. Renvoie vrai si le joueur a gagn� (faux sinon).
     * \param [in, out] Space Espace de jeu
     * \param [in, out] Pos   position du joueur sur sa ligne
     * \param [in, out] Lost  indique si le joueur a perdu
     */
    bool ManageMe (CVString & Space, Size_t & Pos, bool & Lost);

    /*!
     * \brief simule le jeux
     * <ol>
     *     <li>
     *         D�clare la grille de jeux
     *     </li>
     *     <li>
     *         L'initialise
     *     </li>
     *     <li>
     *         L'affiche
     *     </li>
     *     <li>
     *         boucle dont on sortira quand le joueur aura perdu ou gagn�
     *         <ul>
     *             <li>
     *                 joue pour le joueur
     *             </li>
     *             <li>
     *                 recalcule l'espace si le joueur n'a ni gagn� ni perdu
     *             </li>
     *             <li>
     *                 affiche l'espace
     *             </li>
     *             <li>
     *                 sort de la boucle en cas de victoire ou de d�faite
     *             </li>
     *             <li>
     *                 r�it�re ces 4 op�rations KRatioMeInvaders fois
     *             </li>
     *             <li>
     *                 sort de la boucle en cas de victoire ou de d�faite
     *             </li>
     *             <li>
     *                 joue pour l'e joueur'envahisseur
     *             </li>
     *             <li>
     *                 recalcule l'espace si l'e joueur'envahisseur n'a ni gagn� ni perdu
     *             </li>
     *             <li>
     *                 affiche l'espace
     *             </li>
     *             <li>
     *                 sort de la boucle en cas de victoire ou de d�faite
     *             </li>
     *         </ul>
     *     </li>
     *     <li>
     *         affiche le r�sultat
     *     </li>
     * </ol>
     */
    void SpaceInvaders (void);
}
