/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:55 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 22:38:27 by rhanitra         ###   ########.fr       */
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
        GetFileContents contents = GetFileContents(argv[1]);
        contents.setFileContents();
        ReplaceContent replace = ReplaceContent(argv[2], argv[3], contents);
        replace.replaceFileContent();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

