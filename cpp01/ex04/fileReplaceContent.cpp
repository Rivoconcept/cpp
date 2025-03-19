/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplaceContent.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 22:41:11 by rhanitra         ###   ########.fr       */
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

    std::vector<std::string> lines = _contents.getFileContents();
    
    for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); ++it) {
        size_t pos = 0;
        while ((pos = it->find(_s1, pos)) != std::string::npos) {
            it->erase(pos, _s1.length());
            it->insert(pos, _s2);
            pos += _s2.length();
        }
        ofs << *it << std::endl;
    }
    ofs.close();
}

