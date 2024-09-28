/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:56:08 by jeguerin          #+#    #+#             */
/*   Updated: 2024/09/26 19:08:13 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/*
std::ifstream : pour lire depuis un fichier (input).
std::ofstream : pour écrire dans un fichier (output).
std::fstream : pour lire et écrire dans un fichier (input/output).
*/
// Add if s1 or s2 empty !

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cout << "Number of arguments is wrong, please add : a filename, s1, s2" << std::endl;
        return 1;
    }
    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream   inputFile(argv[1]);
    if(!inputFile.is_open())
    {
        std::cerr << "Error while trying to read the file: " << argv[1] << std::endl;
        return 1;
    }
    file.append(".replace");
    std::ofstream   outputFile(file.c_str());
    if (!outputFile.is_open()){
        std::cerr << "error while opening file" << std::endl; 
        return 1;
    }
    std::string line;
    while(std::getline(inputFile, line))
    {
        std::size_t j = 0;
        while ((j = line.find(s1, j)) != std::string::npos) // To find an occurance.
        {
           line.erase(j, s1.length()); // We delete the occurence of s1
           line.insert(j, s2); // We add (at previous s1 index) s2 occurence.
           j+= s2.length(); // We update our index to check next occurence, if there is one.
        }
        outputFile << line << std::endl;
 
    }
    inputFile.close();
    outputFile.close();
    return 0;
}

/*
OFSTREAM :
S'attend à recevoir un tableau de caractères (un pointeur de type char* ou 
const char*) au lieu d'un objet std::string.
Pourquoi file.c_str() fonctionne :
- Conversion en C-string :
    > La méthode c_str() de std::string retourne un pointeur de type const char* 
    qui représente la chaîne sous forme de tableau de caractères (C-string).
    > Cela permet à d'autres parties de ton programme, qui peuvent ne pas 
    savoir comment travailler avec std::string, d'accéder à la chaîne sous une 
    forme compatible.
*/


// int main(int argc, char **argv)
// {
//     if (argc != 4)
//         std::cout << "Number of arguments is wrong, please add : a filename, s1, s2" << std::endl;
//     std::string s1 = argv[2];
//     std::string s2 = argv[3];
//     // std::string file = argv[1];
//     std::ifstream   inputFile(argv[1]);
//     if(!inputFile.is_open())
//     {
//         std::cerr << "Error while trying to read the file: " << argv[1] << std::endl;
//         return 1;
//     }
//     // file += ".replace";
//     std::ofstream   outputFile("ouutpuut.replace");
//     if (!outputFile.is_open()){
//         std::cerr << "error while opening file" << std::endl; 
//         return 1;
//     }
//     std::string line;
//     while(std::getline(inputFile, line))
//     {
//         std::string new_line;
//         std::size_t j = 0;
//         while ((j = line.find(s1, j)) != std::string::npos)
//         {
//             new_line.append(line.substr(0, j)); // Extraire la sous-chaîne de N à N puis la mettre dans new_line.
//             new_line.append(s2); // Pour concatainer une chaîne
//             j += s1.length();
//             // line.append(line + j);
//         }
//         new_line.append(line.substr(j)); // Add le reste la ligne après la last occurence.
//         outputFile << new_line << std::endl;
       
//     }
//     inputFile.close();
//     outputFile.close();
//     return 0;
// }

