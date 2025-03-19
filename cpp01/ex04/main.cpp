/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:55 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 19:44:26 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getFileContents.hpp"
#include "fileReplaceContent.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return EXIT_FAILURE;
    }

    try
    {
        std::string temp = argv[1];
        std::string filename = temp.c_str();
        GetFileContents fileContents(filename);
        fileContents.setFileContents(filename);

        ReplaceContent replacer(argv[2], argv[3]);
        replacer.replaceFileContent(fileContents, filename.c_str());
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/*int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Use right parameter: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream ifs(filename.c_str());
    if (!ifs) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return (1);
    }

    std::string line;
    std::vector<std::string> lines;

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty!" << std::endl;
        return (1);
    }

    while (std::getline(ifs, line))
    {
        lines.push_back(line);
    }
    ifs.close();

    std::ofstream ofs((filename + ".replace").c_str());
    if (!ofs) {
        std::cerr << "Error: cannot create output file" << std::endl;
        return (1);
    }
    for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); ++it) {
        size_t pos = 0;
        while ((pos = it->find(s1, pos)) != std::string::npos) {
            it->erase(pos, s1.length());
            it->insert(pos, s2);
            pos += s2.length();
        }
        ofs << *it << std::endl;
    }
    ofs.close();
    return 0;
}*/
