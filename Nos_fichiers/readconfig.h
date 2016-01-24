#pragma once
#include <string>
#include <map>
namespace SpaceInvader
{
    /**
     * @brief GetValueChar
     * Fonction qui permet de r�cup�rer un charact�re � partir d'un fichier yaml
     * @param Value
     * Nom de La variable contenant la valeur � extraire
     * @param File
     * Nom du ficher yaml contenant les imformations supos�es
     * @param defaultValue
     * Valeur par-d�faut en cas d'�chec de lecture
     * @return
     * valeur contenu dans la variable
     */
    char GetValueChar(const std::string &Value, const std::string &File, const char &defaultValue);

    /**
     * @brief GetValueStr
     * Fonction qui r�cup�re le contenue d'une variable dans un fichier yaml
     * @param Value
     * Nom de la variable
     * @param File
     * Nom du Fichier YAML
     * @param defaultValue
     * Valeur par-d�faut en cas d'inexistance de la variable
     * @return
     * Valeur de la variable
     */
    std::string GetValueStr(const std::string &Value, const std::string &File, const std::string &defaultValue);

    /**
     * @brief GetValueInt
     * Fonction qui permet de recuperer une valeur num�rique non sign�e � partir d'un fichier yaml
     * @param Value
     * nom de la variable
     * @param File
     * nom du fichier de configuration
     * @param defaultValue
     * Valeur par-d�faut en cas d'echec d'extraction
     */
    unsigned GetValueInt(const std::string &Value, const std::string &File, const unsigned &defaultValue);

    /**
     * @brief LoadFile
     * Fonction de lecture partielle de fichier yaml
     * @param File
     * Fichier au format yaml � lire
     * @param reload
     * Les donn�es d�j� en m�moire seront recharg�es si vrai
     * @return
     * Renvoie les donn�s de configuration
     */
    const std::map<std::string, std::string> &LoadFile(const std::string &File, bool reload = false);
}
