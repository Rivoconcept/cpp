/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplaceContent.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/22 17:26:24 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileReplaceContent.hpp"

ReplaceContent::ReplaceContent(std::string s1, std::string s2, GetFileContents& contents)
    : _s1(s1.c_str()), _s2(s2.c_str()), _contents(contents) {}

ReplaceContent::~ReplaceContent() {}

void ReplaceContent::replaceFileContent()
{
    std::ofstream ofs((_contents.getFileName() + ".replace").c_str());

    if (!ofs)
    {
        throw std::runtime_error("Error: cannot create output file '" + _contents.getFileName() + ".replace'");
    }

    const std::string& lines = _contents.getFileContents();
    
    std::string modified_contents;
    size_t pos = 0, last_pos = 0;

    while ((pos = lines.find(_s1, last_pos)) != std::string::npos)
    {
        for (size_t i = last_pos; i < pos; ++i)
            modified_contents += lines[i];
        modified_contents += _s2;
        last_pos = pos + _s1.length();
    }
    for (size_t i = last_pos; i < lines.size(); ++i) {
        modified_contents += lines[i];
    }
    ofs << modified_contents;
    ofs.close();
}



