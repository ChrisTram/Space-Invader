#include "readconfig.h"
#include <string>
#include <map>
#include <fstream>

using namespace std;
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

namespace SpaceInvader
{
    const map<string, string> &LoadFile(const string &File, bool reload)
    {
        static map<string, map<string, string> > TabValue;
        if(!reload)
        {
            map<string, map<string, string> >::iterator value;
            if((value = TabValue.find(File)) !=TabValue.end())
                return value->second;
        }

        ifstream file(File);
        string Line;

        while (getline(file,Line))
        {
            // Position dans la ligne
            unsigned offset(0);
            // Cl�e dans la map
            string  Key;
            // Valeur de la cl�
            string  Value;
            // si la ligne est vide on lance une exception (l'exception est attraper par l'extracteur)
            if(Line.size() == 0)
                throw("can't read File : "+File);
            // on saute jusqu'au premier mots
            while (offset<Line.size() && Line[offset]==' ') ++offset;
            // on extrait le mots
            while (offset<Line.size() && Line[offset]!=' ') Key.push_back(Line[offset++]);
            // on saute jusqu'au :
            while (offset<Line.size() && Line[offset]==' ') ++offset;
            // si il n'est pas trouver on quite
            if(offset>=Line.size() || Line[offset++] != ':')
                continue;
            // on saute jusqu'au contenue des variable
            while (offset<Line.size() && Line[offset]==' ') ++offset;
            // on  extrait le 2�me mots
            while (offset<Line.size()) Value.push_back(Line[offset++]);
            // avectation de la valeur;
            TabValue[File][Key] = Value;
        }
        // on retourne la table courante
        return TabValue[File];
    }

    char GetValueChar(const string &Value, const string &File, const char &defaultValue)
    {
        // on essaye de r�cup�re la valeur attacher � Value
        try
        {
            // r�cup�re les constante stocker dans File
            const std::map<std::string, std::string> &ArrayVal = LoadFile(File);
            // r�cup�re la valeur de la cl�e
            std::map<std::string, std::string>::const_iterator val = ArrayVal.find(Value);
            // si elle n'existe pas ou est invalide on renvoie la valeur par d�faut
            if(val == ArrayVal.end() || val->second.size()==0)
                return defaultValue;
            // sinon on retourne la premier lettre stocker
            return val->second[0];
        }
        // si le fichier est introuvable ou n'importe quel erreur on renvoie la valeur par d�faut
        catch(...)
        {
            return defaultValue;
        }
    }

    string GetValueStr(const string &Value, const string &File, const string &defaultValue)
    {
        // on essaye de r�cup�re la valeur attacher � Value
        try
        {
            //  on charge le fichier en m�moire et on le stock
            const std::map<std::string, std::string> &ArrayVal = LoadFile(File);
            // on r�cup�re la valueur attacher � la cl�e
            std::map<std::string, std::string>::const_iterator val = ArrayVal.find(Value);
            // si elle n'existe pas
            if(val == ArrayVal.end() || val->second.size()==0)
                return defaultValue;
            //sinon on renvois la veuleur attacher � la variable
            return val->second;
        }
        // si le fichier est introuvable ou n'importe quel erreur on renvoie la valeur par d�faut
        catch(...)
        {
            return defaultValue;
        }

    }

    // fonction qui permet de verifier si le nombre est un non signer
    bool isUnsignedValue(const string &ValTest)
    {
        for(const char &Value : ValTest)
            if(!isdigit(Value))
                return false;
        return true;
    }

    // permet de traduire une chaine de caract�re en valeur num�rique
    unsigned AliasToValueInt(const string &Value)
    {
        // si la valeur est une couleur connue alors on renvois sa valeur num�rique
        if("KJaune" == Value)
            return KJaune;
        if("KNoir" == Value)
            return KNoir;
        if("KRouge" == Value)
            return KRouge;
        if("KVert" == Value)
            return KVert;
        if("KBleu" == Value)
            return KBleu;
        if("KMAgenta" == Value)
            return KMAgenta;
        if("KCyan" == Value)
            return KCyan;
        // sinon on ne peut pas g�r�
        throw(runtime_error("Cannot Find Alias"));
    }

    unsigned GetValueInt(const string &Value, const string &File, const unsigned &defaultValue)
    {
        // on essaye de r�cup�re la valeur attacher � Value
        try
        {
            //  on charge le fichier en m�moire et on le stock
            const std::map<std::string, std::string> &ArrayVal = LoadFile(File);
            // on r�cup�re la valeur attacher � Value
            std::map<std::string, std::string>::const_iterator val = ArrayVal.find(Value);
            // si elle n'existe pas
            if(val == ArrayVal.end() || val->second.size()==0)
                return defaultValue;
            // si c'est une valeur non sign� on l'extrait
            else if(isUnsignedValue(val->second))
                return atoi(val->second.data());
            // sinon on essait de traduire le supposer alias contenue
            return AliasToValueInt(val->second);
        }
        // si le fichier n'existe pas ou l'alias n'est pas traduisible on retourne la valeur par d�faut
        catch(...)
        {
            return defaultValue;
        }
    }
}
