/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFileContents.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:56:11 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/19 19:45:02 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getFileContents.hpp"

GetFileContents::GetFileContents(const std::string& filename) : _filename(filename) {}

GetFileContents::~GetFileContents() {}

const std::string& GetFileContents::getFileName() const
{
    return (this->_filename);
}

const std::vector<std::string>& GetFileContents::getFileContents() const
{
    return (this->_lines);
}

void GetFileContents::setFileContents()
{
    std::ifstream ifs(_filename);

    if (!ifs)
    {
        throw std::runtime_error("Error: cannot open file '" + _filename + "'");
    }

    std::string line;
    while (std::getline(ifs, line))
    {
        this->_lines.push_back(line);
    }
    ifs.close();
}