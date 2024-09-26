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

/*
std::ifstream : pour lire depuis un fichier (input).
std::ofstream : pour écrire dans un fichier (output).
std::fstream : pour lire et écrire dans un fichier (input/output).
*/

int main(int argc, char **argv)
{
    if (argc != 4)
        std::cout << "Number of arguments is wrong, please add : a filename, s1, s2" << std::endl;
    std::ifstream   inputFile(argv[1]);
    if(!inputFile)
    {
        std::cerr << "Error while trying to read the file: " << argv[1] << std::endl;
        return 1;
    }
    std::string line;

    while(std::getline(inputFile, line))
    {
        // To continue;
    }
    
    return 0;
}