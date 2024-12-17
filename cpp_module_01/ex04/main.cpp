/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:02:53 by rufus             #+#    #+#             */
/*   Updated: 2024/12/17 17:56:10 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Program takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.*/

#include <iostream>
#include <fstream> // For file handling
#include <string>  // For std::string

std::string myReplace(const std::string &line, size_t pos, size_t s1_length, const std::string &s2)
{
    // Build a new string:
    // - Part before the position
    // - Replacement string
    // - Part after the replaced segment
    return line.substr(0, pos) + s2 + line.substr(pos + s1_length);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1]; // The input file
    std::string s1 = argv[2];       // String to be replaced
    std::string s2 = argv[3];       // Replacement string

    // Open input file for reading
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << " for reading." << std::endl;
        return 1;
    }

    // Create output file with <filename>.replace
    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create output file " << filename << ".replace" << std::endl;
        inputFile.close();
        return 1;
    }

    // Read file content line by line (example placeholder for next steps)
    std::string line;
    size_t replacements = 0;
    while (std::getline(inputFile, line))
    {
        // Process line here: replace occurrences of s1 with s2, .replace is forbidden
        size_t pos = 0;
        
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            // cannot use this line.replace(pos, s1.length(), s2); replace forbidden
            line = myReplace(line, pos, s1.length(), s2);
            replacements++;
            
            pos += s2.length();
        }
        outputFile << line << std::endl; // Placeholder: Write the line as-is
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    std::cout << "File processing completed successfully!" << std::endl;
    std::cout << replacements << " replacements made." << std::endl;
    return 0;
}
