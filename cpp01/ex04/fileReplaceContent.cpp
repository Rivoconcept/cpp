/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplaceContent.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 19:41:38 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileReplaceContent.hpp"

ReplaceContent::ReplaceContent(const std::string& s1, const std::string& s2) \
    : _s1(s1), _s2(s2) {}

ReplaceContent::~ReplaceContent() {}

const std::string& ReplaceContent::getS1() const
{
    return (this->_s1);
}

const std::string& ReplaceContent::getS2() const
{
    return (this->_s2);
}

void ReplaceContent::replaceFileContent(const GetFileContents& contents, \
	const std::string& filename)
{
    std::ofstream ofs(filename + ".replace");

    if (!ofs)
    {
        throw std::runtime_error("Error: cannot create output file '" + filename + ".replace'");
    }

    const std::vector<std::string>& lines = contents.getFileContents();
    
    for (const std::string& line : lines)
    {
        std::string modifiedLine = line;
        size_t pos = 0;

        while ((pos = modifiedLine.find(_s1, pos)) != std::string::npos)
        {
            modifiedLine.replace(pos, _s1.length(), _s2);
            pos += _s2.length();
        }

        ofs << modifiedLine << '\n';
    }

    ofs.close();
}

